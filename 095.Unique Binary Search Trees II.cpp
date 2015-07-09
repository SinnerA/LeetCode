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
递归：依次将每个节点作为根节点，然后在左边选一个左节点，右边选一个右节点，这是一个树，可以加入res中
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
动态规划：dp[i][j][]表示i...j之间的节点可以构成BST的数量
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*> > > dp(n+2, vector<vector<TreeNode*> >(n+2, vector<TreeNode*>()));
		for(int i = 1; i <= n+1; i++)           //为了下面处理btrees[i][j]时 i > j的边界情况
			dp[i][i-1].push_back(NULL);
		
		for(int k = 1; k <= n; k++){             //k表示节点数目
			for(int i = 1; i <= n-k+1; i++){     //i表示起始节点
				for(int j = i; j <= i+k-1; j++){ //求[i,i+1,...i+k-1]序列对应的所有BST树
					for(int m = 0; m < dp[i][j-1].size(); m++){
						for(int n = 0; n < dp[j+1][i+k-1].size(); n++){
							TreeNode* root = new TreeNode(j);
							root->left = dp[i][j-1][m];
							root->right = dp[j+1][i+k-1][n];
							dp[i][i+k-1].push_back(root);
						}
					}
				}
			}
		}
		return dp[1][n];
    }
};
