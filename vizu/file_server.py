# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    file_server.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/28 22:07:23 by pde-rent          #+#    #+#              #
#    Updated: 2018/06/28 22:07:26 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# !/usr/bin/python3
import http.server
import socketserver

port = 8080

Handler = http.server.SimpleHTTPRequestHandler
httpd = socketserver.TCPServer(("", port), Handler)
print("Serving local files at localhost: %d" % port)
httpd.serve_forever()
