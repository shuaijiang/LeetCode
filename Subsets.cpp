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

