#------------------------------------------------------------------------------
#prog: Run this command with only one arugment. This program will input the 
#  array from MSS_Problems.txt file and output running results from four different 
#  algorithms into MSS_Results.txt file.

#run: Run this command with total 3 arguments, the sencond argument is for 
#  choice of alogrithm(1, 2, 3, 4). the third argument is for number of size 
#  of a random test array.
#------------------------------------------------------------------------------
default: prog run

algorithms.o: algorithms.cpp algorithms.h 
	g++ -c algorithms.cpp

prog: algorithms.o main1.cpp
	g++ algorithms.o  main1.cpp -o prog

run: algorithms.o main2.cpp
	g++ algorithms.o  main2.cpp -o run
	
clean:
	rm algorithms.o	

cleanall: clean
	rm prog
	rm run

