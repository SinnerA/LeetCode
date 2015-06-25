/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
 
/*
后序遍历递归定义：先左子树，后右子树，再根节点。
后序遍历的难点在于：需要判断上次访问的节点是位于左子树，还是右子树。
若是位于左子树，则需跳过根节点，先进入右子树，再回头访问根节点；若是位于右子树，则直接访问根节点。
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
		if(root == NULL) return res;
		TreeNode* p = root, *pLast = NULL;
		stack<TreeNode*> myStack;
		while(p){
			myStack.push(p);
			p = p->left;
		}
		while(!myStack.empty()){
			p = myStack.top();
			myStack.pop();
			//不存在右孩子或右孩子已访问
			if(!p->right || p->right == pLast){
				res.push_back(p->val);
				pLast = p;
			} else {
				myStack.push(p);
				p = p->right;
				while(p){
					myStack.push(p);
					p = p->left;
				}
			}
		}
		return res;
    }
};