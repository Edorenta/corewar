# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    serve.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/01 21:07:11 by pde-rent          #+#    #+#              #
#    Updated: 2018/07/02 21:12:57 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
#if [[ $(lsof -ti tcp:8080) ]]; then
#    kill -9 $(lsof -ti tcp:8080)
#fi
#if [[ $(lsof -ti tcp:8082) ]]; then
#    kill -9 $(lsof -ti tcp:8082)
#fi
pkill -f file_server
pkill -f websocket_pipe
pkill -f socket_bridge
nohup python3 file_server.py >/dev/null 2>&1 &
nohup python3 websocket_pipe.py >/dev/null 2>&1 &
nohup python3 socket_bridge.py >/dev/null 2>&1 &
#nohup python3 file_server.py
#nohup python3 websocket_pipe.py
#nohup python3 socket_bridge.py
