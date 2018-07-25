# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    socket_bridge.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/28 22:07:27 by pde-rent          #+#    #+#              #
#    Updated: 2018/07/02 20:47:08 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# !/usr/bin/python3

import websocket
import socket
import time
import asyncio
import sys
import os

s_uri = os.getenv("WS_HOST", "127.0.0.1")
s_port = os.getenv("WS_PORT", "8083")
# ws_uri = os.getenv("WS_HOST", "127.0.0.1")
ws_port = os.getenv("WS_PORT", "8082")

address = "ws://" + s_uri + ":" + ws_port

# Create a TCP/IP socket

# Bind the socket to the port
print("Expecting data on %s:%s [TCP]" % (s_uri, s_port))
print("Sending data to %s:%s [WebSocket]" % (s_uri, ws_port))
# Let's bind
# sock.bind((s_uri,int(s_port)))
# Listen for incoming connections
# sock.listen(1)
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
wsock = websocket.create_connection(address)
sock.bind((s_uri,int(s_port)))
sock.listen(1)
loop = asyncio.get_event_loop()

async def send_websocket(data):
	await wsock.send(data)

async def play_corewar():

	#_dbg = 0
	payload = None
	(new_socket, client_address) = sock.accept()
	while 1:
		buf = None
		while 1:
			payload = new_socket.recv(1).decode()
			# print(payload)
			if (not payload or ("<end>" in payload)): #or len(payload) < 2):
				print("End of payload.\nWaiting for another game to begin!")
				new_socket.close()
				await play_corewar()
				return
				# continue
			elif not "$" in payload:
				if buf:
					buf += payload
				else:
					buf = payload
			# print("payload:%s" % payload)
			if "$" in payload:
				# print("%s" % buf, end='')
				# print("Sending #%d" % _dbg)
				#_dbg += 1
				# asyncio.ensure_future(send_websocket(buf))
				# time.sleep(0.05)
				wsock.send(buf)
				buf = None
			# if ("<end>" in payload): #or len(payload) < 2):
				# print("End of payload.\nWaiting for another game to begin!")
				# sock.close()
				# wsock.close()
				# return
				# c = sys.stdin.read(1)
				# if (c == 'y' or c == 'Y'):
				# 	continue
				# else:
				# 	sock.close()
				# 	wsock.close()
				# 	sys.exit(0)
				# 	break

# loop.run_until_complete(play_corewar())
asyncio.ensure_future(play_corewar())
loop.run_forever()
# loop.close()
