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
 
/*方法一：使用栈的非递归中序遍历*/
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

/*方法二：不使用栈的非递归中序遍历*/
