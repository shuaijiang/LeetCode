/*
*3Sum Closest
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int sumNum;
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if(size<=2)
        	return -1;
        sort(nums.begin(),nums.end());
        sumNum = nums[0] + nums[1] + nums[2];
        for(int i=0;i<size-2;i++){
        	if(i>0 && nums[i]==nums[i-1])
				continue;
        	twoSum(nums, i+1, size-1, nums[i], target);
        	if(sumNum == target)
        		return sumNum;
        }
        return sumNum;
    }
    void twoSum(vector<int> &nums, int start, int end, int num, int target){
    	while(start<end){
    		int oneSum = nums[start] + nums[end] + num;
    		if(oneSum == target){
    			sumNum = oneSum;
    			return;
    		}
    		if( oneSum < target ){
    			if(abs(oneSum - target) < abs(sumNum - target))
					sumNum = oneSum;
    			start ++;
    		}
    		else
			{
				if(abs(oneSum - target) < abs(sumNum - target))
					sumNum = oneSum;
    			end --;
    		}
    	}
		return ;
    }
};
