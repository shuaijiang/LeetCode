/*
*Swap Nodes in Pairs
*Author: shuaijiang
*Email: zhaoshuaijiang8@gmail.com
*/

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
    ListNode *swapPairs(ListNode *head) {
    	if(head == NULL)
    		return head;
		if(head->next == NULL)
			return head;
		
        ListNode * currentNode = head->next;
        ListNode * lastNode = head;
        ListNode * tempNode;
		if(head->next != NULL)
        {
        	tempNode = head;
        	head = head->next;
        	tempNode->next = head->next; 
        	head->next = tempNode;
        	lastNode = head->next;
        	currentNode = lastNode->next;
        }
        while(currentNode != NULL )
        {
        	if(currentNode->next == NULL)
        		break;
			tempNode = currentNode;
			currentNode = currentNode->next;
			tempNode->next = currentNode->next;
			currentNode->next = tempNode;
			
			lastNode->next = currentNode;
			
			lastNode    = currentNode->next;
			currentNode = lastNode->next;
        }
        return head;
    }
};
