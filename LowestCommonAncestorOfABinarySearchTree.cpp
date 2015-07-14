/*
*Lowest Common Ancestor of a Binary Search Tree
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<math>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pValue = p->val;
        int qValue = q->val;
        int rValue = root->val;
		if(min(pValue,qValue)<=rValue && max(pValue,qValue)>=rValue)
			return root;
		else if(min(pValue,qValue)>=rValue)
			return lowestCommonAncestor(root->right,p,q);
		else if(max(pValue,qValue)<=rValue)
			return lowestCommonAncestor(root->left,p,q);
    }
};
