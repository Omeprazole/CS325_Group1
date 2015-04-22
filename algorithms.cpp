/******************************************************************************
Apply 4 algorithms
Input an array, output the subarray with a maximum sum along with the sum
******************************************************************************/
//Need impreved, using virtual funciton
#include "algorithms.h"

void  Algorithms::set_subarray(vector<int> nums, vector<int> &subarray, int start_idx, int end_idx){
  subarray.clear();
  for(int j = start_idx; j <= end_idx; j++){
    subarray.push_back(nums[j]);
  }
}

//Algorithm 1: Enumeration
//Ianni's attempt
int Algorithm_1::algorithm(vector<int> nums, vector<int> &subarray){
  max_sum = 0;
  for(int i = 0; i < nums.size(); i++){
    for(int j = i; j < nums.size(); j++){
      sum = 0;
      for(int a = i; a <= j; a++) {
	//Ni: Revision: i->a
	sum += nums[a];
      }
      if(sum > max_sum){
	max_sum = sum;
	start_idx = i;
	end_idx = j;
      }
    }
  }

  Algorithms::set_subarray(nums, subarray, start_idx, end_idx);

  return max_sum;
}

//Algorithm 2: Better Enumeration
int Algorithm_2::algorithm(vector<int> nums, vector<int> &subarray){
  max_sum = 0;
  for(int i = 0; i < nums.size(); i++){
    sum = 0;
    for(int j = i; j < nums.size(); j++){
      sum += nums[j];
      if(sum > max_sum){
	max_sum = sum;
	start_idx = i;
	end_idx = j;
      }
    }
  }
  Algorithms::set_subarray(nums, subarray, start_idx, end_idx);
  return max_sum;
}
/*
//Algorithm 3: Divide and conquer
int Algorithm_3::algorithm(vector<int> nums, vector<int> &subarray){

}

//Algorithm 4: Linear-time
int Algorithm_4::algorithm(vector<int> nums, vector<int> &subarray){

}*/
