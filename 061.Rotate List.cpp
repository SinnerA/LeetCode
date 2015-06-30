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
�����ҵ�����ĵ�����k���ڵ㣬������˫ָ��ķ�������һ��ָ����ָ���k���ڵ㣬�ڶ���ָ��ָ��ͷ��㣬Ȼ�������ڵ�һ��ǰ����
����һָ��ָ��β�ڵ�ʱ���ڶ���ָ���ָ������k���ڵ�

ע�⣺k���ܴ���n(������)����ʱk = k%n��k����Ϊn��������
*/

/*����һ���ȵõ�k = k%n*/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k){
		if(head == NULL) return NULL;
		ListNode *p = head;
		int n = 0; //������
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


/*����������n�ϴ�ʱ��ʱ*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode* p = head;
		ListNode* q = head, *preQ = NULL;
		int n = 0;
		for(int i = 1; i < k; i++){
			p = p->next;
			if(p == NULL) p = head;//��ʾk����������ĳ���
		}
		
		while(p->next){
			p = p->next;
			preQ = q;
			q = q->next;
		}
		if(preQ == NULL) return head; //k��������ĳ��ȵ�������
		p->next = head;
		preQ->next = NULL;
		return q;
    }
};