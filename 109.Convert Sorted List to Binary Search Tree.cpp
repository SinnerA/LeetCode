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
/*����1�����ÿ���ָ���ҵ��������м�ڵ�*/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
		if(head == NULL) return NULL;
		ListNode *fast = head, *slow = head, *preSlow = NULL;
		while(fast->next && fast->next->next){
			fast = fast->next->next;//������
			preSlow = slow;
			slow = slow->next;      //��һ��
		}
		TreeNode *root = new TreeNode(slow->val);
		fast = slow->next;
		//delete slow;   //�����������Ϊslowָ��ListNode�ṹ�壬��ListNode���Լ����������������Զ�����delete����ɶ���delete
		if(preSlow != NULL){
			preSlow->next = NULL;
			root->left = sortedListToBST(head);
		}
		root->right = sortedListToBST(fast);
		return root;
    }
};

/*����2�������ҵ��������м�ڵ�*/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head);
    }
	TreeNode* build(ListNode* head){
		if(head == NULL) return NULL;
		
		//����������
		int len = 0;
		ListNode *p = head, *q = head;
		while(p){
			len++;
			p = p->next;
		}
		
		//��ֳ���������������
		int dist = (len == 2) ? len / 2 : (len - 1) / 2; //��len==2ʱ�����⴦��
		p = head;
		while(dist--){
			q = p;
			p = p->next;//qָ����ڵ�
		}
		q->next = NULL; //qָ�������������һ��Ԫ��
		
		TreeNode* root = new TreeNode(p->val);
		ListNode* leftHead = (p == head) ? NULL : head;    //ֻʣ�¸��ڵ㣬����ڵ�ΪNULL
		ListNode* rightHead = (p == head) ? NULL : p->next;//ֻʣ�¸��ڵ㣬���ҽڵ�ΪNULL
		root->left = build(leftHead);
		root->right = build(rightHead);
		return root;
	}
};