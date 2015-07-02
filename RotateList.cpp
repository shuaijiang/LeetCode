/*
*Rotate List  
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
    ListNode* rotateRight(ListNode* head, int k) {
    	if(head == NULL)
    		return head;
        int nodeSize = 0;
        vector<ListNode*> vec;
        ListNode* node = head;
        
        while(node!=NULL){
        	vec.push_back(node);
        	node=node->next;
        }
        nodeSize = vec.size();
        k = k % nodeSize;
        if(k==0)
        	return head;
        
        head = NULL;
        
        for(int i=0;i<k;++i){	
        	node = vec[nodeSize-1-i];
        	if(i==0)
        		node->next = vec[0];
        	else
				node->next = head;
			head = node;
        }
        node = vec[nodeSize-1-k];
		node->next = NULL;
        return head;
    }
};
