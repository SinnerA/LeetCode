/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

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

/*����һ��ÿ��ѡȡ��һ��group��,���÷�ת�����Ӻ�����ת��group*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode tmpHead(0);
		ListNode *p = head, *tail = &tmpHead;//tail��ʾ��ǰ�Ѵ������β�ڵ�
		
		while(p){
			ListNode *groupHead = p;
			int i;
			for(i = 1; i < k && p->next != NULL; i++) p = p->next;
			if(i < k){
				//����k���ڵ�
				tail->next = groupHead;
				return tmpHead.next;
			}
			p = p->next;
			pair<ListNode*, ListNode*> headtailPair = reverseList(groupHead, p);
			tail->next = headtailPair.first; //��һ�η�ת����֮��tail->next��tmpHead.nextָ���µ�����ͷ��㣬��Ϊ����ֵ
			tail = headtailPair.second;
		}
		return tmpHead.next;
    }
	
	//��ת����,�����ط�ת�������ͷ����β�ڵ�
	pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* end){
		ListNode *p = head, *pre = NULL;
		while(p != end){
			ListNode* tmp = p->next;
			p->next = pre;
			pre = p;
			p = tmp;
		}
		return make_pair(pre, head);
	}
};


/*������������ķ���ʵ���ϱ�����2������,�����ԼӸĽ��ڼ���k������Ĺ����оͿ�ʼ��ת, ��󲿷��������k���ڵ�,��ԭԭ����˳��*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode tmpHead(0);
		ListNode *p = head, *tail = &tmpHead;
		while(p){
			pair<ListNode*, ListNode*> pair = reverseList(p, k);
			tail->next = pair.first;
			tail = pair.second;
			p = tail->next;
		}
		return tmpHead.next;
    }
	
	//��ת��head��ʼ��k������ڵ㣬�������k���򲻷�ת�����ط�ת�����k���ڵ�
    //�������head��tail����ת����������Ǻ����������Ĳ��������ġ�
	pair<ListNode*, ListNode*> reverseList(ListNode* head, int k){
		ListNode *pre = NULL, *p = head;
		int cnt = 0;
		while(p && cnt < k){
			ListNode *tmp = p->next;
			p->next = pre;
			pre = p;
			p = tmp;
			cnt++;
		}
		head->next = p;                   //�ѷ�ת�������������������Ĳ���������
		if(cnt == k){
			return make_pair(pre, head);
		} else {
			return reverseList(pre, cnt); //����k������ԭԭ����˳��
		}
	}
};