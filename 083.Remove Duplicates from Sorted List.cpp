/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
		ListNode* p = head, *q = head;
		bool flag = false;
		while(q->next){
			if(q->val != q->next->val)
				flag = true;
			q = q->next;
			if(flag){
				p->next = q;
				p = p->next;
				flag = false;
			}
		}
		p->next = NULL;
		return head;
    }
};