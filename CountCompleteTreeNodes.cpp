/*
*Count Complete Tree Nodes 
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
    int countNodes(TreeNode* root) {
        if(root == NULL) 
        	return 0;
        int leftH  = leftHight(root) + 1;
        int rightH = rightHight(root) + 1;
		if(leftH == rightH)
        	return 	2<<(leftH-1) - 1;
		else
			return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int leftHight(TreeNode * root){
    	int hight = 0;
    	while(root->left != NULL){
    		root = root->left;
    		hight ++;
    	}
    	return hight;
    }
	int rightHight(TreeNode * root){
    	int hight = 0;
    	while(root->right != NULL){
    		root = root->right;
    		hight ++;
    	}
    	return hight;
    }
};
