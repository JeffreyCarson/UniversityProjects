############################################
# TAKES DATA DIRECTLY AND RETURNS CHECKSUM #
############################################

# Jeffrey Carson
# Checksum implementation according to Lec 12 slides
# 4/29/22 CPE400

#CHECKSUM ALGORITHM
#convert data into binary
#divide data into 16 bit integers
#add segment contents 
#take 1's compliment

#converts a string into binary
def toBinary(arr):
    return ''.join(format(ord(i), '08b') for i in arr)

#splits a long binary string into a 2D array of 
# 16 bit binary numbers
def splitInto2D(binaryArr):
    arr = []
    temparr = []
    #split binary string into 2d array of 16 bit binary strings
    for i in range(0, len(binaryArr), 16):
        temparr = []
        for j in range(i, i+15):
            if (j < len(binaryArr)):
                temparr.append(binaryArr[j])
        arr.append(temparr)
    #formatting strings correctly
    for x in range(len(arr)):
        arr[x] = ''.join((arr[x]))
        arr[x] = int(arr[x], 2)
    return arr

# determines 1's compliment of binary number (switches 1's and 0's)
def compliment(arr):
    newArr = []
    newArr.append('0')
    newArr.append('b')
    #increment through inputted array, if 1, push 0 to new string, else, push 1.
    for i in range(len(arr)):
        if i > 1:
            if arr[i] == '0':
                newArr.append('1')
            if arr[i] == '1':
                newArr.append('0')
    
    newArr = ''.join((newArr))
    return newArr

#adds two 16 bit binary numbers, accounts for the wraparound 
# if number is over 16 bits
def addTwoBinary(bin1, bin2):
    sum = bin1 + bin2
    newArr = []
    #if sum has a wrap-around bit, add it to the end and pop leading bit
    #else, return sum
    if len(bin(sum)) > 18:
        sum += 1
        difference = len(bin(sum)) - 18
        newArr.append('0')
        newArr.append('b')
        for i in range(difference+2, len(bin(sum))):
            newArr.append(bin(sum)[i])
        newArr = ''.join((newArr))
        return int(newArr, 2)
    else:
        return sum

#returns true if passed a binary strings
def isBinaryStr(arr):
    for i in range(len(arr)):
        if arr[i] != '0' and arr[i] != '1' and arr[i] != '\n':
            return False
    return True

#takes a file and its path, calculates the checksum from data, returns checksum
def checksum(data):

    string = str(data)
    string = string.replace('\n', '')
    #if data is not binary, convert to binary
    if isBinaryStr(string) is False:
        string = toBinary(string)
    #split into 16 bit segments
    splitarr = splitInto2D(string)
    sum = 0
    #add segment contents together
    for x in range(len(splitarr)):
        sum = addTwoBinary(sum, splitarr[x])
    #take 1's compliment, and return value
    return compliment(bin(sum))
