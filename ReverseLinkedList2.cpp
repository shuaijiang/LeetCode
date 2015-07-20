/*
*Reverse Linked List II
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<vector>
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL)
        	return head;
        if(m>n)
        	return NULL;
        if(m==n)
        	return head;
        
        ListNode * newHead;
        ListNode * lastNode, *currNode, *nextNode, *node;
        if(n<=1)
        	return head;
        
        node = head;
		for(int i=1;i<n;i++){
			node = node->next;
		}
		nextNode = node->next;
		
		if(m==1){
			newHead = reverseList(head, n-m+1);
			head->next = nextNode;
			return newHead; 
		}
		else{
			lastNode = head;
			currNode = head->next;
			for(int i=2;i<m;i++){
				lastNode = lastNode->next;
				currNode = currNode->next; 
			}
			newHead = reverseList(currNode,n-m+1);
			currNode->next = nextNode;
			lastNode->next = newHead;
		}
		return head;
    }
    ListNode* reverseList(ListNode* head, int k){
    	stack<ListNode*> myStack;
    	ListNode* newHead, *node, *nextNode;
    	node = head;
    	myStack.push(node);
    	for(int i=1;i<k;i++){
    		node = node->next;
    		myStack.push(node);
    	}
    	newHead = node;
    	myStack.pop();
    	while(!myStack.empty()){
    		nextNode = myStack.top();
    		myStack.pop();
    		node->next = nextNode;
    		node = node->next;
    	}
    	return newHead;
    }
};
