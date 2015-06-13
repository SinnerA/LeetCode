/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
	TreeNode* build(Iter ibegin, Iter iend, Iter pbegin, Iter pend){
		if(ibegin == iend) return NULL;
		int rootVal = *(pend - 1);
		TreeNode* root = new TreeNode(rootVal);
		Iter rootIter = find(ibegin, iend, rootVal);
		root->left = build(ibegin, rootIter, pbegin, pbegin + (rootIter - ibegin));
		root->right = build(rootIter + 1, iend, pbegin + (rootIter - ibegin), pend - 1);
		return root;
	}
};