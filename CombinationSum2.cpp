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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {       	
	    int size = candidates.size();
        if(size <= 0)
        	return result;
        vector<int> oneSet;
		sort(candidates.begin(),candidates.end());
		oneCombination(candidates, oneSet, 0, target);
		return result;
    }
    void oneCombination(vector<int>&candidates, vector<int> &oneSet, int start, int target) {    	
	    if(target < 0)
			return;
		else if(target == 0){
			for(int i=0;i<result.size();i++){
				if(sameSet(result[i], oneSet))
					return;
			}
			result.push_back(oneSet);
			return;
		}
		for(int i=start;i < candidates.size(); i++){
			int newTarget = target-candidates[i];
			oneSet.push_back(candidates[i]);
			oneCombination(candidates, oneSet, i+1, newTarget);
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
