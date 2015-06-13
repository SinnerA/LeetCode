/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Tags: Depth-first Search Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head);
    }
	TreeNode* build(ListNode* head){
		if(head == NULL) return NULL;
		
		//求链表长度
		int len = 0;
		ListNode *p = head, *q = head;
		while(p){
			len++;
			p = p->next;
		}
		
		//拆分成左右两个子链表
		int dist = (len == 2) ? len / 2 : (len - 1) / 2; //当len==2时，特殊处理
		p = head;
		while(dist--){
			q = p;
			p = p->next;//q指向根节点
		}
		q->next = NULL; //q指向左链表的最后一个元素
		
		TreeNode* root = new TreeNode(p->val);
		ListNode* leftHead = (p == head) ? NULL : head;    //只剩下根节点，则左节点为NULL
		ListNode* rightHead = (p == head) ? NULL : p->next;//只剩下根节点，则右节点为NULL
		root->left = build(leftHead);
		root->right = build(rightHead);
		return root;
	}
};








