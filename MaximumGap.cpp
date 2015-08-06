/*
*Maximum Gap
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
		int size = nums.size();
		if(size < 2)
			return 0;
		sort(nums.begin(),nums.end());
		int maxGap = 0;
		for(int i=1;i<size;i++){
			if(nums[i]-nums[i-1] > maxGap)
				maxGap = nums[i]-nums[i-1];
		}
		return maxGap;
    }
};
