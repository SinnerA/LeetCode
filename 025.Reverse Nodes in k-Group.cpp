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

/*每次选取好一个group后,调用翻转链表子函数翻转该group*/
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