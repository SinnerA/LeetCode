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
�ݹ飺���ν�ÿ���ڵ���Ϊ���ڵ㣬Ȼ�������ѡһ����ڵ㣬�ұ�ѡһ���ҽڵ㣬����һ���������Լ���res��
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
��̬�滮��dp[i][j][]��ʾi...j֮��Ľڵ���Թ���BST������
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*> > > dp(n+2, vector<vector<TreeNode*> >(n+2, vector<TreeNode*>()));
		for(int i = 1; i <= n+1; i++)           //Ϊ�����洦��btrees[i][j]ʱ i > j�ı߽����
			dp[i][i-1].push_back(NULL);
		
		for(int k = 1; k <= n; k++){             //k��ʾ�ڵ���Ŀ
			for(int i = 1; i <= n-k+1; i++){     //i��ʾ��ʼ�ڵ�
				for(int j = i; j <= i+k-1; j++){ //��[i,i+1,...i+k-1]���ж�Ӧ������BST��
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
