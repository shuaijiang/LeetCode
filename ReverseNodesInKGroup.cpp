/*
*Reverse Nodes in k-Group 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(head == NULL || head->next == NULL)
    		return head;
    	if(k <= 1)
    		return head;
    	
        stack<ListNode*> myStack;
        ListNode* node=NULL, *lastNode=NULL;

        node = head;
        int i = 0;
        while(node != NULL){
        	myStack.push(node);
        	node = node->next;
        	i ++;
        	if(i%k == 0){
        		if(i==k){
        			if(!myStack.empty())
        				head = myStack.top();
        			lastNode = head;
        			myStack.pop();
        		}
        		while(!myStack.empty()){
        			lastNode->next = myStack.top();
        			myStack.pop();
        			lastNode = lastNode->next;
        			lastNode->next = NULL;
        		}
        	}
        }
        if(lastNode == NULL)
        	return head;
        
        while(!myStack.empty()){
        	node = myStack.top();
        	myStack.pop();
        }
        if(node!=NULL)
        	lastNode->next = node;
        
		return head;
    }
};
