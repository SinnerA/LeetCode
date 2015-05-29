/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

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
 
//算法1：递归
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
		if(root == NULL) return sum;
		vector<int> res;
		int tempRes = root->val;
		dfs(root, res, tempRes);
		for(vector<int>::iterator it = res.begin(); it != res.end(); it++)
			sum += *it;
		return sum;
    }
	void dfs(TreeNode* root, vector<int>& res, int &tempRes){
		if(root->left == NULL && root->right == NULL){
			res.push_back(tempRes);
			return;
		}
		if(root->left){
		    int savedTempRes = tempRes;
		    tempRes = tempRes*10 + root->left->val;
		    dfs(root->left, res, tempRes);
		    tempRes = savedTempRes;
		}
		if(root->right){
		    int savedTempRes = tempRes;
		    tempRes = tempRes*10 + root->right->val;
		    dfs(root->right, res, tempRes);
		    tempRes = savedTempRes;
		}
	}
};

//算法2：非递归，新建数据结构，运用队列
class Solution {
private:
	struct Qnode{
		TreeNode* p;
		int sum;
		Qnode(TreeNode* p_, int sum_):p(p_),sum(sum_){};
		Qnode(){};
	};
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
		if(root == NULL) return res;
		queue<Qnode> myQueue;
		myQueue.push(Qnode(root, root->val));
		while(!myQueue.empty()){
			Qnode node = myQueue.front();
			myQueue.pop();
			if(node.p->left == NULL && node.p->right == NULL){
				res += node.sum;
			} else {
				if(node.p->left)
					myQueue.push(Qnode(node.p->left, node.sum*10 + node.p->left->val));
				if(node.p->right)
					myQueue.push(Qnode(node.p->right, node.sum*10 + node.p->right->val));
			}
		}
		return res;
    }
};