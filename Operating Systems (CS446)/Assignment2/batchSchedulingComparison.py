#Jeffrey Carson
#Assignment 2 CS446
# Compare and contrast, and simulate first come first served, 
# shortest job first, and priority scheduling process 
# management algorithms.
#FCFS is the most simple of the algorithms, simply processing the batch jobs in the order that they arrive. If two batch jobs arrive at the same time, then execute the one with the lower PID.
#ShortestFirst is a little more complicated than the other two, requiring checks at each time increment to decide which process has the last amount of time left to run.
#This implementation of Priority is similar to FCFS, where you run the process with the highest priority until completion. If two batch jobs arrive at the same time, then execute the one with the lower PID.


# batchfile structure:
# PID, Arrival Time, Burst Time, and Priority
# 1, 0, 20, 2
# 3, 0, 50, 1
# 7, 9, 4, 3
# 2, 10, 12, 4

import sys
import os.path

#Parameters
#   processCompletionTimes: the time that the process would be completed at by the algorithm
#   processArrivalTimes: accepts the time that each process arrives
#Returns
#   (1)the average turn around, (2)a list of each process turn around times
# processCompletionTimes = CompletionTime Object
# processArrivalTimes = 
def AverageTurnaround(processCompletionTimes, processArrivalTimes):
    avgTurnAroundTime = 0
    tatList = []
    for i in range(len(processCompletionTimes)):
        avgTurnAroundTime += processCompletionTimes[i] - processArrivalTimes[i]
        tatList.append(processCompletionTimes[i] - processArrivalTimes[i])


    avgTurnAroundTime /= len(processCompletionTimes)

    return avgTurnAroundTime, tatList

#Parameters
#   accepts the list of process turnaround times that is returned by AverageTurnaround, accepts the burst time of each process
#Returns
#   Average Wait
def averageWait(processTurnAroundTimes, processBurstTime):
    avgWait = 0
    for i in range(len(processTurnAroundTimes)):
        avgWait += processTurnAroundTimes[i] - processBurstTime[i]
    avgWait /= len(processTurnAroundTimes)
    return avgWait

#Parameters
#   Accepts all batchfile data opened in main
#Returns
#   (1) a list (or other data structure) of the time each process is completed at, and (2) a list (or other data structure) 
#   containing the PID of the processes in the order the algorithm sorted them by.
def firstComeFirstServedSort(batchFileData):
    dataTuple = []
    compTimes = []
    pidOrder = []
    arrivalTimes = []
    burstTimes = []
    
    for i in range(len(batchFileData)):
        dataTuple.append(tuple(batchFileData[i]))
    dataTuple.sort(key = lambda x: x[0])
    dataTuple.sort(key = lambda x: x[1])

    #Setting the completion time data structure
    num = 0
    for i in range(len(dataTuple)):
        compTimes.append(num + dataTuple[i][2])
        num += dataTuple[i][2]
        pidOrder.append(dataTuple[i][0])
        arrivalTimes.append(dataTuple[i][1])
        burstTimes.append(dataTuple[i][2])
        
    #for i in range(len(compTimes)):
    #    print(compTimes[i].pid, compTimes[i].completionTime)
    
    return compTimes, pidOrder, arrivalTimes, burstTimes


#Parameters
#   Accepts all batchfile data opened in main
#Returns
#   (1) a list (or other data structure) of the time each process is completed at, and (2) a list (or other data structure) 
#   containing the PID of the processes in the order the algorithm sorted them by.
def shortestJobFirst(batchFileData):
    index = 0
    maxRunTime = 0
 
    availableProcessesQueue = []
    
    finalPidOrder = []
 
    completionTimes = [0] * 20
    
    #Sorting by pid then arrival time
    batchFileData.sort(key = lambda x: x[0])
    batchFileData.sort(key = lambda x: x[1])

    #setting current process (first arrived process)
    #currProcess = batchFileData[0]

    #sum of run times
    for i in range(len(batchFileData)):
        maxRunTime += batchFileData[i][2]

    finalCompTimes = [0] * maxRunTime

    #looping from 0 to sum of all run times
    for i in range(maxRunTime):
        #Getting available processes to run
        for x in range(len(batchFileData)):
            if (i == batchFileData[x][1]):
                availableProcessesQueue.append(batchFileData[x])

        completionTimes[index] = i
        #sort available processes by BURST TIME
        availableProcessesQueue.sort(key = lambda x: x[2])

        if i == 0 :
            finalPidOrder.append(availableProcessesQueue[0][0])

        if (availableProcessesQueue[0][2] > 0):
            availableProcessesQueue[0][2] -= 1
            finalCompTimes[availableProcessesQueue[0][0]] += 1

        else:
            index += 1
            finalPidOrder.append(availableProcessesQueue[0][0])
            #completionTimes.append(i)
            del availableProcessesQueue[0]
        
        #print(i, availableProcessesQueue)
    #completionTimes.append(maxRunTime)
    finalPidOrder.append(availableProcessesQueue[0][0])

    
    completionTimes = list(filter(lambda num: num != 0, completionTimes))
    
    #print(completionTimes)
    #print(finalPidOrder)

    return finalPidOrder, completionTimes

