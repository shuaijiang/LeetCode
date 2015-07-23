/*
*Sliding Window Maximum 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> result;
        int maxNum;
        
        if(size<=0)
        	return result;
        if(k==1)
        	return nums;
        
        maxNum = maxArray(nums, 0, k-1);
        result.push_back(maxNum);
        
		for(int i=k;i<size;i++){
        	maxNum = maxArray(nums, i-k+1, i);
        	result.push_back(maxNum);
        }
        return result;
    }
    int maxArray(vector<int>& nums, int start, int end){
    	int maxNum = nums[start];
		for(int i = start+1;i<=end;i++){
			if(nums[i] > maxNum)
				maxNum = nums[i];
		}
		return maxNum;
    }
};
