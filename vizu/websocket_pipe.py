# import logging
import os
import tornado.web
import tornado.websocket
import tornado.ioloop
# from websocket_server import WebsocketServer

uri = os.getenv("WS_HOST", "127.0.0.1")
port = os.getenv("WS_PORT", "8082")
address = "ws://" + uri + ":" + port
root = os.path.dirname(__file__)
# class MainHandler(tornado.web.RequestHandler):
# 	def get(self):
# 		# items = ["Item 1", "Item 2", "Item 3"]
# 		self.render("index.html")

class WebSocketHandler(tornado.websocket.WebSocketHandler):
	connections = set()
	#i = 0
	def check_origin(self, origin):
		return True

	def open(self):
		self.connections.add(self)
		print("New client connected")
		self.write_message("You are connected")

	def on_message(self, message):
		#print(message)
		#if "<cyc>" in message:
		#	self.i += 1
		#	print(">> cycle #%d >>" % self.i)
		# print("Transmitting message...")
		for c in self.connections:
			c.write_message(message)
		# print(message)

	def on_close(self):
		self.connections.remove(self)
		print("Client disconnected")

print("URI ws://%s:%s is now open for web communication" % (uri, port))
application = tornado.web.Application([
	# (r"/(.*)", tornadso.web.StaticFileHandler, {"path": root, "default_filename": "index.html"}),
	# (r"/", MainHandler),
	(r"/", WebSocketHandler),
])
 
if __name__ == "__main__":
	application.listen(8082)
	tornado.ioloop.IOLoop.instance().start()

# # Called for every client connecting (after handshake)
# def new_client(client, server):
# 	print("New connection: Client #%d" % client['id'])
# 	#server.send_message_to_all("New client")

# # Called for every client disconnecting
# def client_left(client, server):
# 	print("Client #%d disconnected" % client['id'])

# # Called when a client sends a message
# def message_received(client, server, message):
# 	server.send_message_to_all(message)
# 	if 'i' not in message_received.__dict__:
# 		message_received.i = 0
# 	message_received.i += 1
# 	print("Transmitting #%d" % message_received.i)
# 	# print(message)

# server = WebsocketServer(int(port), host=uri, loglevel=0)
# print("URI ws://%s:%s is now open for web communication" % (uri, port))
# server.set_fn_new_client(new_client)
# server.set_fn_client_left(client_left)
# server.set_fn_message_received(message_received)
# server.run_forever()

# from SimpleWebSocketServer import SimpleWebSocketServer, WebSocket

# class transmit(WebSocket):

# 	def handleMessage(self):
# 		# echo message back to client
# 		if 'i' not in message_received.__dict__:
# 			message_received.i = 0
# 		self.sendMessage(self.data)
# 		print("Transmitting #%d" % message_received.i)

# 	def handleConnected(self):
# 		print(self.address, 'connected')

# 	def handleClose(self):
# 		print(self.address, 'closed')

# server = SimpleWebSocketServer('', 8082, transmit)
# print("URI ws://%s:%s is now open for web communication" % (uri, port))
# server.serveforever()
