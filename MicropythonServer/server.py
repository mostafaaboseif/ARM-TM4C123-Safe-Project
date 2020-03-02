import socket

gSocket = ''        #to store the answering socket
handler = {}       #to store handelers ( key --> path requested, value --> [function to be exuted, its parameters])
resources = ''      #to store the resources path


# returns the requested path and the http request parameters 
def analyze(req):
    if len(req) < 5 : return (None,{})
    index = 5
    data = ""
    dataObj = {}
    key = ''
    path = ''
    #print(req)
    while True : 
        if req[index] == 63 :   #?
            if len(data) == 0 :
                path = '/'
            else :
                path = data
            data = ''
            index += 1
        elif req[index] == 61 : #=
            key = data
            data = ''
            index += 1
        elif req[index] == 38 : #&
            dataObj[key] = data
            data = ""
            index += 1
        elif req[index] == 32 : #space
            #print(" space found ")
            if len(data) == 0 and len(path) == 0 :
                #print("path is / ")
                path = "/"
            elif len(key) > 0 : dataObj[key] = data
            else : path = data
            break
        else : 
            data += chr(req[index])
            index += 1 
    print((path,dataObj))
    return (path,dataObj)

#is called to handel the path (check if it's available in handeler)
def handle(path,object,socket): 
    global gSocket,resources
    gSocket = socket
    if path in handler:                #check if the requested path in the handler dictionary
        parm = handler[path][1]        #get the parameters list that will be passed to the callback function
        handler[path][0](parm,object)  #calling the callback function with the parameters list  as the first arg and http parameters dictionary as the second arg
        print("DONE")
    else :                              #if the requested path is not in the handler check if it's a file requested (.js - .css - image)
        print("resource file is : " + resources)    
        try:
            print("openning : " + resources+"res/"+path)
            file = open(resources+"res/"+path,"r")  #open the resources file
            try:                                    #if it's in the resources file reaad it and send it
                while True :
                    d = file.read(1024)             #read the file
                    if len(d) == 0 : break          #if the read stream length is 0 (EOF) break
                    socket.write(d)                 #send the read stream
                print("DONE")
            except:
                print('error happend while writing to socket')  #error happended will writing to the socket 
        except :                                    #if it's not in the resources file send 404 file not found
            gSocket.write("404 file not found")
            print("ERROR 0x55")                     # error code to traceback the errors

		
def serve(name,object) :    #function used to send serve files to the client (html files, imgs, js files) if the the requested path is / u will serve a specific file
	global resources
	print("openning : " + resources+name)
	f = open(resources+name,"r")
	try:
		while True :
			d = f.read(4096)
			if len(d) == 0 : break
			gSocket.write(d)
	except:
		print('error happend while writing to socket')

def setHandler(functions): #used to add handelers in handel (handel format {'key' : [function,parameters list]})
	global handler
	for key in functions :
		handler[key] = functions[key]

def setResourceFolder(path): #set the folder of the website
	global resources
	resources = path+'/'

def runServer() : #used to start the server
	addr = socket.getaddrinfo("0.0.0.0",8080)[0][-1]
	s = socket.socket()
	s.bind(addr)
	s.listen(3)
	while True:
		try:
			res = s.accept()
			client_s = res[0]
			client_addr = res[1]
			print("client address: ",client_addr)
			req = client_s.recv(1024)
			client_s.write("HTTP/1.0 200 OK \r\n\r\n")
			print("req : " + str(req))
			path,parametersObject = analyze(req)
			handle(path,parametersObject,client_s)
			client_s.close()
		except:
			print('error happend 0x01')