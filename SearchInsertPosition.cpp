/*
*Search Insert Position
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/

#include<iostream>
#include<vector>
#include <unordered_set>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		if(nums.size()<=0)
        	return 0;
        int size = nums.size();
		for(int i=0;i<nums.size();i++){
			if(target <= nums[i])
				return i;
		}
		return size;
    }
};
