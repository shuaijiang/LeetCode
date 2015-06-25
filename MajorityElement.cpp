/*
*Majority Element 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<math.h>
#include<vector>
#include<map>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	if(nums.size() == 0)
    		return 0;
        map<int,int> myMap;
        map<int,int>::iterator mapIter;
        
        vector<int>::iterator iter;
        int n = 0;
        for(iter=nums.begin();iter<nums.end();++iter){
        	if(myMap.find(*iter) == myMap.end())
        		myMap[*iter] = 1;
        	else
        		myMap[*iter] += 1;    		
        }
        n = nums.size()/2;
        int max = 0, maxCount = 0;
        mapIter=myMap.begin();
        max = mapIter->first;
        maxCount = mapIter->second; 
        for(mapIter=myMap.begin();mapIter!=myMap.end();++mapIter) {
        	if(mapIter->second >= maxCount){
        		max = mapIter->first;
        		maxCount = mapIter->second;
        	}
        }
        return max;
    }
};
