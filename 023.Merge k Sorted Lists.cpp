/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Tags: Divide and Conquer Linked List Heap
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
�㷨1�������������1��2�ϲ���12�����3�ϲ���123�����4�ϲ�����,123..k-1�����k�ϲ������Ǽ���һ�¸��Ӷȡ�
1��2�ϲ�������2n���ڵ�
12�����3�ϲ�������3n���ڵ�
123�����4�ϲ�������4n���ڵ�
��
123..k-1�����k�ϲ�������kn���ڵ�
�ܹ������Ľڵ���ĿΪn(2+3+��+k) = n*(k^2+k-2)/2, ���ʱ�临�Ӷ���O(nk^2)
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
		if(n == 0) return NULL;
		ListNode* res = lists[0];
		for(int i = 1; i < n; i++)
			res = mergeTwoList(res, lists[i]);
		return res;
    }
	ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
		ListNode node(0);
		ListNode* head = &node, *p = head;
		while(l1 && l2){
			if(l1->val <= l2->val){
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if(l1)
			p->next = l1;
		if(l2)
			p->next = l2;
		return head->next;
	}
};
 
/*
�㷨2�����÷���˼�룬�Ѻϲ�K������ֳɺϲ�����K/2��������������Դ����ƣ�һֱ���֣�ֱ��������ֻʣ��һ��������������
1�������õݹ飬�㷨���Ӷ�ΪO��nklogk��
2�������Ƿǵݹ��˼�루���ĸ�����Ϊ����
	1��3�ϲ����ϲ�����ŵ�1��λ��
	2��4�ϲ����ϲ�����ŵ�2��λ��
	�ٰ�1��2�ϲ����൱��ԭ����13 �� 24�ϲ���
	��󷵻�1
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		int n = lists.size();
		if(n == 0) return NULL;
		//��n=1ʱ��������ʱ�Ѻϲ���һ������
		while(n > 1){
			int k = (n + 1) / 2;
			for(int i = 0; i < n/2; i++)
				lists[i] = mergeTwoList(lists[i], lists[i + k]);
			n = k;
		}
		return lists[0];
    }
	ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
		ListNode node(0);
		ListNode* head = &node;
		ListNode* p = head;
		while(l1 && l2){
			if(l1->val <= l2->val){
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if(l1)
			p->next = l1;
		if(l2)
			p->next = l2;
		return head->next;
	}
};

/*
�㷨3��
ά��һ��k����С����С�ѣ���ʼ������Ԫ��Ϊÿ�������ͷ��㣬ÿ�δӶ���ѡ����С��Ԫ�ؼ��뵽���������ѡ�����СԪ�������������һ���ڵ���뵽���С�
��������Ϊ��ʱ����������Ľڵ㶼�Ѿ������˽������Ԫ�ؼ�����еĸ��Ӷ�ΪO��longk�����ܹ���kn��Ԫ�ؼ�����У���ˣ����Ӷ�Ҳ���㷨2һ����O��nklogk��
*/
class Solution {
private:
	struct cmp{
		bool operator()(const ListNode* a, const ListNode* b){
			return a->val > b->val;
		}
	};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		int n = lists.size();
		if(n == 0) return NULL;
		ListNode node(0);
		ListNode *head = &node, *p = head;
		priority_queue<ListNode*, vector<ListNode*>, cmp> myQueue;
		for(int i = 0; i < n; i++)
			if(lists[i])
				myQueue.push(lists[i]);
		while(!myQueue.empty()){
			ListNode* q = myQueue.top();
			myQueue.pop();
			p->next = q;
			p = q;
			
			if(q->next != NULL)
				myQueue.push(q->next);
		}
		return head->next;
    }
};