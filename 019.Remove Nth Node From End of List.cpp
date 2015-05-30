/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

Tags: Linked List Two Pointers
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//快指针先走n步，然后快慢指针一起走，块指针指向尾节点时，慢指针指向倒数第n个节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head, *slowPre = NULL;
		for(int i = 1; i < n; i++)
			fast = fast->next;
		while(fast->next != NULL){
			slowPre = slow;
			slow = slow->next;
			fast = fast->next;
		}
		if(slow == head)
			head = head->next; //消除第一个节点
		else
			slowPre->next = slow->next;
		return head;
    }
};