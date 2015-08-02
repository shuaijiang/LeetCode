/*
*Maximum Product Subarray 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(size <= 0)
        	return 0;
		if(size == 1)
        	return nums[0];
        int maxNum = nums[0];
        int minNum = nums[0];
        int maxRes = nums[0];
        for(int i=1;i<size;i++){
        	int num1 = nums[i] * maxNum;
        	int num2 = nums[i] * minNum;
			maxNum = max(max(num1,num2),nums[i]);
			minNum = min(min(num1,num2),nums[i]);
			maxRes = max(maxRes, maxNum);
        }
        return maxRes;
    }
};
