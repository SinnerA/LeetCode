/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Tags: Linked List
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
    ListNode* swapPairs(ListNode* head) {
        ListNode node(0);
		ListNode* headPre = &node;
		headPre->next = head;
		ListNode *pre = headPre, *p = head;
		//p 和 p->next是待交换的两个节点，pre是p的前一个节点
		while(p && p->next){
			pre->next = p->next;
			p->next = p->next->next;
			pre->next->next = p;
			
			pre = p;
			p = p->next;
		}
		return headPre->next;
    }
};