/*
*Recover Binary Search Tree 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
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
	pair<TreeNode*, TreeNode*> badNode;
    void recoverTree(TreeNode* root) {
        if(root==NULL)
        	return;
        
        TreeNode *prev = NULL ;
    	TreeNode *curr = root;


		while(curr != NULL){
			if(curr->left == NULL){
				WrongDetect(prev, curr);
				prev = curr;
				curr = curr->right;
			}
			else{
				TreeNode * node = curr->left;
				while(node->right != NULL && node->right != curr)
					node = node->right;
				if(node->right == NULL){
					node->right = curr;
					curr = curr->left;
				}
				else{
					WrongDetect(prev, curr);
					node->right = NULL; 
					prev = curr;
					curr = curr->right;
				}
			}
		}
		int temp = badNode.first->val;
		badNode.first->val = badNode.second->val;
		badNode.second->val = temp;
    }
    void WrongDetect(TreeNode * prev, TreeNode * curr){
    	if(prev != NULL && prev->val > curr->val){
			if(badNode.first == NULL)
				badNode.first = prev;
			badNode.second = curr;
		}
    }
};
