/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Tags: Hash Table Linked List
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
/*
�㷨1�������ڹ���������Ľڵ�ʱ������ԭʼ�����nextָ��ӳ���ϵ������ָ�������±仯(��ɫΪԭʼ����ڵ㣬�Ϻ�ɫΪ������ڵ�)��
�ο���http://www.cnblogs.com/TenosDoIt/p/3387000.html

Ȼ������ͼ�Ļ����Ͻ�����������
1�������������randomָ�룺����new1->random = new1->random->random->next, new2->random = NULL, new3-random = NULL, new4->random = new4->random->random->next
2���ָ�ԭʼ���������ʼ�����ԭʼ����nextָ��ӳ���ϵ�ָ�ԭʼ����

���㷨ʱ��ռ临�ӶȾ�ΪO(N)
*/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
		unordered_map<RandomListNode*, RandomListNode*> oldListMap;
		
		RandomListNode* newHead = new RandomListNode(head->label);
		RandomListNode* pold = head, *pnew = newHead;
		pnew->random = pold; //�Ա����while��Ĳ���
		RandomListNode* preOld = pold, *preNew = pnew;
		
		while(pold->next){
			oldListMap.insert(make_pair(pold, pold->next));
			pold = pold->next;
			preOld->next = pnew;
			pnew = new RandomListNode(pold->label);
			preNew->next = pnew;
			pnew->random = pold;
			
			preOld = pold;
			preNew = pnew;
		}
		pold->next = pnew;
		
		RandomListNode* p = newHead;
		while(p){
			if(p->random->random)
				p->random = p->random->random->next;
			else
				p->random = NULL;
			p = p->next;
		}
		
		p = head;
		for(int i = 0; i < oldListMap.size(); i++){
			p->next = oldListMap[p];
			p = p->next;
		}
		p->next = NULL;
		
		return newHead;
    }
};

/*
�㷨2�����㷨��Ϊ������ñ���ԭʼ�����ӳ���ϵ�������½ڵ�ʱ��ָ�������±仯�������½ڵ���뵽��Ӧ�ľɽڵ���棺
�ο���http://www.cnblogs.com/TenosDoIt/p/3387000.html

ͬ�������
1�������½ڵ�randomָ�룺new1->random = old1->random->next, new2-random = NULL, new3-random = NULL, new4->random = old4->random->next
2���ָ�ԭʼ�����Լ���������������old1->next = old1->next->next,  new1->next = new1->next->next

���㷨ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(1)
*/