/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

Tags: Tree Dynamic Programming
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
递归：
依次将每个节点作为根节点，以根节点为中点，划分为左右两边，左边可以构成m棵树，右边可以构成n棵树
，然后在m中选一棵树作为左子树，n中选一棵树作为右子树，由此构成一棵树，加入res中
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return createTree(1, n);
    }
	
	vector<TreeNode*> createTree(int start, int end){
		vector<TreeNode*> res;
		if(start > end){
			res.push_back(NULL);
			return res;
		}
		
		for(int k = start; k <= end; k++){
			vector<TreeNode*> left = createTree(start, k-1);
			vector<TreeNode*> right = createTree(k+1, end);
			for(int i = 0; i < left.size(); i++){
				for(int j = 0; j < right.size(); j++){
					TreeNode* root = new TreeNode(k);
					root->left = left[i];
					root->right = right[j];
					res.push_back(root);
				}
			}
		}
		return res;
	}
};


/*
动态规划：dp[i][j][]表示i...j之间的节点构成的所有BST
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*> > > dp(n+2, vector<vector<TreeNode*> >(n+2, vector<TreeNode*>()));//n+2是因为下面i == n+1
		for(int i = 1; i <= n+1; i++)                                 //为了下面处理btrees[i][j]时 i > j的边界情况
			dp[i][i-1].push_back(NULL);
		
		for(int len = 1; len <= n; len++){                            //k表示节点数目
			for(int start = 1; start <= n-len+1; start++){            //i表示起始节点
				int end = start + len - 1;
				for(int rootVal = start; rootVal <= end; rootVal++){  //求[i,i+1,...i+k-1]序列对应的所有BST树
					for(int m = 0; m < dp[start][rootVal-1].size(); m++){
						for(int n = 0; n < dp[rootVal+1][end].size(); n++){
							TreeNode* root = new TreeNode(rootVal);
							root->left = dp[start][rootVal-1][m];
							root->right = dp[rootVal+1][end][n];
							dp[start][end].push_back(root);
						}
					}
				}
			}
		}
		return dp[1][n];
    }
};
