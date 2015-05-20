/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

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
 
/*根据BST的中序遍历序列是有序的，在中序遍历二叉树的代码上加上判断相邻元素的大小即可*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
		stack<TreeNode*> myStack;
		TreeNode *pre = NULL, *p = root;
		while(p || !myStack.empty()){
			while(p){
				myStack.push(p);
				p = p->left;
			}
			if(!myStack.empty()){
				p = myStack.top();
				myStack.pop();
				if(pre && pre->val >= p->val) return false;
				pre = p;
				p = p->right;
			}
		}
		return true;
    }
};