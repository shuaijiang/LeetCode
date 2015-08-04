/*
*Search in Rotated Sorted Array
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
    int search(vector<int>& nums, int target) {
    	int size = nums.size();
    	map<int,int> myMap;
    	if(size <= 0)
    		return -1;
		
		for(int i=0;i<size;i++){
			myMap[nums[i]] = i;
		}
		
		sort(nums.begin(),nums.end());
		
		int start, end, middle;
		start = 0; 
		end = size-1;
		
		while(start <= end){
			middle = (start+end) / 2;
			if(nums[middle] == target){
				return myMap[nums[middle]];
			}
				
			else if(nums[middle] > target)
				end = middle - 1;
			else
				start = middle + 1;
		}
		return -1;
    }
};
