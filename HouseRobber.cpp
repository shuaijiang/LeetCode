/*
*House Robber
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
    int rob(vector<int>& nums) {
    	vector<int>::iterator iter=nums.begin();
    	if(nums.size() <= 0)
    		return 0;
    	if(nums.size() == 1)
    		return *iter;
    	
    	int size = nums.size();
    	int *money = new int[size];
    	//Dynamic programming
    	money[0] = nums[0];
    	money[1] = max(nums[0],nums[1]);
    	for(int count=2;count<size;++count){
    		money[count] = max(money[count-1],money[count-2]+nums[count]);
    	}
    	return money[size-1];
    }
};
//The code under below is used for test
int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(12);
	nums.push_back(3);
	
	int maxMoney = s.rob(nums);
	cout<<"money="<<maxMoney<<endl;
	system("pause");
	return 0;
}
