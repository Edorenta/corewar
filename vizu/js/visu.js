"use strict";

//interface colors tracker
var clrs = {
    blue : "rgb(0,110,255)",   //blue
    green : "rgb(15,185,0)",   //green
    red : "rgb(230,0,0)",      //red
    purple : "rgb(230,0,230)", //purple
    yellow : "rgb(250,250,0)", //yellow
    grey : "rgb(80,80,80)",  //grey
    white : "rgb(255,255,255)",
    dark_grey : "rgb(45,45,45)",
    light_grey : "rgb(255,240,220)",
    theme : "rgb(200,200,200)"
};

var dark_mode = true;
var text_mode = true;
var block_mode = true;
var text_mode_bold = false;
var arena_block_clr = clrs.grey;
var player_clrs = [
    ShadeBlend(-0.18, clrs.blue),
    ShadeBlend(-0.18, clrs.red),
    ShadeBlend(-0.18, clrs.green),
    ShadeBlend(-0.18, clrs.purple),
    ShadeBlend(-0.18, clrs.yellow)];
var arena_block_shape =
    ['triangle', 0];
var player_shapes = [
    ['square', 4],
    ['square', 4],
    ['square', 4],
    ['square', 4],
    ['square', 4]];
var uri = "127.0.0.1";
var port = "8082";
var address = "ws://" + uri + ":" + port;
var ws;

//global variables
var title;
var canvas;
var mem_div;
var cmd_div;
var dark_ui;
var light_ui;
var theme_ui;
var back_clr = clrs.dark_grey;
var joystix_font;
var str;
var trim;
var fontsize;
var start_x = 557;
var start_y = 35;
var itx = 0;
var ity = 0;
var space_x = 20.7;
var space_y = 14.4;
var countdown = 0;

//core GET variables
var procs = [];
var block = [];
var player = [];

var in_set = [];
var in_cyc = [];
var in_exe = [];
var in_liv = [];
var in_hex;
var in_map;
var last_alive;

//min max of array as .this function
Array.prototype.max = function(){
    return Math.max.apply(null, this);
};

Array.prototype.min = function(){
    return Math.min.apply(null, this);
};

String.prototype.rpl = function(from, to) {
    let target = this;
    return target.replace(new RegExp(from, 'g'), to);
};

//canvas resize on viewport change
function canvas_resize(){
    win.w = Math.max(document.documentElement.clientWidth, window.innerWidth || 0);
    win.h = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);
    resizeCanvas(win.w, win.h, true);
}
//viewport size tracker
var win = {
    w : Math.max(document.documentElement.clientWidth, window.innerWidth || 0),
    h : Math.max(document.documentElement.clientHeight, window.innerHeight || 0),
};

class Block{
    constructor(x, y, player){
        this.x = x;
        this.y = y;
        this.shape = player ? player.shape : arena_block_shape;
        this.clr = player ? player.clr : arena_block_clr;
        this.player = player ? player : null;
        this.proc = null;
        //console.log(this.clr);
    }
    set_player(player){
        if (typeof player !== 'undefined'){
            this.player = player;
            if (this.proc == null){
                this.shape = player.shape;
                this.clr = player.clr;
            }
        }
    }
    set_proc(pc){
        this.proc = pc;
        this.clr = ShadeBlend(+0.30, this.proc.player.clr);
        this.shape = ['round', 1];
        //this.set_player(player);
    }
    unset_proc(){
        this.proc = null;
        this.clr = this.player ? this.player.clr : arena_block_clr;
        this.shape = this.player ? this.player.shape : arena_block_shape;
    }
    draw(){
        fill(this.clr);
        switch (this.shape[0]){
            case 'square' :
                rect(this.x, this.y, space_x-this.shape[1], space_y-this.shape[1]);
                break;
            case 'round' :
                ellipse(this.x, this.y, space_x-this.shape[1], space_y-this.shape[1]);
                break;
            case 'triangle' :
                triangle(this.x - space_x/2, this.y-space_y/2+(space_y-this.shape[1]),
                this.x-space_x/2+((space_x-this.shape[1])/2), this.y-space_y/2,
                this.x-space_x/2+(space_x-this.shape[1]), this.y-space_y/2+(space_y-this.shape[1]));
                break;
        }
    }
};

