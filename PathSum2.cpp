/*
*Path Sum II 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stack>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> result;
    vector< vector<int> > pathSum(TreeNode* root, int sum) {
    	if(root == NULL)
    		return result;
    	vector<int> onePath;
		sumNum(root,onePath,0,sum);
		return result;
    }
    void sumNum(TreeNode * root, vector<int> onePath, int oneSum, int sum){
    	if(root == NULL)
    		return;
    	oneSum +=  root->val;
    	onePath.push_back(root->val);
    	if(root->left == NULL && root->right == NULL){
    		if(oneSum == sum)
    			result.push_back(onePath);
    		else
    			return;
    	}
    	sumNum(root->left, onePath, oneSum, sum);
		sumNum(root->right, onePath, oneSum, sum);
    }
};
