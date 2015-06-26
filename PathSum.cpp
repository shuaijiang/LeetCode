/*
* Path Sum
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	if(root == NULL)
    		return false;
		return 	sumNum(root,0,sum);
    }
    bool sumNum(TreeNode * root, int val,int sum){
    	if(root == NULL)
    		return false;    
    	val = val + root->val;
    	if(root->left == NULL && root->right == NULL){
    		if(val == sum)
    			return true;
    		else
    			return false;
    	}
    	return (sumNum(root->left,val,sum) || sumNum(root->right,val,sum));
    }
};

