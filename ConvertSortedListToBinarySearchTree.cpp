/*
*Convert Sorted List to Binary Search Tree
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
    	if(head == NULL)
    		return NULL;
        TreeNode *root = new TreeNode(-1);
        if(head->next == NULL){
        	root->val = head->val;
        	return root;
        }
        	
        ListNode *before, *slow, *fast;
        before=head;
		slow = head;
        fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
        	if(slow != head)
        		before = before->next;
			slow = slow->next;
        	fast = fast->next->next;
        }
        if(fast->next == NULL){
        	fast = slow;
        	before->next = NULL;
        }
        else{
	       	fast = slow->next;
        	slow->next = NULL;
        }

        root->val = fast->val;
        root->left  = sortedListToBST(head);
        if(fast->next != NULL)
        	root->right = sortedListToBST(fast->next);
        else
        	root->right = NULL;
        
		return root;
    }
};
