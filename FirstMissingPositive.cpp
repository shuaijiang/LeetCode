/*
*First Missing Positive 
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
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        bool positive = false;
		sort(nums.begin(),nums.end());
        for(int i=0;i<size;i++){
			if(positive){
				if(nums[i]-nums[i-1] > 1)
					return nums[i-1] + 1;
			}
			else{
				if(nums[i]>0)
					positive = true;
				if(nums[i]>1)
					return 1;
			}
		}
		if(positive)
			return nums[size-1]+1;
		return 1;
    }
};
