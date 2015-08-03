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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {       	
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
			result.push_back(oneSet);
			return;
		}
		for(int i=start;i < candidates.size(); i++){
			int newTarget = target-candidates[i];
			oneSet.push_back(candidates[i]);
			oneCombination(candidates, oneSet, i, newTarget);
			oneSet.pop_back();
    	}
    	return;
    }
};
