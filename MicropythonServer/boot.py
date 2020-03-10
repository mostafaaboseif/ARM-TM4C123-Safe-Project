import gc
import network
from time import sleep_ms
from const import gpio
from machine import Pin

gc.collect()
notifi = Pin(gpio("D4"),Pin.OUT)
notifi.on()
station = network.WLAN(network.STA_IF)                                          
station.active(True)
print("Nodemcu .. Micropython iot board")
print("connecting to WIFI ...")
available = station.scan()
names = [name[0] for name in available]
print("avialabe ssids : ")
for name in names :
	print("\t" + str(name))
ssid = "MGTMM"#input("ssid : ")
password = '8111998alia' #input("password : ")
station.connect(ssid,password)
ip = 0
for triels in range(30):
	sleep_ms(400)
	if station.isconnected() :
		ip = station.ifconfig()[0]
		print("Connected to " + ssid)
		notifi.off()
		break
	else :
		print("Trying to connect to " + ssid)
del available, names, ssid, password