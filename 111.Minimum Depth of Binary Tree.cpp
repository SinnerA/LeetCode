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
�㷨1��dfs�ݹ�
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

//�ֱ���������������С��ȣ�Ȼ�󷵻�������������С����н�С��+1
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
�㷨2����α������ҵ����ȱ�����Ҷ�ӵĲ���������С�߶�
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
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
				if(p->left == NULL && p->right == NULL){
					res++;
					break;
				}
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