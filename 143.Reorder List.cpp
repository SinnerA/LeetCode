/*
Given a singly linked list L: L0��L1������Ln-1��Ln,
reorder it to: L0��Ln��L1��Ln-1��L2��Ln-2����

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
���ÿ���ָ���ҵ�������е㣬Ȼ��ת�����벿�֣��ٺ�ǰ�벿����ϡ�
��Ҫע����ǰ�����ֳ�����ʱ��ǰ��ε�β�ڵ�Ҫ��ΪNULL����ת����ʱҲҪ��β�ڵ���ΪNULL��
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
		ListNode* fast = head, *slow = head, *tail = NULL;
		while(fast != NULL && fast->next != NULL){
			//���ÿ���ָ���ҵ�������е�
			tail = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *beforeP = head, *afterP = slow;
		tail->next = NULL;   //��ʱtailָ��ǰ��εĽ�β
		afterP = reverseList(afterP); //��ת�������                          
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
	
	//��ת����
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