def gpio(pin):
    gpio = {
        "D3" : 0,
        "D4" : 2,
        "built_in" : 2,
        "D2" : 4,
        "D1" : 5,
        "D6" : 12,
        "D7" : 13,
        "D0" : 16,
        "D5" : 14,
        "D8" : 15,
    }
    return gpio[pin]