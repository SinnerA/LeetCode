/*
Sort a linked list using insertion sort.

Tags: Linked List Sort
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
    ListNode* insertionSortList(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;
		ListNode *tmpHead = new ListNode(0);
		tmpHead->next = head;
		ListNode *start = tmpHead, *end = head, *p = head->next;
		while(p){
			ListNode *move = start->next, *pre = start;
			while(move != p && p->val >= move->val){
				pre = move;
				move = move->next;
			}
			if(p == move){
				end = p;
			} else {
				end->next = p->next;
				p->next = pre->next;
				pre->next = p;
			}
			p = end->next;
		}
		head = tmpHead->next;
		return head;
    }
};