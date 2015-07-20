/*
*Subsets 2
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
     vector<vector<int>> subsetsWithDup(vector<int>& nums){
    	vector<vector<int>> result;
        if(nums.size()<=0)
        	return result;
        sort(nums.begin(),nums.end());
        
        vector<int> vec;
        int lastSize = 0;
        result.push_back(vec);
        vec.push_back(nums[0]);
        result.push_back(vec);
        lastSize = 1;
        
		for(int i=1;i<nums.size();i++){
			if(nums[i] != nums[i-1]){
				int resultSize = result.size();
				lastSize = resultSize;
				for(int j=0;j<resultSize;j++){
					vector<int> vec = result[j];
					vec.push_back(nums[i]);
					sort(vec.begin(),vec.end());
					result.push_back(vec);
				}
			}
			else{
				int resultSize = result.size();
				for(int j=0;j<lastSize;j++){
					vector<int> vec = result[resultSize - j - 1];
					vec.push_back(nums[i]);
					sort(vec.begin(),vec.end());
					result.push_back(vec);
				}
			}
		}
		return result;
    }
};

