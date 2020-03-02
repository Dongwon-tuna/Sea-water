from socket import *

serverSock = socket(AF_INET,SOCK_STREAM)
serverSock.bind(('',8080))
serverSock.listen(1)



morse_code = { '':' ','.-':'A', '-....':'B',
    '-.-.':'C', '-..':'D', '.':'E',
    '..-.':'F', '--.':'G', 'H':'....',
    '..':'H', '.---':'J', '-.-':'K',
    '.-..':'L', '--':'M', '-.':'N',
    '---':'O', '.--.':'P', '--.-':'Q',
    '.-.':'R', '...':'S', '-':'T',
    '..-':'U', '...-':'V', '.--':'W',
    '-..-':'X', '-.--':'Y', '--..':'Z',
    '.----':'1', '..---':'2', '...--':'3',
    '....-':'4', '.....':'5', '-....':'6',
    '--...':'7', '---..':'8', '----.':'9',
    '-----':'0', '--..-- ':',', '.-.-.-':'.',
    '..--..':'?', '-..-.':'/', '-....-':'-'

    }

b = []
c = []


while True:
    connectionSock, addr = serverSock.accept()
    data = connectionSock.recv(1024)
    puttheword = data.decode('utf-8')
    print(puttheword) 
    connectionSock.send('connecting'.encode('utf-8'))

    split_code = data.decode('utf-8').split(" ")
    b =split_code

    

    for i in b:
    
        c.append(morse_code.get(i))

    #res = ''.join(c)

    

   
    print(c)
    b.clear()
    c.clear()
    
   
        

   
