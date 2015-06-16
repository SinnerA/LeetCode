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
 
/*方法1：递归*/
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
方法2：通过层序遍历，分别用两个队列保存两棵树的层序节点。
每次从两个队列中分别取出一个元素，如果他们的值相同，再继续遍历子节点。注意每次取出的两个元素的左子树要么同时非空，要么同时为空，右子树也一样
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