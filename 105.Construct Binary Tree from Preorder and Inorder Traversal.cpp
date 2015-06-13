/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Tags: Tree Array Depth-first Search
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
	typedef vector<int>::iterator Iter;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
	TreeNode* build(Iter pbegin, Iter pend, Iter ibegin, Iter iend){
		if(pbegin == pend) return NULL;
		int rootVal = *pbegin;
		TreeNode* root = new TreeNode(rootVal);
		Iter rootIter = find(ibegin, iend, rootVal);
		root->left = build(pbegin + 1, pbegin + 1 + (rootIter - ibegin), ibegin, rootIter);
		root->right = build(pbegin + 1 + (rootIter - ibegin), pend, rootIter + 1, iend);
		return root;
	}
};