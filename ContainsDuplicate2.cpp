/*
*Contains Duplicate2
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	if(nums.size()<=1)
    		return false;
        map<int,int> myMap;
        map<int,int>::iterator mapIter;
        for(int count=0;count<nums.size();++count){
        	if(myMap.find(nums[count])==myMap.end())
        		myMap[nums[count]] = count;
        	else{
        		if(count - myMap[nums[count]] <= k)
        			return true;
        		else
        			myMap[nums[count]] = count;
        	}
        		
        }
        return false;
    }
};
