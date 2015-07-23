/*
*Longest Consecutive Sequence 
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
    int longestConsecutive(vector<int>& nums) {
    	int longestNum = 0, num;
    	int size = nums.size();
		if(size<=0)
	   		return longestNum;
	   	if(size == 1)
	   		return 1;
		sort(nums.begin(),nums.end());
		
		longestNum = 1;
		num = 1;
		for(int i=1;i<size;i++){
			if(nums[i]-nums[i-1] == 0)
				;
			else if(nums[i]-nums[i-1] == 1)
				num ++;
			else
				num = 1;
			if(num > longestNum)
				longestNum = num;
		}
		return longestNum;
    }
};
// the code under below is used for test
int main(){
	Solution s;
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(-1);
	
	int num = s.longestConsecutive(nums);
	cout<<"num="<<num<<endl;
	system("pause");
	return 0;
}
