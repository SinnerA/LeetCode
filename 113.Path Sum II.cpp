/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
		if(root == NULL) return res;
		vector<int> tempRes;
		tempRes.push_back(root->val);
		dfs(root, sum, res, tempRes);
		return res;
    }
	void dfs(TreeNode *root, int sum, vector<vector<int> > &res, vector<int> &tempRes){
		if(root->val == sum && root->left == NULL && root->right == NULL){
			res.push_back(tempRes);
			return;
		}
		if(root->left){
			tempRes.push_back(root->left->val);
			dfs(root->left, sum - root->val, res, tempRes);
			tempRes.pop_back();
		}
		if(root->right){
			tempRes.push_back(root->right->val);
			dfs(root->right, sum - root->val, res, tempRes);
			tempRes.pop_back();
		}
	}
};