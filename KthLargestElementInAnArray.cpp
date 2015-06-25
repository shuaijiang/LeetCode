/*
*Kth Largest Element in an Array 
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
    int findKthLargest(vector<int>& nums, int k) {
        int *KNum = new int[k];
        int minNum,minIndex;
        for(int i=0;i<k;i++){
        	KNum[i] = nums[i];
        }
        minIndex = minIndexOfNums(KNum,k);
        minNum   = KNum[minIndex];
        for(int i=k;i<nums.size();i++){
        	if(nums[i]>minNum){
        		KNum[minIndex] = nums[i];
        		minIndex = minIndexOfNums(KNum,k);
        		minNum   = KNum[minIndex];
        	}
        }
        return minNum;
    }
    int minIndexOfNums(int *num, int k){
    	int min = num[0];
    	int index = 0;
    	for(int count=1;count<k;count++){
    		if(num[count]<min){
    			min = num[count];
    			index = count;
    		}
    	}
    	return index;
    }
};
