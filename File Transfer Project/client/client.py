#Jonathan Chavarria, Chandler Martin, Jeffrey Carson
#CPE 400 5/2/22
#File Transfer Application Project
#Client Code (SENDER)
#Takes input from command line to determine which files to 
#send and how many connections to open.
# EX:

# python3 client.py <Directory_Name> <Num_Connections> (if linux or mac)
# py client.py <Directory_Name> <Num_Connections> (if windows)


# <Directory_Name>  the directory containing the files the user wishes to send.
# <Num_Connections>  Number of concurrent connections the user wishes to send their files through
#          (If user leaves blank, will default to 1)

import socket
import sys
import os
import myChecksumClient
import threading
import time
import numpy as np

#Takes in a directory name
#Returns a list of all files in that directory
def filesInDir(folder):
    arr = []
    os.chdir(folder)
    for dName, subdirList, fileList in os.walk('.'):
        for fName in fileList:
            arr.append(fName)
    os.chdir('..')
    return arr

#Takes in a list of filenames and the directory name
#Sends files within the list "filenames"
def sendFiles(filenames, foldername):
    s = socket.socket()
    host = socket.gethostname()
    port = 5050
    s.connect((host,port))
   
    #Sending number of files for server to expect
    s.send(f"{len(filenames)}".encode())
    time.sleep(.25)
    
    #looping through filenames and sending them to server
    for filename in filenames:
        try:
            #Sends the filename and the checksum of that file over a socket connection
            s.send(f"{filename}bruhmoment{myChecksumClient.checksum(f'{foldername}/{filename}')}".encode())
            print(f"[SENDING] {filename}")
            with open(foldername + '/' + filename, "rb") as f:
                while True:
                    bytes_read = f.read(1024)
                    if not bytes_read:
                        break
                
                    time.sleep(.25)
                    s.send(bytes_read)
        except IOError:
            print(f"Couldn't find {foldername}/{filename}!")
    s.close()

if __name__ == '__main__':
    #If user doesnt enter correct command line syntax
    if len(sys.argv) == 1:
        print("\n[ERROR] Incorrect Syntax\n")
        print("Correct Usage: \n\n\tpython3 client.py <Directory_Name> <Num_Connections>\n")
        exit()
    #If user enters non-existant directory
    if (os.path.isdir(sys.argv[1]) == False):
        print(f"\n[ERROR] Could not find \"{sys.argv[1]}\" directory\n")
        exit()
    

    print(f"\n[TRANSFERRING FROM] {sys.argv[1]}")
    if len(sys.argv) > 2:
        input = int(sys.argv[2])
        print(f"[CONCURRENCY COUNT] {sys.argv[2]}\n")
    else:
        print(f"\n[CONCURRENCY COUNT] 1\n")
        input = 1

    foldername = sys.argv[1]
    filenames = filesInDir(foldername)
    split = np.array_split(filenames, input)

    i = 1
    for array in split:
        print(f"[CONNECTION {i}] {array}")
        thread = threading.Thread(target=sendFiles, args=(array, foldername))
        thread.start()
        i +=1
    print('\n')

