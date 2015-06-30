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

/*方法一：每次选取好一个group后,调用翻转链表子函数翻转该group*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode tmpHead(0);
		ListNode *p = head, *tail = &tmpHead;//tail表示当前已处理完的尾节点
		
		while(p){
			ListNode *groupHead = p;
			int i;
			for(i = 1; i < k && p->next != NULL; i++) p = p->next;
			if(i < k){
				//不足k个节点
				tail->next = groupHead;
				return tmpHead.next;
			}
			p = p->next;
			pair<ListNode*, ListNode*> headtailPair = reverseList(groupHead, p);
			tail->next = headtailPair.first; //第一次翻转链表之后，tail->next即tmpHead.next指向新的链表头结点，作为返回值
			tail = headtailPair.second;
		}
		return tmpHead.next;
    }
	
	//翻转链表,并返回翻转后链表的头结点和尾节点
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


/*方法二：上面的方法实际上遍历了2遍链表,可以稍加改进在计数k个链表的过程中就开始翻转, 最后部分如果不足k个节点,则还原原来的顺序*/
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
	
	//翻转从head开始的k个链表节点，如果不足k个则不翻转，返回翻转后的这k个节点
    //子链表的head和tail。翻转后的子链表还是和子链表后面的部分相连的。
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
		head->next = p;                   //把翻转后的子链表和子链表后面的部分连起来
		if(cnt == k){
			return make_pair(pre, head);
		} else {
			return reverseList(pre, cnt); //不足k个，还原原来的顺序
		}
	}
};