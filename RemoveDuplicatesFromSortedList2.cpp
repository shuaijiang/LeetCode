/*
*Remove Duplicates from Sorted List II 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<string.h>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
        	return head;
        ListNode *node = head->next;
        int headVal = head->val;
        if(node != NULL && node->val == headVal){
	        while(true){
	        	while(node != NULL && node->val == headVal)
	        		node = node->next;	        	
	        	if(node == NULL){
	        		head = NULL;
	        		return head;
	        	}
        		head = node;
        		node = head->next;
        		headVal = head->val;
        		if(node==NULL || node->val != headVal)
        			break;
	        }
        }
        if(head==NULL || head->next == NULL)
        	return head;
		ListNode *lastNode = head, *currNode=head->next, *nextNode;
        
		while(currNode != NULL){
			nextNode = currNode->next;
			int currVal = currNode->val;
			if(nextNode!=NULL && currVal == nextNode->val){
				while(true){
					while(nextNode!=NULL && currVal == nextNode->val){
						nextNode = nextNode->next;
					}
					
					currNode = nextNode;
					if(currNode == NULL)
						break;
					nextNode = currNode->next;
					currVal = currNode->val;
					if(nextNode==NULL || currVal != nextNode->val)
						break;
				}
				lastNode->next = currNode;
				lastNode = currNode;
				if(currNode != NULL)
					currNode = currNode->next;
			}
			else{				
				lastNode = currNode;
				currNode = currNode->next;
			}
		}
		return head;
    }
};
