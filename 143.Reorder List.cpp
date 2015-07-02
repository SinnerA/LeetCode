/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

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

/*
先用快慢指针找到链表的中点，然后翻转链表后半部分，再和前半部分组合。
需要注意的是把链表分成两半时，前半段的尾节点要置为NULL，翻转链表时也要把尾节点置为NULL。
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
		ListNode* fast = head, *slow = head, *tail = NULL;
		while(fast != NULL && fast->next != NULL){
			//利用快慢指针找到链表的中点
			tail = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *beforeP = head, *afterP = slow;
		tail->next = NULL;   //此时tail指向前半段的结尾
		afterP = reverseList(afterP); //翻转链表后半段                          
		while(beforeP){
			ListNode *tmp = afterP->next;
			afterP->next = beforeP->next;
			beforeP->next = afterP;
			tail = afterP;
			beforeP = afterP->next;
			afterP = tmp;
		}
		if(afterP) tail->next = afterP;
    }
	
	//翻转链表
	ListNode* reverseList(ListNode* head){
		if(head == NULL || head->next == NULL) return head;
		ListNode *pre = head, *p = head->next;
		while(p){
			ListNode *tmp = p->next;
			p->next = pre;
			pre = p;
			p = tmp;
		}
		head->next = NULL;
		head = pre;
		return head;
	}
};