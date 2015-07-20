/*
*Combinations   
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        if(k<=0)
        	return result;
        vector<int> nums;
        vector<int> res;
        for(int i=1;i<=n;i++)
        	nums.push_back(i);
        getCombine(nums,res,0,k);
        return result;
    }
    void getCombine(vector<int> &nums, vector<int> res, int start, int k){
    	if(k == 1){
    		for(int i=start;i<nums.size();i++){
    			res.push_back(nums[i]);
    			result.push_back(res);
    			res.pop_back();
    		}
    	}
    	for(int i=start;i<nums.size();i++){
    		res.push_back(nums[i]);
    		getCombine(nums,res,i+1,k-1);
    		res.pop_back();
    	}
    }
}; 
