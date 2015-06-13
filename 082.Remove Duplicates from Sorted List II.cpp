/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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

/*??1*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
		ListNode headNode(INT_MAX);
		ListNode* p = &headNode, *q = head;
		int count = 0;
		while(q->next){
			if(q->val != q->next->val){
				if(count == 0){
					p->next = q;
					p = p->next;
				} else {
					count = 0;
				}
			}
			if(q->val == q->next->val)
				count++;
			q = q->next;
		}
		if(count == 0) p->next = q;
		else p->next = NULL;
		return headNode.next;
    }
};

/*??2*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
    }
};