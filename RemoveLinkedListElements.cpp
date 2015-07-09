/*Remove Linked List Elements 
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
    ListNode* removeElements(ListNode* head, int val) {
		while(head != NULL && head->val == val)
			head = head->next;
		
		if(head == NULL)
        	return NULL;
		ListNode *lastNode = head;
		ListNode *currNode = head->next;
		while(currNode != NULL) {
			if(currNode->val == val){
				lastNode->next = currNode->next;
				currNode = currNode->next;
			}
			else{
				lastNode = lastNode->next;
				currNode = currNode->next;
			}
		}
		return head;		
    }
};
