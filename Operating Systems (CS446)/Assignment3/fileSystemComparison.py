#Jeffrey Carson
#CS446 
#4/9/22
#Assignment 3
#Hierarchical vs Single Level 

#In singleLevelFiles.txt, the files are printed in seemingly random order
#all with size of 0. While in hierarchicalFiles.txt, the files are printed
#in groups of 10, following the directory that those ten files are in. The 
#txt files in both files all have a size of 0, which is expected because the
#files dont contain any information. The only 'files' that have a size are
#the directories in hierarchical root. This is because they have to hold the
#information pertaining to the subdirectories within them.

#In order to implement similar functionality to a hierarchical system in 
# a single level system, include some sort of tag in front of the file name 
# indicating a pseudo path to that file. For example:
# Instead of looking like this:
#
#   root
#       directory1
#          -file1.txt
#          -file2.txt
#       directory2
#          -file1.txt
#          -file2.txt   


# We would have:
#
#   root
#       directory1/file1.txt
#       directory1/file2.txt
#       directory2/file1.txt
#       directory2/file2.txt
#
# This way, we would be able to have multiple files of the same name AND have the 
# organizational benefits of a hierarchical system.

import os, time

#Makes the files and directories needed for this specific project
def makeFilesAndDirectories():
    os.mkdir('singleRoot')
    os.mkdir('hierarchicalRoot')
    #Making Single Level File Structure
    os.chdir('./singleRoot')
    for x in range(100):
        open('file' + str(x+1) + '.txt', 'x')
    #Making Hierarchical File Structure
    os.chdir('../hierarchicalRoot')
    temp = 1
    for x in range(10):
        name = 'files' + str(temp) + '-' + str(temp+9)
        os.mkdir(name)
        os.chdir('./' + name)
        for i in range(10):
            open('file' + str(temp) + '.txt', 'x')
            temp += 1
        os.chdir('..')
    os.chdir('..')

#traverses single level file structure
def singleTraverse(fileRoot):
    arr = []
    os.chdir(fileRoot)
    for dName, subdirList, fileList in os.walk('.'):
        arr.append([dName, os.path.getsize(dName)])
        for fName in fileList:
            arr.append([fName, os.path.getsize(fName)])
    os.chdir('..')
    arr.pop(0)
    return arr

#traverses hierarchical file structure, slightly different 
#from single level, as changing the working directory is needed
def hierarchicalTraverse(fileRoot):
    arr = []
    os.chdir(fileRoot)
    for dName, subdirList, fileList in os.walk('.'):
        arr.append([dName, os.path.getsize(dName)])
        for fName in fileList:
            os.chdir(dName)
            arr.append([fName, os.path.getsize(fName)])
            os.chdir('..')
    os.chdir('..')
    arr.pop(0)
    return arr

#Prints a list of size [n x 2] to file 
def printToFile(arr, fName):
    f = open(fName, "w")
    #f.write("Filename:\t\tSize:\n")
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            f.write(str(arr[i][j]) + '\t\t')
        f.write('\n')
    f.close

#Finds average of values in second column of a list
def myAvg(arr):
    sum = 0
    for i in range(len(arr)):
        sum += arr[i][1]
    sum /= len(arr)
    return sum

def main():

    singleArr = []
    hierarchicalArr = []
    
    #if directories havent been made yet, make them, else skip
    if((os.path.isdir('singleRoot') == False) and (os.path.isdir('hierarchicalRoot') == False)):
        makeFilesAndDirectories()
    
    t0 = time.time()
    singleArr = singleTraverse('./singleRoot')
    t1 = time.time()
    sTraverse = t1-t0

    t0 = time.time()
    hierarchicalArr = hierarchicalTraverse('./hierarchicalRoot')
    t1 = time.time()
    hTraverse = t1-t0

    printToFile(singleArr, 'singleLevelFiles.txt')    
    printToFile(hierarchicalArr, 'hierarchicalFiles.txt')    

    print("\nSingle Level File System")
    print("Number of Files: " + str(len(singleArr)))
    print("Average File Size: " + str(int(myAvg(singleArr))))
    print("Traversal Time: " + f'{sTraverse:0.5f}s')

    print("\nHierarchical File System")
    print("Number of Files: " + str(len(hierarchicalArr)))
    print("Average File Size: " + f'{myAvg(hierarchicalArr):0.5}')
    print("Traversal Time: " + f'{hTraverse:0.5f}s\n')

if __name__ == '__main__':
    main()