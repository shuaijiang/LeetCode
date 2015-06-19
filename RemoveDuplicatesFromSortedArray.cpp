/*
*Remove Duplicates from Sorted Array 
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
    	if(nums.size()==0)
    		return 0;
        vector<int> nums1;
        vector<int>::iterator iter,iter1;
        int last_num;
        int total_num = 0;
		for(iter=nums.begin();iter<nums.end();++iter) {
			nums1.push_back(*iter);
		}
		iter = nums.begin();
		last_num = *iter;
		iter ++;
		total_num ++;
		for(iter1=nums1.begin();iter1<nums1.end();++iter1){
			if(*iter1 != last_num){
				last_num = *iter1;
				*iter = last_num;
				iter ++;
				total_num ++;
			}
		}
		return total_num;
    }
};
// The code under blow is used for test
int main() {
	vector<int> nums;
	vector<int>::iterator iter;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	
	Solution s;
	int total_num = s.removeDuplicates(nums);
	cout<<"total_num="<<total_num<<endl;
	for(iter=nums.begin();iter<nums.end();++iter){
		cout<<*iter<<endl;
	}
	system("pause");
	return 0;
}
