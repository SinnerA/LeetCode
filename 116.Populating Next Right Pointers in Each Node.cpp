/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

Tags: Tree Depth-first Search
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

/*层序遍历二叉树，把每一层中前一个节点的next指向后一个节点，使用队列辅助层序遍历时，在队列中用NULL来分割每层的节点*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
		TreeLinkNode *pre = NULL, *p = NULL;
		queue<TreeLinkNode*> myQueue;
		myQueue.push(root);
		myQueue.push(NULL);
		while(!myQueue.empty()){
			p = myQueue.front();
			myQueue.pop();
			if(p){
				if(p->left) myQueue.push(p->left);
				if(p->right) myQueue.push(p->right);
			} else {
				if(!myQueue.empty()) myQueue.push(NULL);
			}
			if(pre) pre->next = p;
			pre = p;
		}
		return;
    }
};