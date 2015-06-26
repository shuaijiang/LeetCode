/*
*Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
    	if(root==NULL)
    		return 0;
    	if(root->left!=NULL && root->right==NULL)
    		return 1+minDepth(root->left);
    	if(root->left==NULL && root->right!=NULL)
    		return 1+minDepth(root->right);
    	return min(1+minDepth(root->left),1+minDepth(root->right));
    }
};
