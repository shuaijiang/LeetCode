/*
*Binary Search Tree Iterator 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	int nextMin = 0;
	stack<TreeNode*> myStack;
    BSTIterator(TreeNode *root) {
        while(root!=NULL){
        	myStack.push(root);
        	root=root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
    	if(!myStack.empty()){
    		TreeNode * node = myStack.top();
    		myStack.pop();
			nextMin = node->val;
				
			node = node->right;
			while(node){
				myStack.push(node);
				node=node->left;
			}
			
    		return true;
    	}
		return false;
    }

    /** @return the next smallest number */
    int next() {
		return nextMin;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
