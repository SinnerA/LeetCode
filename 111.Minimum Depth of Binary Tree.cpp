/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
 
/*
算法1：dfs递归
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
		int res = INT_MAX;
		dfs(root, 1, res);
		return res;
    }
	void dfs(TreeNode* root, int depth, int &res){
		if(root->left == NULL && root->right == NULL && res > depth){
			res = depth;
			return;
		}
		if(root->left != NULL)
			dfs(root->left, depth + 1, res);
		if(root->right != NULL)
			dfs(root->right, depth + 1, res);
	}
};

//分别求左右子树的最小深度，然后返回左右子树的最小深度中较小者+1
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
		int leftDepth = minDepth(root->left);
		int rightDepth = minDepth(root->right);
		if(leftDepth == 0) return rightDepth + 1;
		if(rightDepth == 0) return leftDepth + 1;
		return min(leftDepth, rightDepth) + 1;
    }
};

/*
算法2：层次遍历，找到最先遍历到叶子的层数就是最小高度
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
		int res = 0;
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		myQueue.push(NULL); //NULL作为每一层节点的分割标志
		while(!myQueue.empty()){
			TreeNode* p = myQueue.front();
			myQueue.pop();
			if(p){
				if(p->left) myQueue.push(p->left);
				if(p->right) myQueue.push(p->right);
				if(p->left == NULL && p->right == NULL){
					res++;
					break;
				}
			} else {
				//遍历完一层
				res++;
				if(!myQueue.empty()) 
					myQueue.push(NULL); //所有下一层节点已经加入队列，则加上结束标记
			}
		}
		return res;
    }
};