#Jonathan Chavarria, Chandler Martin, Jeffrey Carson
#CPE 400 5/2/22
#File Transfer Application Project
#Server Code (RECEIVER)
#Accepts files from the client
#Make sure this file is running first, so it is seen as an available connection.

# To run:
# python3 server.py (if linux or mac)
# py server.py (if windows)


#Transmitted files will be added to current working directory of server.py

import socket
import myChecksumServer
import threading

#Gets data from client and performs neccessary operations
def getFiles(conn, addr):
    print(f"[CONNECTED] {addr} ", flush = True)
    length = int(conn.recv(1024).decode())

    #For amount of connections recieved
    for i in range(length):
        data = conn.recv(1024).decode()
        filename, clientchecksum = data.split('bruhmoment')

        try:
            #Create file with corresponding name from client
            with open(filename, "wb+") as file:

                bytes_read = conn.recv(1024)
                file.write(bytes_read)

                # Calculate checksum of recieved data, compares to client-side checksum
                serverchecksum = myChecksumServer.checksum(bytes_read.decode())
                if (serverchecksum != clientchecksum):
                    print(f"{filename} experienced corruption while being transferred, try retransmitting\n")

                print(f"[RECEIVED] {filename} ")
        except IOError:
            print("Problem recieving data!")

    print(f"[DISCONNECTED] {addr} ", flush = True)
    conn.close()

if __name__ == '__main__':
    s = socket.socket()
    host = socket.gethostname()
    port = 5050
    s.bind((host,port))
    s.listen(5)
    print(host)
    print("Waiting for any incoming connections ...")

    while True:
        conn, addr = s.accept()
        thread = threading.Thread(target=getFiles, args=(conn, addr))
        thread.start()