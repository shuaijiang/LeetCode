/*
*Populating Next Right Pointers in Each Node 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(root == NULL)
    		return;
        vector<TreeLinkNode*> currLevel;
        vector<TreeLinkNode*> nextLevel;
        currLevel.push_back(root);
        while(currLevel.size()>0){
        	for(int i=0;i<currLevel.size();i++){
	        	TreeLinkNode * node = currLevel[i];
	        	if(i+1<currLevel.size())
	        		node->next = currLevel[i+1];
	        	if(node->left != NULL)
					nextLevel.push_back(node->left);
	        	if(node->right != NULL)
	        		nextLevel.push_back(node->right);
	        }
	        currLevel = nextLevel;
	        nextLevel.clear();
        }
    }
};