class Proc{
    constructor(pid, player, block){
        this.pid = pid;
        console.log("New proc pid: " + pid);
        this.player = player;
        this.player.nb_procs++;
        this.block = block;
        this.block.set_proc(this);
        this.is_alive = true;
    }
    move(to_player, to_block){
        if (to_player != this.player){ //proc has been stolen
            this.player.nb_procs--;
            console.log('move');
            this.player = to_player;
            this.player.nb_procs++;
        }
        this.block.unset_proc();
        this.block = to_block;
        this.block.set_proc(this);
    }
    kill(){
        this.player.nb_procs--;
        console.log('kill');
        this.block.unset_proc();
    }
};

//Player shapes: square / triangle / round

class Player{
    constructor(id, name, msg, clr, shape){
        this.id = id;
        this.name = (name.length > 11 ? name.slice(0, 11) : name);
        this.msg = msg;
        this.clr = clr;
        this.shape = shape;
        this.sum_alives = 0;
        this.control = 0.0;
        this.nb_procs = 0;
        console.log("Player " + this.id + " joined the game.\nWelcome " + this.name + "!");
    }
    set_name(name){
        this.name = name;
    }
    get_name(){
        return this.name;
    }
    get_control(){
        this.control = (in_map.split(this.id).length - 1) / 40.96; // /4096 * 100
    }
};

//initialization function
function preload(){
    dark_ui = loadImage("../assets/corewar_dark_back.png");
    light_ui = loadImage("../assets/corewar_white_back.png");
    joystix_font = loadFont("../fonts/joystix_monospace.ttf");
    //title = document.getElementById('title');
    mem_div = document.getElementById("mem");
    theme_ui = light_ui;
    init();
}

function init()
{
    ws = new ReconnectingWebSocket(address);
    if (window.WebSocket === undefined)
        console.log("Error: WebSockets not supported");
    //callbacks:
    ws.onopen = function(event){
        console.log("Access to WebSocket " + address + " granted");
    };

    ws.onmessage = function(event){
        let data = event.data;
        let type = data.slice(0, 5);
        //console.log(event.data);
        //console.log("Rec:" + type);
        switch (type){
            case "<set>":
                in_set = JSON.parse(data.slice(5, data.length));
                init_players();
                break;
            case "<cyc>":
                let tmp = JSON.parse(data.slice(5, data.length));
                in_cyc[1] == tmp[1] ? 0 : init_new_period();
                in_cyc = tmp;
                countdown = countdown > 0 ? --countdown : parseInt(in_cyc[1]);
                break;
            case "<exe>":
                in_exe = JSON.parse(data.slice(5, data.length));
                //console.log(in_exe);
                get_procs();
                break;
            case "<liv>":
                in_liv = JSON.parse(data.slice(5, data.length));
                get_life();
                break;
            case "<hex>":
                in_hex = data.slice(5, data.length);
                //console.log("ok");
                // update_hexdump();
                break;
            case "<map>":
                in_map = data.slice(5, data.length);
                get_ownership();
                get_map_control();
                break;
            case "<end>": victory();
                break;
        }
    };
    ws.onclose = function(){
        console.log("WebSocket " + address + " closed");
    };
    ws.onerror = function(event){
        console.log("Communication error with " + address);
        console.log(event);
    };
}

function init_blocks(){
    for (let i = 0; i < 4096; i++){
        block[i] = new Block(start_x + (itx % 1326), start_y + (ity % 926), null);
        itx = itx > 1290 ? 0 : itx + space_x;
        ity = itx == 0 ? ity + space_y : ity;
    }
}

function init_players(){
    let id;
    for (let i = 0; i < in_set.length; i++){
        id = i + 1;
        player[i] = new Player(id.toString(), in_set[i], "insert_warcry", player_clrs[i], player_shapes[i]);
    }
}

