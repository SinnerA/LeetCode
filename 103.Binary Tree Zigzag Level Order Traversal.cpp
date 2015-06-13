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
���ȿ϶�����Ҫ�������в���������������������Ԫ�ر���˳�����෴�ģ���˴�ͳ�ķǵݹ����������һ�����п϶����޷�ʵ�֡�
����������ջ��ʵ�֣�ͬһ��Ԫ�ض���ͬһ��ջ�У����ڵ�����Ԫ�ط��ڲ�ͬ��ջ�У�
�����һ��Ԫ�ط��ڵ�һ��ջ����ô�ڶ���ͷ��ڵڶ���ջ��������ͷ��ڵ�����ջ......
���ĳһ��Ԫ���Ǵ������ұ����ģ���ô���Ԫ�صĺ��ӽڵ���ջ˳����������Ӻ��Һ��ӣ��෴���ĳһ��Ԫ���Ǵ�����������ģ���ջ˳��������Һ��Ӻ����ӡ�
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