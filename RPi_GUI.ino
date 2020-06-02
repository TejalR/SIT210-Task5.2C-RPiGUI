from tkinter import *
import tkinter.font
from gpiozero import LED
import RPi.GPIO
RPi.GPIO.setmode(RPi.GPIO.BCM)

## Hardware ##
ledRed = LED(18)
ledGreen = LED(17)
ledBlue = LED(27)

## GUI DEFINITIONS ##
window = Tk()
window.title("LED Toggler")
myFont = tkinter.font.Font(family = "Calibri", size = 12, weight = "bold")

## EVENT FUNCTIONS ##
def ledRedToggle():
    if ledRed.is_lit:
        ledRed.off()
        ledRedButton["text"] = "Turn Red LED On"
    else:
        ledRed.on()
        ledRedButton["text"] = "Turn Red LED Off"
       
def ledGreenToggle():
    if ledGreen.is_lit:
        ledGreen.off()
        ledGreenButton["text"] = "Turn Green LED On"
    else:
        ledGreen.on()
        ledGreenButton["text"] = "Turn Green LED Off"

def ledBlueToggle():
    if ledBlue.is_lit:
        ledBlue.off()
        ledBlueButton["text"] = "Turn Blue LED On"
    else:
        ledBlue.on()
        ledBlueButton["text"] = "Turn Blue LED Off"

def close():
    RPi.GPIO.cleanup()
    window.destroy()


## WIDGETS ##
ledRedButton = Button(window, text = 'Turn Red LED On', font = myFont, command = ledRedToggle, bg = 'bisque2', height = 1, width = 24)
ledRedButton.grid(row = 0, column = 1)

ledGreenButton = Button(window, text = 'Turn Green LED On', font = myFont, command = ledGreenToggle, bg = 'bisque2', height = 1, width = 24)
ledGreenButton.grid(row = 1, column = 1)

ledBlueButton = Button(window, text = 'Turn Blue LED On', font = myFont, command = ledBlueToggle, bg = 'bisque2', height = 1, width = 24)
ledBlueButton.grid(row = 2, column = 1)

exitButton = Button(window, text = 'Exit', font = myFont, command = close, bg = 'red', height = 1, width = 10)
exitButton.grid(row = 3, column = 1)

window.protocol("WM_DELETE_WINDOW", close) # EXIT cleanly

window.mainloop() #Loop Forever
