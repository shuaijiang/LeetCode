/*
*Single Number
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
    int singleNumber(vector<int>& nums) {
    	if(nums.size() <= 0)
    		return 0;
        map<int,int> nums_map;
        map<int,int>::iterator mapIter;
        vector<int>::iterator iter;
        for(iter=nums.begin();iter<nums.end();++iter){
        	int num = *iter;
        	if(nums_map.find(num) == nums_map.end())
        		nums_map[num] = 1;
        	else
        		nums_map[num] += 1;
        }
        for(mapIter=nums_map.begin();mapIter!=nums_map.end();++mapIter){
        	if(mapIter->second == 1)
        		return mapIter->first;
        }
        
    }
};
