/*
*Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q!=NULL)
        	return false;
        if(p!=NULL && q==NULL)
        	return false;
        if(p == NULL && q == NULL)
        	return true;
        if(p->val != q->val)
        	return false;
        if(isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
        	return true;
        else
        	return false;
    }
};
