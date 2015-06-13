/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Tags: Tree Breadth-first Search Stack
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
首先肯定的是要对树进行层序遍历，但是相邻两层的元素遍历顺序是相反的，因此传统的非递归遍历方法用一个队列肯定是无法实现。
我们用两个栈来实现，同一层元素都在同一个栈中，相邻的两层元素放在不同的栈中，
比如第一层元素放在第一个栈，那么第二层就放在第二个栈，第三层就放在第三个栈......
如果某一层元素是从左往右遍历的，那么这层元素的孩子节点入栈顺序就是先左孩子后右孩子，相反如果某一层元素是从右往左遍历的，入栈顺序就是先右孩子后左孩子。
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
		if(root == NULL) return res;
		stack<TreeNode*> S1, S2;
		S1.push(root);
		vector<int> tempRes;
		bool isS1 = true;
		
		while(!S1.empty() || !S2.empty()){
			TreeNode* p;
			if(isS1){
				p = S1.top();
				S1.pop();
				tempRes.push_back(p->val);
				if(p->left) S2.push(p->left);
				if(p->right) S2.push(p->right);
				if(S1.empty()){
					res.push_back(tempRes);
					tempRes.clear();
					isS1 = false;
				}
			} else {
				p = S2.top();
				S2.pop();
				tempRes.push_back(p->val);
				if(p->right) S1.push(p->right);
				if(p->left) S1.push(p->left);
				if(S2.empty()){
					res.push_back(tempRes);
					tempRes.clear();
					isS1 = true;
				}
			}
		}
		return res;
    }
};