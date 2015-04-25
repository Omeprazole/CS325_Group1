/******************************************************************************
Read input from MSS_Problems.txt file, output all four algorithms on all
arrays to MSS_Results.txt file.
******************************************************************************/
#include "algorithms.h"
#include <fstream>		
#include <iostream>		
#include <vector>
#include <cstring>
#include <cstdio>		//printf
#include <stdlib.h>		//atoi
using namespace std;

//src:http://www.oopweb.com/CPP/Documents/CPPHOWTO/Volume/C++Programming-HOWTO-7.html
void Tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

int main(int argc, char* argv[]) {	
        //Check the number of argument
        if( argc != 1 ){
                cout << "Error, please input only one argument." << endl;
                return 0;
        }

	ifstream the_file;
	//Open the file MSS_Problems.txt
	the_file.open("./MSS_Problems.txt");

	//reading the file and convert each line into an array
	if(!the_file.is_open()){
        	cout << "Unable to open file." << endl;
		return -1;
	}

	string line;
	vector<vector<int> > rows;
	//line represent all characters in a line, which is cstring
	while(getline(the_file,line)){
		vector<string> row;
		vector<int> nums;
		Tokenize(line, row, " [],");
		for (int i=0; i<row.size();i++) {
			nums.push_back(atoi(row[i].c_str()));
		}
		rows.push_back(nums);
	}
	the_file.close();

	ofstream output_file;
	output_file.open("MSS_Results.txt");
	
	//Check if "MSS_Results.txt" file is open
	if(!output_file.is_open()){
        	cout << "Unable to open file." << endl;
		return -1;
	}

	//output the results in the file "MSS_Results.txt".
	int sum;
	vector<int> subarray;
	Algorithm_1 algo_1;
	Algorithm_2 algo_2;
	Algorithm_3 algo_3;
	Algorithm_4 algo_4;

	//Output each algorithm's result
	for(int a = 1; a < 5; a++ ){	
		output_file << "Algorithm " <<  a <<" Result:" << endl;
		for(int i = 0; i < rows.size(); i++){

			//Output original array
			output_file << "Original Array : ";
			for(int j = 0; j < rows[i].size(); j++){
				output_file << rows[i][j];
				if(j != rows[i].size() - 1)
				output_file << ", ";
			}

			//Iterator each algorithm
			if(a == 1)
				sum = algo_1.algorithm(rows[i], subarray);
			if(a == 2)
				sum = algo_2.algorithm(rows[i], subarray);
			if(a == 3)
				sum = algo_3.algorithm(rows[i], subarray);
			if(a == 4)
				sum = algo_4.algorithm(rows[i], subarray);

			//Output the subarray
			output_file << "\nSubarray ";
			for(int k = 0; k < subarray.size(); k++){
				output_file << subarray[k];
				if(k != subarray.size() - 1)
					output_file << ", ";
			}

			//Output sum.
			output_file << "\nMax sum: " << sum << endl;
			output_file << endl;
		}
		output_file << endl;
	}
	output_file.close();
	return 0;
}
