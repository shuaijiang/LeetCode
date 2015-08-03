/*
*Jump Game II
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int step = 0;
        if(size <= 1)
        	return step;
        
        int currIndex = 0;
        int nextIndex = nums[0];
        while(currIndex <= nextIndex && currIndex < size){
        	int temp = nextIndex;
			for(int j=currIndex;j<=temp && j<size;j++){
				if(nums[j] + j > nextIndex){		
					nextIndex = nums[j] + j;
				}	
			}
			step ++;
			currIndex = temp + 1;
        }
        return step;
    }
};

int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	
	int result = s.jump(nums);
	cout<<"result="<<result<<endl;
	system("pause");
	return 0;
}

