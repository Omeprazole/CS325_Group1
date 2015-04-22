/******************************************************************************
Apply 4 algorithms
Input an array, output the subarray with a maximum sum along with the sum
******************************************************************************/
//Need impreved, using virtual funciton
#include "algorithms.h"

//Algorithm 1: Enumeration
//need improved,this is better enumeration
//int algorithm_1(vector<int> nums, vector<int> &subarray){
//	int sum, max_sum = 0; 
//	int start_idx, end_idx;
//	for(int i = 0; i < nums.size(); i++){
//		sum = 0;
//		for(int j = i; j < nums.size(); j++){
//			sum += nums[j]; 
//			if(sum > max_sum){
//				max_sum = sum;
//				start_idx = i;
//				end_idx = j;
//			}
//		}
//	}
//	subarray.clear();
//	for(int j = start_idx; j <= end_idx; j++){
//		subarray.push_back(nums[j]);
//	}
//	return max_sum;
//}
//

//Algorithm 1: Enumeration
//Ianni's attempt
int algorithm_1(vector<int> nums, vector<int> &subarray){
  int sum, max_sum = 0; 
  int start_idx, end_idx;
  for(int i = 0; i < nums.size(); i++){
    for(int j = i; j < nums.size(); j++){
      sum = 0;
      for(int a = i a <= j; a++) {
	sum += nums[j];
      }
      if(sum > max_sum){
	max_sum = sum;
	start_idx = i;
	end_idx = j;
      }
    }
  }
  subarray.clear();
  for(int j = start_idx; j <= end_idx; j++){
    subarray.push_back(nums[j]);
  }
  return max_sum;
}

//Algorithm 2: Better Enumeration
int algorithm_2(vector<int> nums, vector<int> &subarray){
  int sum, max_sum = 0;    
  int start_idx, end_idx;
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
  subarray.clear();
  for(int j = start_idx; j <= end_idx; j++){
    subarray.push_back(nums[j]);
  }
  return max_sum;
}

//Algorithm 3: Divide and conquer
int algorithm_3(vector<int> nums, vector<int> &subarray){

}

//Algorithm 4: Linear-time
int algorithm_4(vector<int> nums, vector<int> &subarray){

}
