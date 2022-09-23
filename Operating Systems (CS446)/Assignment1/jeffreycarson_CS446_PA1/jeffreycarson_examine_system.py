# Jeffrey Carson
# CS446 Proj1 Part1
# Exploring /proc, printing certain data about ubuntu PIDs.

import sys

#CPU INFO (1)
sec1 = open("/proc/cpuinfo", "r")
procCPU = sec1.readlines()


#KERNEL VERSION DETAILS (2)
sec2 = open("/proc/version", "r")
procKernelVersion = sec2.readlines()

#TIME SINCE LAST BOOT (3)
sec3 = open("/proc/uptime", "r")
procUptime = sec3.readlines()

#THE TIME THAT THE SYSTEM WAS LAST BOOTED (4)
sec4 = open("/proc/stat", "r")
procBootTime = sec4.readlines()

#THE NUMBER OF DISK REQUESTS MADE (5)
sec5 = open("/proc/diskstats", "r")
procDisk = sec5.readlines()

#THE NUMBER OF PROCESSES SINCE LAST BOOT (6)
sec6 = open("/proc/stat", "r")
procSinBoot = sec6.readlines()


with open ('jeffreycarson_systemDetails.txt', 'w') as f:
	sys.stdout = f
	
	print("***CPU INFO /proc/cpuinfo ***\n\n")
	print(procCPU)

	print("\n\n***KERNEL VERSION DETAILS /proc/version***\n\n")
	print(procKernelVersion)

	print("\n\n***AMOUNT OF TIME SINCE LAST BOOT /proc/uptime***\n[seconds, idle time]\n\n")
	print(procUptime)
	
	print("\n\n***THE TIME THAT THE SYSTEM WAS LAST BOOTED /proc/stat***\n\n")
	print(procBootTime)
	
	print("\n\n***THE NUMBER OF DISK REQUESTS MADE /proc/diskstats***\n\n")
	print(procDisk)
	
	print("\n\n***THE NUMBER OF PROCESSES SINCE LAST BOOT /proc/stat***\n\n")
	print(procSinBoot)
	
	
	







