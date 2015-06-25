/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
Tags: Tree Hash Table Stack
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

/*
方法一：使用栈的非递归中序遍历，注意到每次要先遍历当前节点最左节点
http://www.2cto.com/kf/201407/314705.html
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
		if(root == NULL) return res;
		stack<TreeNode*> myStack;
		TreeNode* p = root;
		while(p || !myStack.empty()){
			while(p){
				myStack.push(p);
				p = p->left;
			}
			if(!myStack.empty()){
				p = myStack.top();
				res.push_back(p->val);
				myStack.pop();
				p = p->right;
			}
		}
		return res;
    }
};

/*
方法二：Morris Traversal算法，他是基于线索二叉树，它利用二叉树节点中闲置的右指针指向该节点在中序序列中的后缀节点。
http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
http://yingshin.github.io/algorithm/2014/03/26/morris-traversal-binary-tree/
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
3. 重复以上1、2直到当前节点为空。

注意：中序两次访问的时间：
1. 没有左子树遍历右子树之前
2. 有左子树第二次遍历到根节点，表示遍历左子树已经返回。
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
					pre->right = p;
					p = p->left;
				} else {
					pre->right = NULL;
					res.push_back(p->val);
					p = p->right;
				}
			}
		}
		return res;
    }
};