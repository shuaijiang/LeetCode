/*
*Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	if(nums.size()<=0)
    		return NULL;
        TreeNode* root; 
        root = convert(nums,0,nums.size()-1);
        return root;
    }
    TreeNode* convert(vector<int>& nums, int low, int high){
    	TreeNode * node;
		if(low<high){
    		int midd = (low+high+1)/2;
	    	node = new TreeNode(nums[midd]);
	    	node->left = convert(nums,low,midd-1);
	    	node->right = convert(nums,midd+1,high);
	    	
    	}
    	else if(low==high){
    		int midd = low;
    		node = new TreeNode(nums[midd]);
    		node->left  = NULL;
    		node->right = NULL;
    	}
    	else
    		return NULL;
    	return node;

    }
};
