/*
*Permutations 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
		if(nums.size() <= 0)
			return result;
        findResult(nums, 0, result);
        return result;
    }
    void findResult(vector<int>& nums, int i, vector<vector<int>> &result){
    	int size = nums.size();
		if(i == size-1){
			result.push_back(nums);
			return;
		}
		for(int j=i;j<nums.size();j++){
    		int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			
			findResult(nums, i+1, result);
			
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
    	}
    }
};
