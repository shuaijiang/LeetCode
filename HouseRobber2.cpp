/*
*House Robber
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	int size = nums.size();
    	if(size <= 0)
    		return 0;
    	if(size == 1)
    		return nums[0];    	
    	if(size == 2)
    		return max(nums[0], nums[1]);
    	
    	vector<int> money = vector<int>(size, 0);
    	vector<int> index = vector<int>(size, 0);
    	//Dynamic programming
    	money[0] = nums[0];
    	index[0] = 1;
    	money[1] = max(nums[0],nums[1]);
    	if(nums[0] > nums[1])
    		index[1] = 1;
    	else
    		index[1] = 0;
    	for(int count=2;count<size;++count){
    		money[count] = max(money[count-1],money[count-2]+nums[count]);    		
    		if( money[count-1] >= money[count-2]+nums[count] ){
				if(count == size-1)
					return money[count];
				index[count] = index[count-1];
			} 
    		else
    			index[count] = index[count-2];
    	}
    	if(index[size-1] == 0)
    		return money[size-1];
    	//The result without the last one 
		int max1 = money[size-2];
    	
    	money[1] = nums[1];
    	money[2] = max(nums[1],nums[2]);
    	//Compute the result without the first one
		for(int count=3;count<size;++count){
    		money[count] = max(money[count-1],money[count-2]+nums[count]);    		
    	}
    	//return the max of the two results
    	return max(money[size-1], max1);
    }
};
