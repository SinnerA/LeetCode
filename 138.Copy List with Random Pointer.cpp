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
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
		unordered_map<RandomListNode*, RandomListNode*> oldListMap;
		
		RandomListNode* newHead = new RandomListNode(head->label);
		RandomListNode* pold = head, *pnew = newHead;
		pnew->random = pold; //以便后面while后的操作
		RandomListNode* preOld = pold, *preNew = pnew;
		
		while(pold->next){
			oldListMap.insert(make_pair(pold, pold->next));
			pold = pold->next;
			preOld->next = pnew;
			pnew = new RandomListNode(pold->label);
			preNew->next = pnew;
			pnew->random = preOld;
			
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