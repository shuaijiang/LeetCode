/*
*Validate Binary Search Tree  
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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        	return true;
        vector<int> nums;
        stack<TreeNode*> myStack;
        TreeNode *leftNode  = root->left;
    	TreeNode *rightNode = root->right;
		
		if(rightNode != NULL)
			myStack.push(rightNode);
		
		root->left = root->right = NULL;
		myStack.push(root);
		
		if(leftNode != NULL)
			myStack.push(leftNode);
		
		while(!myStack.empty()){
			TreeNode * node = myStack.top();
			myStack.pop();
			leftNode  = node->left;
			rightNode = node->right;
			if(leftNode==NULL && rightNode==NULL){
				int size = nums.size();
				if(size >=1 && nums[size-1] >= node->val)
					return false;
				else
					nums.push_back(node->val);
			}
				
			else{
				if(rightNode != NULL)
					myStack.push(rightNode);
				
				node->left = node->right = NULL;
				myStack.push(node);
				
				if(leftNode != NULL)
					myStack.push(leftNode);
			}
		}
		return true;	
    }

};
