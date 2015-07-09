/*Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> value;
        if(root == NULL)
        	return value;
        
        vector<TreeNode*> oneLevel;
        vector<vector<TreeNode*>> myTree;
        TreeNode *node;

        oneLevel.push_back(root);
        myTree.push_back(oneLevel);
        while(oneLevel.size()>=1){
        	vector<TreeNode*> nextLevel;
			for(int i=0;i<oneLevel.size();i++)
			{
				node = oneLevel[i];
				if(node->left != NULL)
					nextLevel.push_back(node->left);
				if(node->right != NULL)
					nextLevel.push_back(node->right);
			}
			if(nextLevel.size()>=1)
				myTree.push_back(nextLevel);
			oneLevel = nextLevel;
        }
		for(int i=0;i<myTree.size();i++){
			vector<TreeNode*> level = myTree[i];
			int size = level.size();
			node = level[size-1];
			value.push_back(node->val);
		}
		return value;
    }
};
