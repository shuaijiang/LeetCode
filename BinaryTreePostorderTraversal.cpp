/*
*Binary Tree Postorder Traversal 
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> myStack;
        if(root==NULL)
        	return vec;

       	myStack.push(root);
        while(!myStack.empty()){
        	TreeNode *node = myStack.top();
        	myStack.pop();
        	TreeNode *left = node->left;
			TreeNode *right = node->right; 
        	if(left == NULL && right == NULL){
        		vec.push_back(node->val);	
        	}
        	else{
        		node->left = NULL;
        		node->right = NULL;
        		myStack.push(node);
        	}
        	if(right!=NULL)
        		myStack.push(right);
        	if(left!=NULL)
				myStack.push(left);
        }
        return vec;   
    }
};
