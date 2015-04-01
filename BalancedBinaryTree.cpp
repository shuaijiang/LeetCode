/*
*Balanced Binary Tree 
*Given a binary tree, determine if it is height-balanced.
*For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<iostream>
 #include<math>
 using namespace std;
 
class Solution {
public:
    bool isBalanced(TreeNode *root) {
    	int theDepth;
		return isTreeBalanced(root, &theDepth); 
    }
    bool isTreeBalanced(TreeNode *theRoot, int *theDepth) 
    {
    	if(theRoot == NULL)
    	{
    		*theDepth = 0;
    		return true;
    	}
    	int leftDepth, rightDepth;
    	if(isTreeBalanced(theRoot->left, &leftDepth) && isTreeBalanced(theRoot->right, &rightDepth))
    	{
    		int diffDepth = abs(leftDepth - rightDepth);
    		if(diffDepth <= 1)
    		{
    			*theDepth = 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    			return true;
    		}
    	}
    	return false;
    }
};