function get_life(){
    if (typeof player !== 'undefined' && player.length > 0){
        ++player[parseInt(in_liv) - 1].sum_alives;
        last_alive = player[parseInt(in_liv[0]) - 1];
    }
    let alive = get_proc_by_pid(parseInt(in_liv[1]));
    if (alive) alive.is_alive = true;
}

function init_new_period(){
    if (typeof player !== 'undefined' && player.length > 0){
        for (let i = 0; i < player.length; i++){
            player[i].sum_alives = 0;
        }
    }
    if (typeof procs !== 'undefined' && procs.length > 0){
        for (let i = 0; i < (procs.length); i++){
            if (procs[i].is_alive == false){
                procs[i].kill();
                procs.splice(i, 1);
                return 0;
            }
            else
                procs[i].is_alive = false;
        }
    }
}

//GET METHODS

function get_procs(){
    let owner = parseInt(in_exe[0]) - 1;
    let addr = parseInt(in_exe[1]);
    let pid = parseInt(in_exe[2]);
    let pc = get_proc_by_pid(pid);
    if (pc)
        pc.move(player[owner], block[addr]);
    else
        procs[procs.length] = new Proc(pid, player[owner], block[addr]);
}

function get_ownership(){
    if (block_mode == true){
        //update_clrs();
        if (typeof in_map !== 'undefined' && in_map.length > 0){
            for (let i = 0; i < 4096; i++){
                block[i].set_player(player[parseInt(in_map[i]) - 1]);
            }
        }
    }
}

function get_map_control(){
    if (typeof player !== 'undefined' && player.length > 0){
        for (let i = 0; i < player.length; i++){
            player[i].get_control();
            fill(player[i].clr);
        }
    }
}

function update_cycles(){
    //hori,verti
    textAlign(LEFT, CENTER);
    textFont(joystix_font); // textFont('Courier New');
    // textStyle(BOLD);
    textSize(14);
    fill(clrs.theme);
    let cyc_tot = "Game Total   : "; //in_cyc[0];
    let cyc_cd  = "Next Death   : "
    let cyc_td  = "Cycle to Die : "; //in_cyc[1];
    if (typeof in_cyc !== 'undefined' && in_cyc.length > 0){
        cyc_tot += in_cyc[0];
        cyc_td += in_cyc[1];
        cyc_cd += countdown;
    }
    else{
        cyc_tot += "--";
        cyc_td += "--";
        cyc_cd += "--";
    }
    text(cyc_tot, 88, 425);
    text(cyc_cd, 88, 445);
    text(cyc_td, 88, 465);
}

//UPDATE METHODS

function update_lives(){
    //hori,verti
    textAlign(LEFT, CENTER);
    textFont(joystix_font); // textFont('Courier New');
    // textStyle(BOLD);
    textSize(20);
    fill(clrs.theme);
    let x = 88;
    text("last :", x, 740);
    last_alive ? fill(last_alive.clr) : fill(clrs.theme);
    last_alive ? text(last_alive.name, 200, 740) : text("--", 220, 740);
    fill(clrs.theme);
    text("CTD  :", x, 770);
    textSize(14);
    x += 110
    if (typeof player !== 'undefined' && player.length > 0){
        for (let i = 0; i < player.length; i++){
            fill(player[i].clr);
            text(player[i].sum_alives, x, 770);
            x += 70;
        }
    }
    else{
        text("--", 220, 770);
    }
}

function update_names(){
    //hori,verti
    textAlign(LEFT, CENTER);
    textFont(joystix_font); // textFont('Courier New');
    // textStyle(BOLD);
    textSize(20);
    fill(clrs.theme);
    let x = 88;
    let y = 270;
    if (typeof in_set !== 'undefined' && in_cyc.length > 0){
        for (let i = 0; i < in_set.length; i++){
            if (i == 1 || i == 3) y += 30;
            else y = 270;
            if (i == 2 || i == 3) x = 308;
            else x = 88;
            if (typeof player[i].name !== 'undefined'){
                fill(player[i].clr);
                text(player[i].name, x, y);
            }
            else{
                fill(clrs.theme);
                text("unknown", x, y);
            }
        }
    }
    else if (in_cyc.length == 0)
        text("waiting for players", 88, y);
}

