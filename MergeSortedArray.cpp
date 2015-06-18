/*
*Merge Sorted Array 
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	vector<int> nums3;
        vector<int>::iterator  iter1, iter2,iter3;
        int count=0,count1=0, count2=0;
        int temp = 0;
        iter1=nums1.begin();
		for(count1=0;count1<m;count1++){
			nums3.push_back(*iter1);
			iter1++;
		}
		iter1=nums1.begin();
		iter2=nums2.begin();
		iter3=nums3.begin();
		count1=0; 
        for(;iter2<nums2.end()&&iter3<nums3.end();){
        	cout<<*iter3<<" "<<*iter2<<endl;
        	if(*iter3 <= *iter2){
				*iter1 = *iter3;
				iter1 ++;
				iter3 ++;
        	}
        	else{
				*iter1 = *iter2;
        		iter1 ++;
        		iter2 ++;
        	}
        }
        while(iter2<nums2.end()){
        	*iter1 = *iter2;
        	iter1++;
        	iter2++;
        }
        while(iter3<nums3.end()){
        	*iter1 = *iter3;
        	iter1++;
        	iter3++;
        }
    }
};
// The code under blow is used for test
int main()
{
	vector<int> nums1;
	vector<int> nums2;
	vector<int>::iterator iter;
	Solution s;
	nums1.push_back(2);
	nums1.push_back(0);
	nums2.push_back(1);
	s.merge(nums1,1,nums2,1);
	for(iter=nums1.begin();iter<nums1.end();++iter){
		cout<<*iter<<endl;
	}
	system("pause");
	return 0;
}

