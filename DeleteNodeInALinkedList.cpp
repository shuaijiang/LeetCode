/*
*Delete Node in a Linked List
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<math.h>
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
    void deleteNode(ListNode* node) {
        if(node->next == NULL)
        	return;
        ListNode *nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
		return;
    }
};
