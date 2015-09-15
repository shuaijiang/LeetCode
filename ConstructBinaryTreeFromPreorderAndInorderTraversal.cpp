/*
*Construct Binary Tree from Preorder and Inorder Traversal
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;


//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len1 = preorder.size();
        int len2 = inorder.size();
        if(len1 != len2)
        	return NULL;
        if(len1 <= 0)
        	return NULL;
        TreeNode * root = build(preorder, 0, len1-1, inorder, 0, len1-1);
        return root;
    }
    TreeNode* build(vector<int>& preorder, int pi, int pj, vector<int>& inorder, int ni, int nj){
    	if(pi > pj)
    		return NULL;
		if(ni > nj)
    		return NULL;
    	
		int val = preorder[pi];
		TreeNode *node = new TreeNode(val);
		if(pi == pj){
			return node;
		}
		int pos = ni;
    	for(int i=ni;i<=nj;i++){
        	if(inorder[i] == val) {
        		pos = i;
        		break;
        	}
        }
        int leftLen  = pos-ni;
        int rightLen = nj-pos;
        
    	node->left  = build(preorder, pi+1, pi+leftLen, inorder, ni, pos-1);
    	node->right = build(preorder, pj-rightLen+1, pj, inorder, pos+1, nj);
    	return node;
    }
};
int main()
{
	Solution s;
	vector<int> preorder(2,0), inorder(2,0);
	preorder[0] = 1;
	preorder[2] = 2;
	inorder[0] = 2;
	inorder[1] = 1;
	
	TreeNode * root = buildTree(preorder, inorder);
	
	system("pause");
	return 0;
}
