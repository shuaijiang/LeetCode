/*
*Insertion Sort List 
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
    ListNode* insertionSortList(ListNode* head) {
    	if(head == NULL || head->next == NULL)
    		return head;
    	
        int sortedNum = 1;
        ListNode *currNode=head->next, *lastNode=head;
        while(currNode != NULL){
        	if(currNode->val < lastNode->val){
        		lastNode->next = currNode->next;
				head = insertNode(head, currNode, sortedNum);
        	}
        	else
        	    lastNode = lastNode->next;        
        	currNode = lastNode->next;
        	sortedNum ++;
        }
        return head;
    }
    ListNode* insertNode(ListNode* head, ListNode* node, int k){
    	int val = node->val;
    	if(val < head->val){
    		node->next = head;
    		head = node;
    		return head; 
    	}
    	ListNode* lastNode=head, *currNode=head->next;
    	for(int i=1;i<k;i++){
			if(val < currNode->val){
				node->next = currNode; 
				lastNode->next = node;
				return head;
			}
			lastNode = lastNode->next;
			currNode = currNode->next;
		}
		return head;
    }
};