function update_procs(){
    //hori,verti
    textAlign(LEFT, CENTER);
    textFont(joystix_font); // textFont('Courier New');
    // textStyle(BOLD);
    textSize(20);
    let x = 88;
    fill(clrs.theme);
    text("SUM :", x, 600);
    x += 110
    if ((typeof procs !== 'undefined' && procs.length > 0)
        && (typeof player !== 'undefined' && player.length > 0)){
        for (let i = 0; i < player.length; i++){
            fill(player[i].clr);
            text(player[i].nb_procs, x, 600);
            x += 70;
        }
    }
    else{
        text("--", 200, 600);
    }
}

function update_blocks(){
    if (block_mode == true){
        //update_clrs();
        rectMode(CENTER);
        for (let i = 0; i < 4096; i++){
            block[i].draw();
        }
    }
}

function update_map_control(){
    let x = 88;
    let y = 880;
    let txt;
    textAlign(LEFT, CENTER);
    textFont(joystix_font); // textFont('Courier New');
    // textStyle(BOLD);
    if (typeof player !== 'undefined' && player.length > 0){
        textSize(14);
        for (let i = 0; i < player.length; i++){
            rectMode(CORNER);
            fill(player[i].clr);
            rect(x, y, player[i].control * 4, 10);
            txt = Number((player[i].control).toFixed(2)).toString() + "%";
            text(txt, 400, y);
            y += 20;
        }
    }
    else{
        textSize(20);
        fill(clrs.theme);
        text("waiting for players", x, 895);
    }
}

function update_hexdump(){
    if (text_mode == true){
        textAlign(LEFT, TOP);
        textFont('Courier New');
        text_mode_bold ? textStyle(BOLD) : textStyle(NORMAL);
        textSize(11.5);
        // str = mem_div.innerHTML;
        // trim = str.rpl(/0x0.*: /, '')
        fill(255,255,255,200);
        text(in_hex, 550, 28); //win.w * 18 / 20, win.h * 18 / 20);
    }
}

function setup(){
    //noLoop();
    frameRate(30);
    canvas = createCanvas(1920, 1000); //WEBGL);
    rectMode(CENTER);
    noStroke();
    init_blocks();
}

function draw(){
    //clean and resize the canvas
    //canvas_resize();
    background(back_clr);
    background(theme_ui);
    //update UI
    update_names();
    update_cycles();
    update_procs();
    update_lives();
    update_map_control();
    //update map
    update_blocks();
    update_hexdump();
    //...
}

function sw(what){
    return (what ? false : true);
}

function get_proc_by_pid(pid){
    if (typeof procs !== 'undefined' && procs.length > 0){
        for (let i = 0; i < procs.length; i++){
            if (procs[i].pid == pid)
                return (procs[i]);
        }
    }
    return null;
}

function keyPressed(){
    switch (keyCode){ //RESET setting
        case 86: text_mode = sw(text_mode); break;
        case 66: block_mode = sw(block_mode); break;
        case 72: text_mode_bold = sw(text_mode_bold); break;
        case 84: dark_mode = sw(dark_mode);
            if (dark_mode){
                back_clr = clrs.dark_grey;
                document.body.style.backgroundColor = back_clr;
                clrs.theme = clrs.light_grey;
                theme_ui = light_ui;
            }
            else{
                back_clr = clrs.light_grey;
                document.body.style.backgroundColor = back_clr;
                clrs.theme = clrs.dark_grey;
                theme_ui = dark_ui;
            }
        break;
    }
    //TO ADD: color and shape bindings
    //  console.log(keyCode);
}

function victory(){
    //reinit core GET variables
    procs = [];
    block = [];
    player = [];
    in_set = [];
    in_cyc = [];
    in_exe = [];
    in_liv = [];
    in_hex = undefined;
    in_map = undefined;
    last_alive = undefined;
}