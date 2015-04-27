#------------------------------------------------------------------------------
#prog: Run this command with no arugments. This program will input the
#  array from MSS_Problems.txt file and output running results from four different
#  algorithms into MSS_Results.txt file.

#run: Run this command with total two arguments, the first argument is for
#  choice of alogrithm(1, 2, 3, 4). the second argument is for the of size
#  of the random test array.
#------------------------------------------------------------------------------
all: prog run

algorithms.o: algorithms.cpp algorithms.h 
	g++ -c algorithms.cpp

prog: algorithms.o main1.cpp
	g++ algorithms.o  main1.cpp -o prog

run: algorithms.o main2.cpp
	g++ algorithms.o  main2.cpp -o run

clean:
	rm algorithms.o	
	rm prog
	rm run

