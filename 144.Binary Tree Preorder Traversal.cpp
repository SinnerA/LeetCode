/*
Given a binary tree, return the preorder traversal of its nodes' values.
	
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

Tags: Tree Stack
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

/*方法一：使用栈*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
		if(root == NULL) return res;
		stack<TreeNode*> myStack;
		TreeNode* p = root;
		while(p || !myStack.empty()){
			while(p){
				res.push_back(p->val);
				myStack.push(p);
				p = p->left;
			}
			if(!myStack.empty()){
				p = myStack.top();
				myStack.pop();
				p = p->right;
			}
		}
		return res;
    }
};

/*
方法二：利用线索二叉树，参考题94
http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
http://yingshin.github.io/algorithm/2014/03/26/morris-traversal-binary-tree/
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。输出当前节点（在这里输出，这是与中序遍历唯一一点不同）。当前节点更新为当前节点的左孩子。
   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。当前节点更新为当前节点的右孩子。
3. 重复以上1、2直到当前节点为空。

注意：前序两次访问的时间：
1. 没有左子树遍历右子树之前
2. 有左子树第一次遍历到根节点,下一步会遍历左子树。
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
		if(root == NULL) return res;
		TreeNode *p = root, *pre = NULL;
		while(p){
			if(p->left == NULL){
				res.push_back(p->val);
				p = p->right;
			} else {
				pre = p->left;
				while(pre->right && pre->right != p){
					pre = pre->right;
				}
				if(pre->right == NULL){
					res.push_back(p->val);
					pre->right = p;
					p = p->left;
				} else {
					pre->right = NULL;
					p = p->right;
				}
			}
		}
    }
};