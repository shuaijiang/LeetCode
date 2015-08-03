/*
*Combination Sum
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
	vector<vector<int>> result;
	vector<int> nums;
    vector<vector<int>> combinationSum3(int k, int n) {       	
		for(int i=1;i<=9;i++)
			nums.push_back(i);
		int size = nums.size();
        if(size <= 0)
        	return result;
        vector<int> oneSet;
		oneCombination(oneSet, 0, k, n);
		return result;
    }
    void oneCombination(vector<int> &oneSet, int start, int k, int target) {    	
	    if(oneSet.size() > k)
	    	return;
		if(target < 0)
			return;
		else if(target == 0){
			for(int i=0;i<result.size();i++){
				if(sameSet(result[i], oneSet))
					return;
			}
			if(oneSet.size() == k)
				result.push_back(oneSet);
			return;
		}
		for(int i=start;i < nums.size(); i++){
			int newTarget = target-nums[i];
			oneSet.push_back(nums[i]);
			oneCombination(oneSet, i+1, k, newTarget);
			oneSet.pop_back();
    	}
    	return;
    }
    bool sameSet(vector<int> set1, vector<int> set2) {
    	int size1 = set1.size();
		int size2 = set2.size();
		if(size1 != size2)
			return false;
		for(int i=0;i<size1;i++) {
			if(set1[i] != set2[i])
				return false;
		}
		return true;
    }
};
