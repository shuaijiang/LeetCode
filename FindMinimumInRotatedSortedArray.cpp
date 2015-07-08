/*Find Minimum in Rotated Sorted Array
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
    	if(nums.size()==0)
    		return 0;
    	if(nums.size()==1)
    		return nums[0];
        for(int i=1;i<nums.size();i++){
        	if(nums[i-1]>nums[i])
        		return nums[i];
        }
        return nums[0];
    }
};
