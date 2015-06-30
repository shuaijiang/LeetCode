/*
*Reorder List 
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/
#include<iostream>
#include<stack>
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
    void reorderList(ListNode* head) {
        if(head==NULL)
        	return;
        if(head->next==NULL)
        	return;
        ListNode* node;
        vector<ListNode*> vec;
        int totalNum = 0;
        node = head->next;
        while(node!=NULL){
        	vec.push_back(node);
        	node = node->next;
        }
        int size = vec.size();
        node = head;
        for(int i=0;i<size/2;i++){
        	node->next = vec[size-1-i];
        	node = node->next;
        	node->next = vec[i];
        	node = node->next;
        }
        if(size%2!=0){
        	node->next = vec[size/2];
        	node = node->next;
        }
        node->next=NULL;
    }
};
