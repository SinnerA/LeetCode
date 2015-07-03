/*
Sort a linked list in O(n log n) time using constant space complexity.

Tags: Linked List Sort
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
nlogn的排序有快速排序、归并排序、堆排序。
双向链表用快排比较适合，堆排序也可以用于链表，单向链表适合用归并排序。以下是用归并排序的代码
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
		ListNode *fast = head, *slow = head, *preSlow = NULL;
		//快慢指针找到中间节点
		while(fast != NULL && fast->next != NULL){
			preSlow = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		preSlow->next = NULL;
		ListNode* firstList = sortList(head);   //前半段排序
		ListNode* secondList = sortList(slow);  //后半段排序
		head = mergeList(firstList, secondList);//前后合并
		return head;
    }
	ListNode* mergeList(ListNode *head1, ListNode *head2){
		if(head1 == NULL) return head2;
		if(head2 == NULL) return head1;
		ListNode *res, *p;
		if(head1->val <= head2->val){
			res = head1;
			head1 = head1->next;
		} else {
			res = head2;
			head2 = head2->next;
		}
		p = res;
		
		while(head1 && head2){
			if(head1->val <= head2->val){
				p->next = head1;
				head1 = head1->next;
			} else {
				p->next = head2;
				head2 = head2->next;
			}
			p = p->next;
		}
		if(head1) p->next = head1;
		else p->next = head2;
		return res;
	}
};