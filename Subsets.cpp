/*
*Subsets 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> result;
        if(nums.size()<=0)
        	return result;
        vector<int> vec;
        result.push_back(vec);
		for(int i=0;i<nums.size();i++){
			int resultSize = result.size();
			for(int j=0;j<resultSize;j++){
				vector<int> vec = result[j];
				vec.push_back(nums[i]);
				sort(vec.begin(),vec.end());
				result.push_back(vec);
			}
		}
		return result;
    }
};

class Solution {
public:
	vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()<=0)
        	return result;
		getSub(nums, 0);
		return result;
    }
    void getSub(vector<int>& nums, int start){
    	int size = nums.size();
    	if(start >= size){
    		vector<int> tmp;
    		result.push_back(tmp);
    		return;
    	}
    	else{
    		int num = nums[start];
    		getSub(nums, start+1);
    		for(int i=0;i<result.size();i++){
    			vector<int> res = result[i];
    			res.push_back(num);
    			//sort(res.begin(),res.end());
    			result.push_back(res);
    		}
    	}
		return; 
    }
};
