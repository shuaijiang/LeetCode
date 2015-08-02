/*
*Jump Game 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1)
        	return true;
        vector<bool> path(size,false);
        path[0] = true;
        int currIndex = 0;
        int nextIndex = nums[0];
        while(currIndex <= nextIndex && currIndex < size){
        	int temp = nextIndex;
			for(int j=currIndex;j<=nextIndex && j<size;j++){
				path[j] = true;
				if(nums[j] + j > nextIndex){			
					nextIndex = nums[j] + j;
				}		
			}
			currIndex = temp + 1;
        }
        return path[size-1];
    }
};
