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
算法1：暴力解决，先1、2合并，12结果和3合并，123结果和4合并，…,123..k-1结果和k合并，我们计算一下复杂度。
1、2合并，遍历2n个节点
12结果和3合并，遍历3n个节点
123结果和4合并，遍历4n个节点
…
123..k-1结果和k合并，遍历kn个节点
总共遍历的节点数目为n(2+3+…+k) = n*(k^2+k-2)/2, 因此时间复杂度是O(nk^2)
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
算法2：利用分治思想，把合并K个链表分成合并两个K/2个链表的任务，再以此类推，一直划分，直到链表中只剩下一个或者两个链表。
1：可以用递归，算法复杂度为O（nklogk）
2：下面是非递归的思想（以四个链表为例）
	1、3合并，合并结果放到1的位置
	2、4合并，合并结果放到2的位置
	再把1、2合并（相当于原来的13 和 24合并）
	最后返回1
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		int n = lists.size();
		if(n == 0) return NULL;
		//当n=1时结束，此时已合并成一个链表
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
算法3：
维护一个k个大小的最小堆，初始化堆中元素为每个链表的头结点，每次从堆中选择最小的元素加入到结果链表，再选择该最小元素所在链表的下一个节点加入到堆中。
这样当堆为空时，所有链表的节点都已经加入了结果链表。元素加入堆中的复杂度为O（longk），总共有kn个元素加入堆中，因此，复杂度也和算法2一样是O（nklogk）
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