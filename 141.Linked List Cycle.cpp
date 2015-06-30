/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

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

/*�㷨1�����ÿ���ָ�룬��ʼ����ָ���ָ������head��Ȼ��ѭ���ƶ�����ָ���ƶ�1������ָ�����ƶ�2������������л�������ָ��һ����������*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
		ListNode *fast = head, *slow = head;
		while(fast && fast->next){
			fast = fast->next->next;
			slow = slow->next;
			if(slow == fast) return true;
		}
		return false;
    }
};

/*�㷨�����������õ�ת����ķ������ж��Ƿ��л����������������ÿ�α�����ָ�뵹ת������л����һ����ص�head�ڵ㡣�����������ƻ�����ṹ ����Ҫ�ָ���*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
		ListNode *pre = head, *p = head->next;
		while(p){
			if(p == head) return true;
			ListNode *temp = p->next;
			p->next = pre;
			pre = p;
			p = temp;
		}
		return false;
    }
};