/*Maximum Subarray 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<map>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<=0)
        	return 0;
		int maxSum=nums[0], sum=nums[0];
        for(int i=1;i<nums.size();i++){
        	if(sum < 0)
        		sum = 0;
        	sum += nums[i];
        	maxSum = max(maxSum, sum);
        }
        return maxSum; 
    }
};
