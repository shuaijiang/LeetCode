/*
*Binary Tree Inorder Traversal  
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> myStack;
        vector<int> result;
        if(root == NULL)
        	return result;
        myStack.push(root);
        while(!myStack.empty()){
        	TreeNode * node = myStack.top();
        	myStack.pop();
			if(node->left == NULL && node->right == NULL)
				result.push_back(node->val);
			else{
				TreeNode * left = NULL;
				if(node->right != NULL){
					myStack.push(node->right);
					node->right = NULL;
				}
				if(node->left != NULL){
					left = node->left;
					node->left = NULL; 
				}
				myStack.push(node);
				if(left != NULL)
					myStack.push(left);
			}
        }
        return result;
    }
};
