/*
*3Sum
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
		if(size <= 2)
			return result;
		sort(nums.begin(),nums.end());
		for(int i=0;i<size-2;i++)
		{
			if(i>0 && nums[i]==nums[i-1])
				continue;
			twoSum(nums, i+1,size-1, nums[i]);
		}
		return result;
    }
    void twoSum(vector<int> &nums, int start, int end, int target){
    	vector<int> oneSet;
    	
    	while(start<end){
    		if(nums[start]+nums[end]+target == 0){
    			oneSet.push_back(target);
				oneSet.push_back(nums[start]);
    			oneSet.push_back(nums[end]);
    			result.push_back(oneSet);
    			oneSet.clear();
    			while(start<end && nums[start]==nums[start+1]) start++;
    			while(start<end && nums[end]==nums[end-1]) end--;
    			start ++;
    			end --;
    		}
    		else if(nums[start]+nums[end]+target < 0)
    			start ++;
    		else
    			end--;
    	}
		return ;
    }
};
