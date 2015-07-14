/*
*
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
    void flatten(TreeNode* root) {
        stack<TreeNode*> myStack;
        if(root==NULL)
        	return;

        if(root->right!=NULL)
        	myStack.push(root->right);
        if(root->left!=NULL)
        	myStack.push(root->left);
        root->left = NULL;
		root->right= NULL; 
        TreeNode * lastNode = root;
        while(!myStack.empty()){
        	TreeNode * node = myStack.top();
        	myStack.pop();
        	if(node->right!=NULL)	
        		myStack.push(node->right);
        	if(node->left!=NULL)
        		myStack.push(node->left);
        	node->left=NULL;
        	node->right=NULL;
			lastNode->right=node;
        	lastNode->left =NULL;
        	
			lastNode = lastNode->right;
        }
    }
};
