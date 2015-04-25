#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Algorithms{
	protected:
		int sum, max_sum;
		int start_idx, end_idx;
	public:
		void set_subarray(vector<int> nums, vector<int> &subarray, int start_idx, int end_idx);
		virtual int algorithm(vector<int> nums, vector<int> &subarray) { }
};

//Algorithm 1: Enumeration
class Algorithm_1:public Algorithms{
	public:
		int algorithm(vector<int> nums, vector<int> &subarray);
};


//Algorithm 2: Better Enumeration
class Algorithm_2: public Algorithms{
	public:
		int algorithm(vector<int> nums, vector<int> &subarray);
};

//Algorithm 3: Divide and conquer
class Algorithm_3: public Algorithms{
	public:
		int algorithm(vector<int> nums, vector<int> &subarray);
		int Algorithm_3_Helper(vector<int> &array, int low, int high, int &start_idx, int &end_idx);
};

//Algorithm 4: Linear-time
class Algorithm_4: public Algorithms{
	public:
		int algorithm(vector<int> nums, vector<int> &subarray);
};

#endif
