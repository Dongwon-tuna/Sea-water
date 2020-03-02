import RPi.GPIO as GPIO
import time
from socket import *

GPIO.setmode(GPIO.BCM)
GPIO.setup(21,GPIO.IN,pull_up_down = GPIO.PUD_UP)
GPIO.setup(23,GPIO.IN,pull_up_down = GPIO.PUD_UP)

check = 0 #distinguish line and do
space = 0 #distinguish space between code
a = []    #store the morse code


#while loop

while True:
    input_state = GPIO.input(21)
    input_statet = GPIO.input(23)
    


    if input_state == False:
        time.sleep(0.01)
        print(" ")
        check = check +1
        

        if space >90000:
            print("space")
            a.append(' ')
         
        space = 0
        
       

    if input_state == True:
        if check>=5:
            print('line')
            a.append('-')

        if check>0 and check<5:
            print('dot')
            a.append('.')
                  
        check = 0     
        space = space + 1

        
    if input_statet == False:
        a.remove(' ')

        
        end = ''.join(a)
        
        clientSock = socket(AF_INET, SOCK_STREAM)
        clientSock.connect(('192.168.0.13', 8080))
        way = end
        clientSock.send(way.encode('utf-8'))
        break


        
        
