/*
*Merge Sorted Array 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL && l2 != NULL)
    		return l2;
    	if(l1 != NULL && l2 == NULL)
    		return l1;
    	if(l1 == NULL && l2 == NULL)
    		return NULL;
        
		ListNode *head, *list;
        if(l1->val < l2->val){
        	head = l1;
			l1 = l1->next;	
        }
        else{
        	head = l2;
        	l2 = l2->next;
        }
		list = head;
		while(l1!=NULL && l2!=NULL){
			if(l1->val < l2->val){
				list->next = l1;
				list = list->next;
				l1 = l1->next;
			}
			else{
				list->next = l2;
				list = list->next;
				l2 = l2->next;
			}
		}
		if(l1 != NULL)
			list->next = l1;
		if(l2 != NULL)
			list->next = l2;
		
		return head;
		
    }
};
