/*
*Binary Tree Paths 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
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
	vector<string> result;
    vector<string> binaryTreePaths(TreeNode* root) {
		string str;
		TreePath(root, str);
		return result;
    }
    void TreePath(TreeNode* root, string str){
    	if(root == NULL)
    		return;
    	stringstream ss;
	    string val;
		ss<<root->val;
		ss>>val;
		ss.clear();
    	if(root->left == NULL && root->right == NULL){
			if(str.size() == 0)
				str += val;
			else{
				str.push_back('-');
				str.push_back('>');
				str += val;
			}
    		result.push_back(str);		
    	}
    	else{
    		if(root->left != NULL){
    			string str1 = str;
    			if(str1.size() == 0)
    				str1 += val;
    			else{
    				str1.push_back('-');
    				str1.push_back('>');
					str1 += val;
    			}
	    		TreePath(root->left, str1);
	    	}
	    	if(root->right != NULL){
	    		string str2 = str;
	    		if(str2.size() == 0)
    				str2 += val;
    			else{
    				str2.push_back('-');
    				str2.push_back('>');
					str2 += val;
    			}
	    		TreePath(root->right, str2);
	    	}
    	} 	
    }
};
