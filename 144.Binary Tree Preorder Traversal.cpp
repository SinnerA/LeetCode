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

/*方法二：利用线索二叉树，参考题94*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
		if(root == NULL) return res;
		
    }
};