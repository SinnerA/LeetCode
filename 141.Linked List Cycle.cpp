/*
Given a linked list, determine if it has a cycle in it.

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

/*算法1：利用快慢指针，开始两个指针均指向链表head，然后循环移动，慢指针移动1步，快指针则移动2步，如果链表有环则两个指针一定会相遇。*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
		ListNode *fast = head, *slow = head;
		while(fast && fast->next){
			fast = fast->next->next;
			slow = slow->next;
			if(slow == fast) return true;
		}
		return false;
    }
};

/*算法二：还可以用倒转链表的方法来判断是否有环，沿着链表遍历，每次遍历把指针倒转，如果有环最后一定会回到head节点。不过这样会破坏链表结构 ，需要恢复。*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
		ListNode *pre = head, *p = head->next;
		while(p){
			if(p == head) return true;
			ListNode *temp = p->next;
			p->next = pre;
			pre = p;
			p = temp;
		}
		return false;
    }
};