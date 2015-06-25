/*
*Contains Duplicate
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<map>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	if(nums.size()<=1)
    		return false;
        map<int,int> myMap;
        map<int,int>::iterator mapIter;
        for(int count=0;count<nums.size();++count){
        	if(myMap.find(nums[count])==myMap.end())
        		myMap[nums[count]] = 1;
        	else{
        		myMap[nums[count]] += 1;
        		return true;
        	}
        		
        }
        for(mapIter=myMap.begin();mapIter!=myMap.end();++mapIter){
        	if(mapIter->second > 1)
        		return true;
        }
        return false;
    }
};
