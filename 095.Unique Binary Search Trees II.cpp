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
�ݹ飺
���ν�ÿ���ڵ���Ϊ���ڵ㣬�Ը��ڵ�Ϊ�е㣬����Ϊ�������ߣ���߿��Թ���m�������ұ߿��Թ���n����
��Ȼ����m��ѡһ������Ϊ��������n��ѡһ������Ϊ���������ɴ˹���һ����������res��
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
��̬�滮��dp[i][j][]��ʾi...j֮��Ľڵ㹹�ɵ�����BST
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*> > > dp(n+2, vector<vector<TreeNode*> >(n+2, vector<TreeNode*>()));//n+2����Ϊ����i == n+1
		for(int i = 1; i <= n+1; i++)                                 //Ϊ�����洦��btrees[i][j]ʱ i > j�ı߽����
			dp[i][i-1].push_back(NULL);
		
		for(int len = 1; len <= n; len++){                            //k��ʾ�ڵ���Ŀ
			for(int start = 1; start <= n-len+1; start++){            //i��ʾ��ʼ�ڵ�
				int end = start + len - 1;
				for(int rootVal = start; rootVal <= end; rootVal++){  //��[i,i+1,...i+k-1]���ж�Ӧ������BST��
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
