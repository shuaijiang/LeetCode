/*
*Permutations 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int size = nums.size();
        if(size <= 1){
        	result.push_back(0);
        	return result;
        }
		vector<int> product1, product2;
		
		product1.push_back(nums[0]);
		for(int i=1;i<size;i++){
			int product = nums[i] * product1[i-1];
			product1.push_back(product);
		}
		
		product2 = product1;
		product2[size-1] = nums[size-1];
		for(int i=size-2;i>=0;i--){
			int product = nums[i]  * product2[i+1];
			product2[i] = product;
		}
				
        for(int i=0;i<size;i++){
        	int product = 0;
        	if(i==0)
        		product = product2[i+1];
        	else if(i==size-1)
        		product = product1[i-1];
        	else
				product = product1[i-1] * product2[i+1];
        	
			result.push_back(product);
        }
        return result;
    }
};
