/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
	typedef vector<int>::iterator Iter;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums.begin(), nums.end());
    }
	TreeNode* build(Iter begin, Iter end){
		if(begin == end) return NULL;
		Iter rootIter = begin + (end - begin) / 2;
		int rootVal = *rootIter;
		TreeNode* root = new TreeNode(rootVal);
		root->left = build(begin, rootIter);
		root->right = build(rootIter + 1, end);
		return root;
	}
};