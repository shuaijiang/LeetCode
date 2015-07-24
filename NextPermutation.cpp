/*
*Next Permutation
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
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        if(size<=1)
        	return;
        int indexBegin=-1, indexLarge; 
		for(int i=size-1;i>0;i--){
        	if(nums[i]>nums[i-1]){
        		indexBegin = i;
        		break;
        	}	
        }
        if(indexBegin == -1){
        	sort(nums.begin(),nums.end());
        	return;
        }
        int minNum = nums[indexBegin];
        indexLarge = indexBegin;
        for(int i=indexBegin;i<size;i++){
        	if(nums[i]>nums[indexBegin-1] && nums[i]<=minNum){
        		minNum = nums[i];
				indexLarge = i;
        	}
        }
		int temp = nums[indexBegin-1];
		nums[indexBegin-1] = nums[indexLarge];
		nums[indexLarge] = temp;
		
		sort(nums.begin()+indexBegin,nums.end());
		return;
    }
};
//The code under below is used for test
int main(){
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	
	s.nextPermutation(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<endl;
	}
	system("pause");
	return 0;
}
