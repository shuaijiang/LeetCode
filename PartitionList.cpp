/*
*Partition List 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<queue>
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
    ListNode* partition(ListNode* head, int x) {
    	if(head == NULL)
    		return head;
        queue<ListNode*> largeQueue, smallQueue;
        ListNode * node = head;
        while(node != NULL){
        	if(node->val >= x)
        		largeQueue.push(node);
        	else
        		smallQueue.push(node);
			node = node->next;
        }
        head = NULL;
        if(!smallQueue.empty()){
        	head = smallQueue.front();
        	smallQueue.pop(); 
        	node = head;
        	while(!smallQueue.empty()){
	        	node->next = smallQueue.front();
	        	node = node->next;
	        	smallQueue.pop();
	        }
        }
		if(head == NULL){
			head = largeQueue.front();
			largeQueue.pop();
			node = head;
		}
		while(!largeQueue.empty()){
			node->next = largeQueue.front();
			largeQueue.pop();
			node = node->next;
		}
		node->next = NULL;
		return head;
    }
};
