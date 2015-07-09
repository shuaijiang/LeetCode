/*Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> myMap;
		if(head == NULL) 
			return false;
		if(head->next == NULL)
			return false;
		ListNode * node = head;
		while(node!=NULL){
			if(myMap.find(node)==myMap.end())
				myMap[node] = 1;
			else
				return true;
			node = node->next;
		}
		return false;
    }
};
