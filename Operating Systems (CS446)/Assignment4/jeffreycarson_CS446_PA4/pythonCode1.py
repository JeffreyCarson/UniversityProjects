#Set up a docker environment for this code, and don't try to include superfluous packages!
import cv2 as cv
import socket
from OpenSSL import crypto, SSL
import numpy as np
import matplotlib.pyplot as plt
import random
import os

blackblankimage = random.randint(0, 255) * np.ones(shape=[512, 512, 3], dtype=np.uint8)

cv.putText(blackblankimage, "You did it!", (100, 100), cv.FONT_HERSHEY_SIMPLEX, 2, (255, 255, 255))
cv.rectangle(blackblankimage, pt1=(200,200), pt2=(300, 300), color=(0,0,255), thickness=-1)
plt.axis('off')
plt.imshow(blackblankimage)

plt.savefig("./pythonCode1Image.png")

#modify this code so that it also generates self signed certificate and keys

key = crypto.PKey()
key.generate_key(crypto.TYPE_RSA, 2048)
certification = crypto.X509()

certification.get_subject().C = "US"
certification.get_subject().ST = "NV"
certification.get_subject().L = "Reno"
certification.get_subject().O = "University of Nevada, Reno"
certification.get_subject().OU = "CSE"
certification.get_subject().CN = socket.gethostname()

certification.gmtime_adj_notBefore(0)
certification.gmtime_adj_notAfter(157680000)
certification.set_serial_number(42)

certification.set_pubkey(key)

certification.sign(key, 'sha512')

open('jeffreycarson_selfSignedCertificate.PEM', 'wt').write(str(crypto.dump_certificate(crypto.FILETYPE_PEM, certification)))
open('jeffreycarson_privateKey.PEM', 'wt').write(str(crypto.dump_privatekey(crypto.FILETYPE_PEM, key)))
open('jeffreycarson_publicKey.PEM', 'wt').write(str(crypto.dump_privatekey(crypto.FILETYPE_PEM, key)))










