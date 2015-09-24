/*
*Move Zeroes
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int end=size-1;

		for(int i=0;i<end;i++){
			if(nums[i] != 0){
				continue;
			}
			else{
				for(int j=i;j<end;j++){
					nums[j]=nums[j+1];
				}
				nums[end]=0;
				end --;
				i--; //the numbers after zero move one step to the front, so the index i need one step move
			}
		}
    }
};

int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(1);
	//nums.push_back(3);
	
	s.moveZeroes(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<endl;
	}
	system("pause");
	return 0;
}
