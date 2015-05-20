/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Tags: Linked List Math
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
��������ӣ�
��������ָ��ֱ������������������һ��������ʾ�Ƿ��н�λ��
ĳ����������������ٽ���һ�����������ڽ������֮�󼴿ɣ�
������н�λ��Ҫ���һ���ڵ�
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
		ListNode* head = new ListNode(0);
		ListNode* p = head;
		while(l1 != NULL || l2 != NULL){
			int val1 = 0;
			if(l1 != NULL){
				val1 = l1->val;
				l1 = l1->next;
			}
			
			int val2 = 0;
			if(l2 != NULL){
				val2 = l2->val;
				l2 = l2->next;
			}
			
			int tempVal = val1 + val2 + carry;
			p->next = new ListNode(tempVal % 10);
			carry = tempVal / 10;
			p = p->next;
		}
		
		if(carry == 1){
			p->next = new ListNode(1);
		}
		return head->next;
    }
};