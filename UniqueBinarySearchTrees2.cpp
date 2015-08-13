/*
*Unique Binary Search Trees II 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string.h>
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
    vector<TreeNode*> generateTrees(int n) {
    	if(n == 0)
    		return buildTree(1,0);
    	return buildTree(1,n);
    }
    vector<TreeNode*> buildTree(int start, int end){
    	vector<TreeNode*> tree;
    	if(start > end){
    		tree.push_back(NULL);
    		return tree;
    	}
    	for(int i=start; i<=end;i++){
    		
    		vector<TreeNode*> leftTree = buildTree(start, i-1);
    		vector<TreeNode*> rightTree = buildTree(i+1, end);
    		for(int left=0;left<leftTree.size();left++){
    			for(int right=0;right<rightTree.size();right++){
    				TreeNode* node = new TreeNode(i);
					node->left = leftTree[left];
    				node->right = rightTree[right];
    				tree.push_back(node);
    			}
    		}
    	}
    	return tree;
    }
};
