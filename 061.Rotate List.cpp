/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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

/*
对于找到链表的倒数第k个节点，可以用双指针的方法，第一个指针先指向第k个节点，第二个指针指向头结点，然后两个节点一起前进，
当第一指针指向尾节点时，第二个指针就指向倒数第k个节点

注意：k可能大于n(链表长度)，此时k = k%n；k可能为n的整数倍
*/

/*方法一：先得到k = k%n*/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k){
		if(head == NULL) return NULL;
		ListNode *p = head;
		int n = 0; //链表长度
		while(p->next){
			p = p->next;
			n++;
		}
		n++;
		k = k%n;
		p->next = head;
		ListNode* q = head;
		for(int i = 0; i < n - k -1; i++){
			q = q->next;
		}
		head = q->next;
		q->next = NULL;
		return head;
    }
};


/*方法二：当n较大时超时*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode* p = head;
		ListNode* q = head, *preQ = NULL;
		int n = 0;
		for(int i = 1; i < k; i++){
			p = p->next;
			if(p == NULL) p = head;//表示k超过了链表的长度
		}
		
		while(p->next){
			p = p->next;
			preQ = q;
			q = q->next;
		}
		if(preQ == NULL) return head; //k等于链表的长度的整数倍
		p->next = head;
		preQ->next = NULL;
		return q;
    }
};