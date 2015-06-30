/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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

/*
���ÿ���ָ���жϳ��Ƿ��л��󣬻���Ҫ�ҳ�������㣬�������£�

1����������Ϊlen�������зǿ�nextָ��ĸ�����������˵�ĳ��Ⱦ�Ϊ�ǿ�nextָ��ĸ�����������head��������㳤��Ϊa������㵽����ָ��������ĳ���Ϊb�����ĳ���Ϊr��
2�����赽����ָ������ʱ����ָ���ƶ��ĳ���Ϊs�����ָ���ƶ�����Ϊ2s������ָ���ƶ��ĳ��Ȼ�����s�����ڻ����Ƶ�kȦ��k>=1��,����2s=s+kr ����s = kr��
3����s = a + b �� s = kr ��֪ a + b = kr = (k-1)r + r�� ��r = len - a������a + b = (k-1)r + len - a, �� a = (k-1)r + len - a - b��
   len - a - b�������㵽�������ĳ��ȣ��ɴ˿�֪��������ͷ������㳤�� = (k-1)������+�������㵽����㳤�ȣ��������Ǵ�����ͷ����������ֱ���һ��ָ�룬ÿ�θ���һ��������ָ��ض���������������Ϊ����㡣
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
		ListNode *slow = head, *fast = head;
		while(fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast) break;
		}
		if(slow == fast){
			//���ڻ���Ѱ�һ������
			ListNode *p = slow, *q = head;
			while(p != q){
				p = p->next;
				q = q->next;
			}
			return p;
		} else {
			return NULL;
		}
    }
};