/******************************************************************************
Command line insturction: 
	argument 1: choice of alogrithm(1, 2, 3, 4).
	argument 2: number of size n.
Description:
	1, Generate 10 different vectors of size n.
	2, For each vector,run the algorithm you choose. 
	3, Record and print out the average time of running the algorithm.
******************************************************************************/
#include "algorithms.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

/*Function to get number of milliseconds elapsed since program started execution*/
double getMilliseconds() {
	return 1000.0 * clock() / CLOCKS_PER_SEC;
}

//Generate a 2-dimensional vector, with random numbers
//which contains 10 vectors of a size 
void generateVector(const int size, vector<vector<int> > &rand_vec){
	vector<int> vec;
	srand(time(NULL));

	//Generate 10 random vectors	
	for(int i = 0; i < 10; i++){
		vec.clear();
		for(int j = 0; j < size; j++){
			//The range of each number is from -99 to 100 
			vec.push_back(rand()%200 - 99);
		}

		//Make sure the vector has at least one positive element
		if(vec[rand()%size] <= 0)
			vec[rand()%size] = -vec[rand()%size] + 1;

		rand_vec.push_back(vec);
	}
}


int main(int argc, char* argv[]) {	
	int choice, size;
	double t1, t2;
	const int REPEAT = 10;


	//Check the number of argument
	if( argc != 3 ){
		cout << "Error, please input right number of arguments." << endl;
		cout << "Argument 2: choice of alogrithm(1, 2, 3, 4)." << endl;
                cout << "Argument 3: number of size n" << endl;
		
		return 0;
	}
	
        Algorithm_1 algo_1;
        Algorithm_2 algo_2;
        Algorithm_3 algo_3;
        Algorithm_4 algo_4;
	choice = atoi(argv[1]);
	size = atoi(argv[2]);
	vector<vector<int> > test_vec;
	vector<int> subarray;
	generateVector(size, test_vec);

	//Run ten times on specific algorithm
	t1 = getMilliseconds();
	
	for(int i=0; i < test_vec.size(); i++) {
        	switch(choice){
                case 1:{
			algo_1.algorithm(test_vec[i], subarray);
		}
		break;
		case 2:{
			algo_2.algorithm(test_vec[i], subarray);
		}
			break;
                case 3:{
			algo_3.algorithm(test_vec[i], subarray);
		}
			break;
                case 4:{
			algo_4.algorithm(test_vec[i], subarray);
		}
			break;
                default:
                        cout << "Error, invalid algorithm choice." << endl;
        	}
		
	}	
	
	t2 = getMilliseconds();

	//Print out result
	printf("Time for running algorithm %d on %d elements: %g ms\n", choice, size, (t2 - t1) / 10);
  
	return 0;
}
