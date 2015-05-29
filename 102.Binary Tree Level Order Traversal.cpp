/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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

//队列辅助层序遍历，队列中插入NULL作为层与层之间的间隔，注意处理队列里最后的NULL时，不能再把它入队列以免形成死循环
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
		if(root == NULL) return res;
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		myQueue.push(NULL); //NULL为一层的分隔符
		vector<int> tempRes;
		while(!myQueue.empty()){
			TreeNode* p = myQueue.front();
			myQueue.pop();
			if(p != NULL){
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
		return res;
    }
};