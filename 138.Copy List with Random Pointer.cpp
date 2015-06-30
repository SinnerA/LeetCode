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
算法1：我们在构建新链表的节点时，保存原始链表的next指针映射关系，并把指针做如下变化(蓝色为原始链表节点，紫红色为新链表节点)：
参考：http://www.cnblogs.com/TenosDoIt/p/3387000.html

然后在上图的基础上进行如下两步
1、构建新链表的random指针：比如new1->random = new1->random->random->next, new2->random = NULL, new3-random = NULL, new4->random = new4->random->random->next
2、恢复原始链表：根据最开始保存的原始链表next指针映射关系恢复原始链表

该算法时间空间复杂度均为O(N)
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
算法2：该算法更为巧妙，不用保存原始链表的映射关系，构建新节点时，指针做如下变化，即把新节点插入到相应的旧节点后面：
参考：http://www.cnblogs.com/TenosDoIt/p/3387000.html

同理分两步
1、构建新节点random指针：new1->random = old1->random->next, new2-random = NULL, new3-random = NULL, new4->random = old4->random->next
2、恢复原始链表以及构建新链表：例如old1->next = old1->next->next,  new1->next = new1->next->next

该算法时间复杂度O(N)，空间复杂度O(1)
*/