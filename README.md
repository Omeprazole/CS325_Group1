#To use the makefile type "make all" to compile both executables: prog and run. You can also use "make prog" and "make run".

#prog: Run this command with no arugments. This program will input the
#  array from MSS_Problems.txt file and output running results from four different
#  algorithms into MSS_Results.txt file.

#run: Run this command with total two arguments, the first argument is for
#  choice of alogrithm(1, 2, 3, 4). the second argument is for the of size
#  of the random test array.

There are 7 files in our program:

algorithms.cpp & algorithms.h: 
	Apply 4 algorithms to find the max sum subarray

main1.cpp:
	Read input from MSS_Problems.txt file, output all four algorithms on all
	arrays to MSS_Results.txt file.

main2.cpp:
        1, Generate 10 different vectors of size n.
        2, For each vector,run the algorithm you choose.
        3, Record and print out the average time of running the algorithm.

makefile:
	prog: Run this command with no arugment. This command will run main1.cpp 
	algorithms.cpp, and will input the array from MSS_Problems.txt file and output 
	running results from four different algorithms into MSS_Results.txt file.

	run: Run this command with total two arguments, the first argument is for 
	choice of alogrithm(1, 2, 3, 4). the second argument is for number of size 
	of a random test array. This command will run main2.cpp and algorithms.cpp

MSS_Problems.txt:
	A set of arrays for input and test.

MSS_Results.txt:
	Create by the program, and will output the result in this file.
