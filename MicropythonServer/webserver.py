'''
Example code for the (http) server library
Author : Mohamed Gamal
Date : 2/3/2020

http server to control the rgb led in tiva-c
    -esp32 is connected to tiva-c through UART1
    -web page have 7 buttons for varuis colors 
    -when a button is pressed it send an http request indicating which button 
    is pressed
    -the server handler sends the first letter of the color by UART1
'''


import socket
from server import setHandler , serve, runServer, setResourceFolder
from machine import UART

uart = UART(1)                                      

def testServer(_, object):
    uart.write(object["button"][0])
    print(object)

addr = socket.getaddrinfo("0.0.0.0",8080)[0][-1]

setHandler({"/" : [serve,"web.html"]})            
setHandler({"connect" : [serve,"connect.html"]})
setHandler({"test" : [testServer,1]})

setResourceFolder("/src")
runServer()
