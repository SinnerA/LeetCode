/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

Tags: Tree Dynamic Programming
*/

/*
动态规划：dp[i]表示以长度为i的序列1...i，能构成BST的个数
初始化：dp[0] = 1, dp[1] = 1, dp[2] = 2;
递推式：dp[i] = sum(dp[k] * dp[i-k-1]) (k为选取的根节点，k = 0...i-1，左子树个数 * 右子树个数)
*/
class Solution {
public:
    int numTrees(int n) {
        if(n == 0) return 0;
		
		int dp[n + 1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for(int i = 3; i <= n; i++){
			for(int j = 0; j < i; j++){
				dp[i] += (dp[j] * dp[i-j-1]);
			}
		}
		return dp[n];
    }
};