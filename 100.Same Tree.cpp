/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Tags: Tree Depth-first Search
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
 
/*����1���ݹ�*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if(p && q){
			if(p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
				return true;
			else
				return false;
		} else if(p || q){
			return false;
		} else {
			return true;
		}
    }
};

/*
����2��ͨ������������ֱ����������б����������Ĳ���ڵ㡣
ÿ�δ����������зֱ�ȡ��һ��Ԫ�أ�������ǵ�ֵ��ͬ���ټ��������ӽڵ㡣ע��ÿ��ȡ��������Ԫ�ص�������Ҫôͬʱ�ǿգ�ҪôͬʱΪ�գ�������Ҳһ��
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		queue<TreeNode*> pQueue, qQueue;
		if(p) pQueue.push(p);
		if(q) qQueue.push(q);
		while(!pQueue.empty() && !qQueue.empty()){
			TreeNode* p = pQueue.front();
			TreeNode* q = qQueue.front();
			pQueue.pop();
			qQueue.pop();
			if(p->val == q->val){
				if(p->left && q->left){
					pQueue.push(p->left);
					qQueue.push(q->left);
				} else if(p->left || q->left){
					return false;
				}
				if(p->right && q->right){
					pQueue.push(p->right);
					qQueue.push(q->right);
				} else if(p->right || q->right){
					return false;
				}
			} else {
				return false;
			}
		}
		if(pQueue.empty() && qQueue.empty())
			return true;
		else
			return false;
    }
};