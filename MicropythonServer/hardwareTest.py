from machine import Pin

succ_err_sel = Pin(15, Pin.OUT)
sel_0 = Pin(14, Pin.OUT)
sel_1 = Pin(12, Pin.OUT)
sel_2 = Pin(13, Pin.OUT)

succ_err_sel.off()
sel_0.on()
sel_1.on()
sel_2.on()
from machine import I2C
import time
i2c = I2C(scl = Pin(22), sda = Pin(21))

while True:
    i2c.scan()
    time.sleep(0.5)