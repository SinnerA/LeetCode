/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

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
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
		stack<TreeNode*> S;
		S.push(root);
		TreeNode* pre = NULL;
		while(!S.empty()){
			TreeNode *p = S.top();
			S.pop();
			if(p->right) S.push(p->right);
			if(p->left) S.push(p->left);
			if(pre){
				pre->right = p;
				pre->left = NULL;
			}
			pre = p;
		}
		pre->left = NULL;
		pre->right = NULL;
    }
};