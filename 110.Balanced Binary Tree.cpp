/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
 
/*判断一颗二叉树是否是平衡的，dfs递归求解，递归的过程中顺便求得树的高度*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
		if(height(root) == -1) return false;
		else return true;
    }
	int height(TreeNode* root){
		if(root->left == NULL && root->right == NULL) return 1;
		int leftHeight = 0, rightHeight = 0;
		if(root->left)
			leftHeight = height(root->left);
		if(leftHeight == -1) return -1;
		if(root->right)
			rightHeight = height(root->right);
		if(rightHeight == -1) return -1;
		if(abs(leftHeight - rightHeight) > 1) return -1;
		return 1 + max(leftHeight, rightHeight);
	}
};