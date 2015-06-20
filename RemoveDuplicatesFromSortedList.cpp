/*
*Remove Duplicates from Sorted List 
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
    ListNode* deleteDuplicates(ListNode* head) {
    	if(head == NULL || head->next == NULL)
    		return head;
        ListNode *ptr_all = head->next;
        ListNode *ptr_use = head;
        while(ptr_all != NULL){
        	if(ptr_all->val != ptr_use->val){
        		ptr_use->next = ptr_all;
        		ptr_use = ptr_use->next;
        	}
			ptr_all = ptr_all->next;
        }
        ptr_use->next = NULL;
        return head;
    }
};

