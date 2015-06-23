/*
*Reverse Linked List 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<math.h>
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
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL) 
    		return NULL;
    	ListNode *newList=NULL;
        ListNode *currentNode=head;
        while(currentNode != NULL)
        {
        	int val = currentNode->val;
        	currentNode = currentNode->next;
        	
        	ListNode *newNode = new ListNode(val);
        	newNode->val  = val;
        	newNode->next = newList;
        	newList = newNode;
        }
        return newList;
    }
};
