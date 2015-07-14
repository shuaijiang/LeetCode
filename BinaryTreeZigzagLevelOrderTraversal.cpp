/*
*Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode*> currLevel, nextLevel;
        if(root==NULL)
        	return result;
        currLevel.push_back(root);
        for(int count=0;currLevel.size()>0;count++){
        	vector<int> vec;
		    for(int i=currLevel.size()-1;i>=0;i--){
				TreeNode * node = currLevel[i];
	        	vec.push_back(node->val);
	        	if(count%2==0){
	        		if(node->left)
						nextLevel.push_back(node->left);
					if(node->right)
						nextLevel.push_back(node->right);
	        	}
	        	else{
					if(node->right)
						nextLevel.push_back(node->right);
					if(node->left)
						nextLevel.push_back(node->left);
	        	}
	        }
			result.push_back(vec);
	        currLevel = nextLevel;
	        nextLevel.clear();
        }
		return result; 
    }
};
