/*
*Kth Smallest Element in a BST 
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> myStack;
        vector<int> result;
        if(root==NULL)
        	return 0;
        myStack.push(root);
        
        while(!myStack.empty()){
        	TreeNode * node = myStack.top();
        	myStack.pop();
        	if(node->left == NULL && node->right == NULL)
        		result.push_back(node->val);
        	else{
        		if(node->right != NULL)
        			myStack.push(node->right);
        		TreeNode *left = node->left;
        		node->left = NULL;
        		node->right = NULL;
        		myStack.push(node);
        		if(left != NULL)
        			myStack.push(left);				   			
        	}
			if(result.size()==k)
				return result[k-1];
        }
    }
};
