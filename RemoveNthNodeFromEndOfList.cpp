/*
*Remove Nth Node from End of List 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(head==NULL)
    		return NULL;
    	if(head->next == NULL && n == 1)
    		return NULL;
        ListNode *ptr, *ptr_nth, *ptr_before;
        int count  = 0;
        ptr = head;
        ptr_nth    = head;
		ptr_before = head;
		while(ptr->next != NULL){
			if(count > n){
        		ptr_before = ptr_nth;
				ptr_nth = ptr_nth->next;
        	}
        	count ++;
        	ptr = ptr->next;
		}
		if(ptr_before == ptr_nth)
			head = head->next;
		else
        	ptr_before->next = ptr_nth->next;
        	
        return head;
    }
};
