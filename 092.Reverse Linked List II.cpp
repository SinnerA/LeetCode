/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

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

/*额外节点tmpHead，注意加上：tmpHead->next = head*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || n - m == 0) return head;
		ListNode *tmpHead = new ListNode(0);
		tmpHead->next = head;
		ListNode *pre = tmpHead, *p = head, *preSubHead = tmpHead, *subHead = head;
		
		for(int i = 1; i < m; i++){
			preSubHead = p;
			p = p->next;
		}
		subHead = p;
		
		pre = subHead;
		p = pre->next;
		for(int i = m; i < n; i++){
			ListNode *tmp = p->next;
			p->next = pre;
			pre = p;
			p = tmp;
		}
		preSubHead->next = pre;
		subHead->next = p;
		head = tmpHead->next;
		return head;
    }
};

/*无额外节点，多一些判断*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *p = head, *pre = NULL, *preTmpHead = NULL, *tmpHead = NULL;
		for(int i = 1; i < m - 1; i++){
			p = p->next;
		}
		
		if(m == 1){
			preTmpHead = NULL;
			tmpHead = head;
		} else {
			preTmpHead = p;
		    tmpHead = preTmpHead->next;
		}
		
		pre = tmpHead;
		p = tmpHead->next;
		for(int i = m; i < n; i++){
			ListNode* tmp = p->next;
			p->next = pre;
			pre = p;
			p = tmp;
		}
		if(preTmpHead != NULL)
			preTmpHead->next = pre;
		else
			head = pre;
		tmpHead->next = p;
		return head;
    }
};