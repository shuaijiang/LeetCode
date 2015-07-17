/*
*Remove Duplicates from Sorted Array 2
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int size = nums.size();
		if(size <= 2)
    		return size;
		vector<int> result;
        int lastNum = nums[0];
        int totalNum = 1;
        int repeatNum = 0;
        
        result.push_back(nums[0]);
        for(int i=1;i<size;i++){
        	if(nums[i] == lastNum){
        		repeatNum ++;
        		if(repeatNum <= 1){
        			result.push_back(nums[i]);
        			totalNum ++;
        		}
        	}
        	else{
        		repeatNum = 0;
        		lastNum = nums[i];
        		result.push_back(nums[i]);
				totalNum ++;
        	}
        }
        nums =  result;
        return totalNum;
    }
};
// The code under blow is used for test
int main() {
	vector<int> nums;
	vector<int>::iterator iter;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	//nums.push_back(1);
	
	Solution s;
	int total_num = s.removeDuplicates(nums);
	cout<<"total_num="<<total_num<<endl;
	for(iter=nums.begin();iter<nums.end();++iter){
		cout<<*iter<<endl;
	}
	system("pause");
	return 0;
}

