/******************************************************************************
Apply 4 algorithms
Input an array, output the subarray with a maximum sum along with the sum
******************************************************************************/
//Need impreved, using virtual funciton
#include "algorithms.h"
#include <algorithm>

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

//Algorithm 3: Divide and conquer
int Algorithm_3::algorithm(vector<int> nums, vector<int> &subarray){
  int low = 0;
  int high = nums.size() - 1;
  return Algorithm_3_Helper(nums, low, high);
}

int Algorithm_3_Helper(vector<int> &array, int low, int high) {
  if (low > high) {
    return 0;
  }
  if (low == high) {
    return array.at(low);
  }
  int mid = (low + high)/2;
  int lower_sum = Algorithm_3_Helper(array, low, mid);
  int upper_sum = Algorithm_3_Helper(array, mid + 1, high);
  int upper_max = 0;
  int lower_max = 0;
  int temp_sum = 0;
  for (int i = mid; i >= low; i--) {
    temp_sum += array[i];
    if (temp_sum > lower_max) {
      lower_max = temp_sum;
    }
  }
  temp_sum = 0;
  for (int i = mid+1; i <= high; i++) {
    temp_sum += array[i];
    if (temp_sum > upper_max) {
      upper_max = temp_sum;
    }
  }
  int crossing_sum = lower_sum + upper_sum;
  
  return max(max(lower_sum, upper_sum), crossing_sum);
}
/*
//Algorithm 4: Linear-time
int Algorithm_4::algorithm(vector<int> nums, vector<int> &subarray){

}*/
