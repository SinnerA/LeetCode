/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.

Tags: Array Dynamic Programming
*/

/*算法1：递归，这个方法oj超时*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
		else return uniquePaths(m, n-1) + uniquePaths(m-1, n);
    }
};

/*算法2：动态规划，dp[i][j]表示到位置i,j的唯一路径数目
算法1的递归解法中，其实我们计算了很多重复的子问题，比如计算uniquePaths(4, 5) 和 uniquePaths(5, 3)时都要计算子问题uniquePaths(3, 2)，再者由于uniquePaths(m, n) = uniquePaths(n, m)，这也使得许多子问题被重复计算了。
要保存子问题的状态，这样很自然的就想到了动态规划方法，设dp[i][j] = uniquePaths(i, j)， 那么动态规划方程为：
dp[i][j] = dp[i-1][j] + dp[i][j-1]
边界条件：dp[i][1] = 1, dp[1][j] = 1
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m+1, vector<int>(n+1, 1));
		for(int i = 2; i <= m; i++)
			for(int j = 2; j <= n; j++)
				dp[i][j] = dp[i][j-1] + dp[i-1][j];
		return dp[m][n];
    }
};

/*
简化dp。路线途径：1：上一行的同一列，2：同一行的上一列，dp[j]表示到位置i（隐含在当前循环中）,j的唯一路径数目
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n+1, 1);
		for(int i = 2; i <= m; i++)
			for(int j = 2; j <= n; j++)
				dp[j] = dp[j]+ dp[j-1];
		return dp[n];
    }
};

/*
算法3：组合数
其实这个和组合数有关，对于m*n的网格，从左上角走到右下角，总共需要走m+n-2步，其中必定有m-1步是朝右走，n-1步是朝下走，
那么这个问题的答案就是组合数：C(m+n-2, m-1), 这里需要注意的是求组合数时防止乘法溢出 
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        return combination(m+n-2, m-1);
    }
	int combination(int m, int n){
		if(n > (m >> 1)) n = m - n;//C(m+n-2, m-1)与C(m+n-2, n-1)是等价的
		long long res = 1;
		for(int i = 1; i <= n; i++)
			res = res * (m - i  + 1) / i;
		return res;
	}
};