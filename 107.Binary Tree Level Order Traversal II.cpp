/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

Tags: Tree Breadth-first Search
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
 
//����Ŀ��Binary Tree Level Order Traversal�������ϣ����ת���
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
		if(root == NULL) return res;
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		myQueue.push(NULL);
		vector<int> tempRes;
		while(!myQueue.empty()){
			TreeNode* p = myQueue.front();
			myQueue.pop();
			if(p){
				tempRes.push_back(p->val);
				if(p->left) myQueue.push(p->left);
				if(p->right) myQueue.push(p->right);
			} else {
				res.push_back(tempRes);
				if(!myQueue.empty()){
					tempRes.clear();
					myQueue.push(NULL);
				}
			}
		}
		reverse(res.begin(), res.end());
		return res;
    }
};