#Parameters
#   Accepts all batchfile data opened in main
#Returns
#   (1) a list (or other data structure) of the time each process is completed at, and (2) a list (or other data structure) 
#   containing the PID of the processes in the order the algorithm sorted them by.
def prioritySort(batchFileData):
    dataTuple = []
    compTimes = []
    pidOrder = []
    arrivalTimes = []
    burstTimes = []
    
    for i in range(len(batchFileData)):
        dataTuple.append(tuple(batchFileData[i]))
    dataTuple.sort(key = lambda x: x[0])
    dataTuple.sort(key = lambda x: x[3])

    #Setting the completion time data structure
    num = 0
    for i in range(len(dataTuple)):
        compTimes.append(num + dataTuple[i][2])
        num += dataTuple[i][2]
        pidOrder.append(dataTuple[i][0])
        arrivalTimes.append(dataTuple[i][1])
        burstTimes.append(dataTuple[i][2])

    return compTimes, pidOrder, arrivalTimes, burstTimes

#MAINNNN
def main():
    if len(sys.argv) != 3:
        print("\nERROR: Please enter the correct amount of arguments\n")
        sys.exit()
    
    if os.path.exists(sys.argv[1]) is False:
        print("\nERROR: File doesnt Exist\n")
        sys.exit()

    batchFileObj = open(sys.argv[1], "r")
    #if batchObj == NULL:
    #    print(batchObj.read())

    processSort = sys.argv[2]

    batchArr = batchFileObj.readlines()
    
    #turning list of strings into list of ints
    for i in range(len(batchArr)):
        batchArr[i] = batchArr[i].replace('\n', '')
        batchArr[i] = batchArr[i].split(', ')
        
        for j in range(len(batchArr[i])):
            batchArr[i][j] = int(batchArr[i][j])
    
    #Process Sort
    if processSort == "FCFS":
        print("PID ORDER OF EXECUTION\n")
        compTimes, pidOrder, arrivalTimes, burstTimes = firstComeFirstServedSort(batchArr)
        for x in range(len(pidOrder)):
            print(pidOrder[x])
        print()
        tatAvg, tatList = AverageTurnaround(compTimes, arrivalTimes)
        print("Average Process Turnaround Time: ", tatAvg)
        waitAvg = averageWait(tatList, burstTimes)
        print("Average Process Wait Time: ", waitAvg, "\n")

    #ShortestFirst
    elif processSort == "ShortestFirst":
        print("PID ORDER OF EXECUTION\n")
        pidOrder, compTimes = shortestJobFirst(batchArr)
        arrivalTimes = []
        burstTimes = []
        for i in range(len(batchArr)):
            arrivalTimes.append(batchArr[i][1])
            burstTimes.append(batchArr[i][2])
        for x in range(len(pidOrder)):
            print(pidOrder[x])
        print()
        tatAvg, tatList = AverageTurnaround(compTimes, arrivalTimes)
        print("Average Process Turnaround Time (Not working with SJF Sort): ", tatAvg)
        waitAvg = averageWait(tatList, burstTimes)
        print("Average Process Wait Time (Not working with SJF Sort): ", waitAvg, "\n")
    #Priority
    elif processSort == "Priority":
        print("PID ORDER OF EXECUTION\n")
        compTimes, pidOrder, arrivalTimes, burstTimes = prioritySort(batchArr)
        for x in range(len(pidOrder)):
            print(pidOrder[x])
        print()
        tatAvg, tatList = AverageTurnaround(compTimes, arrivalTimes)
        print("Average Process Turnaround Time: ", tatAvg)
        waitAvg = averageWait(tatList, burstTimes)
        print("Average Process Wait Time: ", waitAvg, "\n")

    else:
        print("\nERROR: Your process scheduling options are FCFS, ShortestFirst, or Priority\n")
        print("Exiting Program\n")
        sys.exit()
    batchFileObj.close()

if __name__ == "__main__":
    main()


