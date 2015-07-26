/*
*4Sum
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> result;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
		if(size <= 3)
			return result;
		sort(nums.begin(),nums.end());
		for(int i=0;i<size-3;i++)
		{
			if(i>0 && nums[i]==nums[i-1] )
				continue;
			for(int j=i+1;j<size-2;j++){
				if(j>i+1 && nums[j]==nums[j-1] )
					continue;
				twoSum(nums, j+1, size-1, nums[i], nums[j], target);
			}
		}
		return result;
    }
    void twoSum(vector<int> &nums, int start, int end, int num1, int num2, int target){
    	vector<int> oneSet;
    	
    	while(start<end){
    		if(nums[start]+nums[end] + num1 + num2 == target){
    			oneSet.push_back(num1);
    			oneSet.push_back(num2);
				oneSet.push_back(nums[start]);
    			oneSet.push_back(nums[end]);
    			result.push_back(oneSet);
    			oneSet.clear();
    			while(start<end && nums[start]==nums[start+1]) start++;
    			while(start<end && nums[end]==nums[end-1]) end--;
    			start ++;
    			end --;
    		}
    		else if(nums[start]+nums[end] + num1 + num2 < target)
    			start ++;
    		else
    			end--;
    	}
		return ;
    }
};
