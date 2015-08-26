/*
*Missing Number 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = size * (1 + size) / 2;
        int total = 0;
        for(int i=0;i<size;i++){
        	total += nums[i];
        }
        return sum-total;
    }
};
