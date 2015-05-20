/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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

/*�㷨1��dfs�ݹ�*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
		int res = INT_MIN;
		dfs(root, 1, res);
		return res;
    }
	void dfs(TreeNode* root, int depth, int& res){
		if(root->left == NULL && root->right == NULL && res < depth)
			res = depth;
		if(root->left != NULL)
			dfs(root->left, depth + 1, res);
		if(root->right != NULL)
			dfs(root->right, depth + 1, res);
	}
};

//�ֱ�����������������߶ȣ�Ȼ�󷵻ؽϴ��� + 1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
		int maxLeftDepth = maxDepth(root->left);
		int maxRightDepth = maxDepth(root->right);
		if(maxLeftDepth == 0) return maxRightDepth + 1;
		if(maxRightDepth == 0) return maxLeftDepth + 1;
		return max(maxLeftDepth, maxRightDepth) + 1;
    }
};

//�㷨2����������������ܲ����������߶�
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
		int res = 0;
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		myQueue.push(NULL); //NULL��Ϊÿһ��ڵ�ķָ��־
		while(!myQueue.empty()){
			TreeNode* p = myQueue.front();
			myQueue.pop();
			if(p){
				if(p->left) myQueue.push(p->left);
				if(p->right) myQueue.push(p->right);
			} else {
				//������һ��
				res++;
				if(!myQueue.empty())
					myQueue.push(NULL); //������һ��ڵ��Ѿ�������У�����Ͻ������
			}
		}
		return res;
    }
};