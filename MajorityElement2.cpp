/*
*Majority Element II 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
    	if(size <= 1)
    		return nums;
    	if(size == 2){
    		if(nums[0] != nums[1])
    			return nums;
    		else{
    			result.push_back(nums[0]);
    			return result;
    		}
    	}
    	sort(nums.begin(),nums.end());
    	int count = 1;
		for(int i=1;i<size;i++){
    		if(nums[i] == nums[i-1]){
    			count++;
    		}
    		else{
    			if(count>size/3)
    				result.push_back(nums[i-1]);
    			count = 1;
    		}
    	}
    	if(count > size/3)
    		result.push_back(nums[size-1]);
    	return result;
    }
};
