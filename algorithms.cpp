/******************************************************************************
Apply 4 algorithms
Input an array, output the subarray with a maximum sum along with the sum
******************************************************************************/
#include "algorithms.h"

void  Algorithms::set_subarray(vector<int> nums, vector<int> &subarray, int start_idx, int end_idx){
  subarray.clear();
  for(int j = start_idx; j <= end_idx; j++){
    subarray.push_back(nums[j]);
  }
}

//Algorithm 1: Enumeration
int Algorithm_1::algorithm(vector<int> nums, vector<int> &subarray){
  max_sum = 0;

  //Interate each segament in the array
  for(int i = 0; i < nums.size(); i++){
    for(int j = i; j < nums.size(); j++){
      sum = 0;
      //Get the sum from index i to j
      for(int a = i; a <= j; a++) {
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

  //Interate each segament in the array
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
  max_sum = Algorithm_3_Helper(nums, low, high, start_idx, end_idx);
  
  //Call the recursive funtion
  Algorithms::set_subarray(nums, subarray, start_idx, end_idx);
  return max_sum;
}

int Algorithm_3::Algorithm_3_Helper(vector<int> &array, int low, int high, int &start_idx, int &end_idx) {
  //Define 6 integers to track the index of max sum subarray
  int a_low, a_high, b_low, b_high, c_low, c_high;

  if (low > high) {
    start_idx = high;
    end_idx = low;
    return 0;
  }

  //Base case
  if (low == high) {
    start_idx = low;
    end_idx = high;
    return array.at(low);
  }
  int mid = (low + high)/2;

  //Divide: Calculate subarray on left side
  int lower_sum = Algorithm_3_Helper(array, low, mid, a_low, a_high);

  //Divide: Calculate subarray on right side
  int upper_sum = Algorithm_3_Helper(array, mid + 1, high, b_low, b_high);

  // Conquer: Calculate subarray crossing the middle.
  int upper_max = INT_MIN;
  int lower_max = INT_MIN;
  c_low = mid;
  c_high = mid;

  int temp_sum = 0;
  for (int i = mid; i >= low; i--) {
    temp_sum += array[i];

    if (temp_sum > lower_max) {
      lower_max = temp_sum;
      c_low = i;
    }
  }
  temp_sum = 0;
  for (int i = mid+1; i <= high; i++) {
    temp_sum += array[i];
    
    if (temp_sum > upper_max) {
      upper_max = temp_sum;
      c_high = i;
    }
  }
  int crossing_sum = lower_max + upper_max;

  // Compare the three cases, and return result.
  if(crossing_sum > max(lower_sum, upper_sum)){
    start_idx = c_low;
    end_idx = c_high;
    return crossing_sum;
  } else if(lower_sum > upper_sum){
    start_idx = a_low;
    end_idx = a_high;
    return lower_sum;
  } else {
    start_idx = b_low;
    end_idx = b_high;
    return upper_sum;
  }
}

//Algorithm 4: Linear-time
int Algorithm_4::algorithm(vector<int> nums, vector<int> &subarray){
  int cur_max = nums[0];

  //Define two variables to track the index of max sum subarray 
  int left = 0, right = 0;

  //Initialization
  max_sum = nums[0];
  start_idx = 0;
  end_idx = 0;

  //Iterator each element in the array
  for(int i = 1; i < nums.size(); i++){
    //Extend the current max to find a maximum subarray ending at index i
    if(cur_max + nums[i] < nums[i]){
      left = i;
      right = i;
      cur_max = nums[i];
    }else {
      right = i;
      cur_max += nums[i];
    }

    //Compare the previous max sum to the sum with the current element 
    if(cur_max > max_sum){
      max_sum = cur_max;
      start_idx = left;
      end_idx = right;
    }
  }
		 
  Algorithms::set_subarray(nums, subarray, start_idx, end_idx);
  return max_sum;
}
