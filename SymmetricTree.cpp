/*
*Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
    	if(root == NULL)
    		return true;
    	return isSym(root->left,root->right);
    }
    bool isSym(TreeNode *p, TreeNode *q){
    	if(p==NULL && q==NULL)
    		return true; 
    	if(p==NULL && q!= NULL)
    		return false;
    	if(p!=NULL && q==NULL)
    		return false;
    	if(p->val != q->val)
    		return false;
    	if(isSym(p->left,q->right) && isSym(p->right,q->left)){
    		return true;
    	}
    	return false;
    }
};
