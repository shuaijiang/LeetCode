/*
*Search in Rotated Sorted Array II
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<map>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
    	int size = nums.size();
    	if(size <= 0)
    		return false;
		
		sort(nums.begin(),nums.end());
		
		int start, end, middle;
		start = 0; 
		end = size-1;
		
		while(start <= end){
			middle = (start+end) / 2;
			if(nums[middle] == target){
				return true;
			}	
			else if(nums[middle] > target)
				end = middle - 1;
			else
				start = middle + 1;
		}
		return false;
    }
};
