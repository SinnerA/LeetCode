/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

Tags: Tree Stack
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
��������ݹ鶨�壺���������������������ٸ��ڵ㡣
����������ѵ����ڣ���Ҫ�ж��ϴη��ʵĽڵ���λ����������������������
����λ���������������������ڵ㣬�Ƚ������������ٻ�ͷ���ʸ��ڵ㣻����λ������������ֱ�ӷ��ʸ��ڵ㡣
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
		if(root == NULL) return res;
		TreeNode* p = root, *pLast = NULL;
		stack<TreeNode*> myStack;
		while(p){
			myStack.push(p);
			p = p->left;
		}
		while(!myStack.empty()){
			p = myStack.top();
			myStack.pop();
			//�������Һ��ӻ��Һ����ѷ���
			if(!p->right || p->right == pLast){
				res.push_back(p->val);
				pLast = p;
			} else {
				myStack.push(p);
				p = p->right;
				while(p){
					myStack.push(p);
					p = p->left;
				}
			}
		}
		return res;
    }
};