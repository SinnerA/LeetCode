/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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

/*只要把比x小的节点按顺序连成一条链，比x大或等于的节点连成另一条链，然后把两条链连起来。注意一下边界情况(某条链为空)*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		ListNode* p = head, *lhead = NULL, *ghead = NULL;
		ListNode* lessP = NULL, *greaterP = NULL;
		while(p){
			if(p->val < x){
				if(lessP){
					lessP->next = p;
					lessP = lessP->next;
				} else {
					lessP = p;
					lhead = p;
				}
			} else {
				if(greaterP){
					greaterP->next = p;
					greaterP = greaterP->next;
				} else{
					greaterP = p;
					ghead = p;
				}
			}
			p = p->next;
		}
		if(greaterP)
			greaterP->next = NULL;
		
		if(!lhead){
			return ghead;
		} else {
			lessP->next = ghead;
			return lhead;
		}
    }
};