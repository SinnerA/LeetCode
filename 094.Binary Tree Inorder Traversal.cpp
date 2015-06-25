/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
Tags: Tree Hash Table Stack
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
����һ��ʹ��ջ�ķǵݹ����������ע�⵽ÿ��Ҫ�ȱ�����ǰ�ڵ�����ڵ�
http://www.2cto.com/kf/201407/314705.html
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
		if(root == NULL) return res;
		stack<TreeNode*> myStack;
		TreeNode* p = root;
		while(p || !myStack.empty()){
			while(p){
				myStack.push(p);
				p = p->left;
			}
			if(!myStack.empty()){
				p = myStack.top();
				res.push_back(p->val);
				myStack.pop();
				p = p->right;
			}
		}
		return res;
    }
};

/*
��������Morris Traversal�㷨�����ǻ��������������������ö������ڵ������õ���ָ��ָ��ýڵ������������еĺ�׺�ڵ㡣
http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
http://yingshin.github.io/algorithm/2014/03/26/morris-traversal-binary-tree/
1. �����ǰ�ڵ������Ϊ�գ��������ǰ�ڵ㲢�����Һ�����Ϊ��ǰ�ڵ㡣
2. �����ǰ�ڵ�����Ӳ�Ϊ�գ��ڵ�ǰ�ڵ�����������ҵ���ǰ�ڵ�����������µ�ǰ���ڵ㡣
   a) ���ǰ���ڵ���Һ���Ϊ�գ��������Һ�������Ϊ��ǰ�ڵ㡣��ǰ�ڵ����Ϊ��ǰ�ڵ�����ӡ�
   b) ���ǰ���ڵ���Һ���Ϊ��ǰ�ڵ㣬�������Һ���������Ϊ�գ��ָ�������״���������ǰ�ڵ㡣��ǰ�ڵ����Ϊ��ǰ�ڵ���Һ��ӡ�
3. �ظ�����1��2ֱ����ǰ�ڵ�Ϊ�ա�

ע�⣺�������η��ʵ�ʱ�䣺
1. û������������������֮ǰ
2. ���������ڶ��α��������ڵ㣬��ʾ�����������Ѿ����ء�
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
		if(root == NULL) return res;
		TreeNode *p = root, *pre = NULL;
		while(p){
			if(p->left == NULL){
				res.push_back(p->val);
				p = p->right;
			} else {
				pre = p->left;
				while(pre->right && pre->right != p){
					pre = pre->right;
				}
				if(pre->right == NULL){
					pre->right = p;
					p = p->left;
				} else {
					pre->right = NULL;
					res.push_back(p->val);
					p = p->right;
				}
			}
		}
		return res;
    }
};