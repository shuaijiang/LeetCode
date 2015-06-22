/*
*Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
    	TreeNode *temp;
    	if(root == NULL)
    		return root;
    	temp = root->left;
    	root->left  = root->right;
    	root->right = temp;
    	
        root->left  = invertTree(root->left);
        root->right = invertTree(root->right);
        
		return root;
    }
};
