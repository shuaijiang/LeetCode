/*
*Binary Tree Preorder Traversal 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stack>
#include<vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> myStack;
        TreeNode * node;
        if(root != NULL)
        	myStack.push(root);
        while(!myStack.empty()){
        	node = myStack.top();
        	vec.push_back(node->val);
        	myStack.pop();
        	if(node->right!=NULL)
        		myStack.push(node->right);
        	if(node->left!=NULL)
			myStack.push(node->left);
        }
        return vec;
        
    }
};
