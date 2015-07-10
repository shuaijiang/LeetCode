/*
*Palindrome Linked List   
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
 
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) 
        	return true;
        ListNode *list1 = head;
        ListNode *list2 = new ListNode(head->val);
        
        list2->next = NULL;
        list1 = list1->next;
		while(list1 != NULL){
			int num = list1->val;
        	ListNode *node = new ListNode(num);
        	node->next = list2;
        	list2 = node;
        	list1 = list1->next;
        }
        list1 = head;
        while(list1 != NULL && list2->next != NULL){
        	if(list1->val != list2->val)
        		return false;
        	list1 = list1->next;
        	list2 = list2->next;
        }
        return true;
    }
};
//The code under below is used for test
int main(){
	ListNode * head = new ListNode(1);
	ListNode * node1 = new ListNode(2);
	ListNode * node2 = new ListNode(0);
	head->next = node1;
	node1->next = node2;
	
	Solution s;
	bool isP = s.isPalindrome(head);
	cout<<"isP="<<isP<<endl;
	system("pause");
	return 0;
	
}
