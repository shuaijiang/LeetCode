/*
*Unique Binary Search Trees
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>

class Solution {
public:
    int numTrees(int n) {
        vector<int> nums; 
        nums.push_back(1);
        for(int i=1;i<=n;i++){
        	nums.push_back(0);
        	if(i<=2)
        		nums[i] = i;
        	else{
        		for(int j=1;j<=i;j++){
        			nums[i] += nums[j-1]*nums[i-j];
        		}
        	}
        }
        return nums[n];
    }
};
