/*Linked List Cycle2
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<map>
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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int> myMap;
		if(head == NULL) 
			return null;
		if(head->next == NULL)
			return null;
		ListNode * node = head;
		while(node!=NULL){
			if(myMap.find(node)==myMap.end())
				myMap[node] = 1;
			else
				return node;
			node = node->next;
		}
		return null;
    }
};
