/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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
/*����1��*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
		return isSymmetricRecur(root->left, root->right);
    }
	bool isSymmetricRecur(TreeNode* p, TreeNode* q){
		if(p && q){
			if(p->val == q->val && isSymmetricRecur(p->left, q->right) && isSymmetricRecur(p->right, q->left))
				return true;
			else 
				return false;
		} else if(p || q){
			return false;
		} else {
			return true;
		}
	}
};

/*����2���ǵݹ�ⷨ�����������зֱ𱣴��������ڵ���������ڵ㣬ÿ�δ����������зֱ�ȡ��Ԫ�أ��������Ԫ�ص�ֵ��ȣ�����������ǵ����ҽڵ�������Ҷ��С�*/ 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
		queue<TreeNode*> leftQueue, rightQueue;
		TreeNode* p = root;
		if(p->left) leftQueue.push(p->left);
		if(p->right) rightQueue.push(p->right);
		while(!leftQueue.empty() && !rightQueue.empty()){
			TreeNode* leftP = leftQueue.front();
			TreeNode* rightP = rightQueue.front();
			leftQueue.pop();
			rightQueue.pop();
			if(leftP->val == rightP->val){
				if(leftP->left && rightP->right){
					leftQueue.push(leftP->left);
					rightQueue.push(rightP->right);
				} else if(leftP->left || rightP->right){
					return false;
				}
				if(leftP->right && rightP->left){
					leftQueue.push(leftP->right);
					rightQueue.push(rightP->left);
				} else if(leftP->right || rightP->left){
					return false;
				}
			} else {
				return false;
			}
		}
		if(leftQueue.empty() && rightQueue.empty())
			return true;
		else
			return false;
    }
};