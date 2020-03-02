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
