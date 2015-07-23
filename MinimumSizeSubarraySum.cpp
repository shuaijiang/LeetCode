/*
*Minimum Size Subarray Sum 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int size = nums.size();
    	int begin=0;
    	if(size<=0)
    		return 0;
    	int len = 1, minLen = size, totalNum = nums[0];
    	int i = 1;
    	while(totalNum < s && i < size){
			totalNum += nums[i];
			i ++;
			len ++;
		}
		if(totalNum < s)
			return 0;
		i--;
		do{
			while(totalNum > s){
				totalNum -= nums[begin];
				len --;
				begin ++;
			}
			if(totalNum < s && begin >= 1){
				begin --;
				totalNum += nums[begin];
				len ++;
			}
			if(len < minLen)
				minLen = len;
				
    		i++;
    		if(i<size){
    			totalNum += nums[i];
    			len ++;
    		}    		
    	}while(i<size);
    	
    	if(totalNum < s)
    		return 0;
    	else
    		return minLen;
    }
};
// the code under below is used for test
int main(){
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(4);
	
	int result = s.minSubArrayLen(4,nums);
	cout<<"result="<<result<<endl;
	system("pause");
	return 0;
}
