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

void printVector(vector<int> a){
	for(int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
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

	//Need improved, write the output in a file.
	int sum;
	vector<int> subarray;
	Algorithm_1 algo_1;
	Algorithm_2 algo_2;
	Algorithms &algo = algo_1;
	for(int i = 0; i < rows.size(); i++){
		printVector(rows[i]);
		sum = algo.algorithm(rows[i], subarray);
		printVector(subarray);
		cout << "Max sum: " << sum << endl;
		cout << endl;
	}

	return 0;
}
