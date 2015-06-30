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
利用快慢指针判断出是否有环后，还需要找出环的起点，分析如下：

1、设链表长度为len（链表中非空next指针的个数，下面所说的长度均为非空next指针的个数），链表head到环的起点长度为a，环起点到快慢指针相遇点的长度为b，环的长度为r。
2、假设到快慢指针相遇时，慢指针移动的长度为s，则快指针移动长度为2s，而快指针移动的长度还等于s加上在环上绕的k圈（k>=1）,所以2s=s+kr ，即s = kr。
3、由s = a + b 和 s = kr 可知 a + b = kr = (k-1)r + r； 而r = len - a，所以a + b = (k-1)r + len - a, 即 a = (k-1)r + len - a - b，
   len - a - b是相遇点到环的起点的长度，由此可知，从链表头到环起点长度 = (k-1)环长度+从相遇点到环起点长度，于是我们从链表头、与相遇点分别设一个指针，每次各走一步，两个指针必定相遇，且相遇点为环起点。
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
			//存在环，寻找环的起点
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