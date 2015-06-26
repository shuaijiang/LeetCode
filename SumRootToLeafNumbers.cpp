/*
*Maximum Depth of Binary Tree
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
struct TreeNode {
 	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
	int sum;
    int sumNumbers(TreeNode* root) {
    	if(root == NULL)
    		return 0;
        if(root->left == NULL && root->right == NULL)
        	return root->val;
        sum = 0;
		sumNum(root,0);
		return sum;
    }
    void sumNum(TreeNode * root, int num){
    	if(root == NULL)
    		return;
    	num = twoSum(num,root->val);
    	if(root->left == NULL && root->right == NULL)
    		sum += num;    	

    	if(root->left != NULL)
    		sumNum(root->left,num);
    	if(root->right != NULL)
    		sumNum(root->right,num);
    }
    int twoSum(int a, int b) {
    	int bNum = b, aNum = a;
    	if(bNum == 0)
    		aNum = aNum * 10;
    	while(bNum>0){
    		aNum = aNum * 10;
    		aNum = aNum + bNum;
    		bNum = bNum / 10;
    	}
    	return aNum;
    }
};

int main(){
	int a=1,b=9;
	Solution s;
	int c = s.twoSum(a,b);
	cout<<"c="<<c<<endl;
	system("pause");
	return 0;
}
