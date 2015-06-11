/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Tags: Array Dynamic Programming
*/

/*
动态规划：与题目“062.Unique Paths”算法2的思路类似，注意dp的初始化与初值
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
		if(m == 0) return 0;
		int n = grid[0].size();
		vector<int> dp(n+1, INT_MAX);
		dp[1] = 0;
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= n; j++)
				dp[j] = min(dp[j], dp[j-1]) + grid[i-1][j-1];
		return dp[n];
    }
};

/*
问题拓展：
现在有个问题，如果两个人同时从左上角出发，目的地是右下角，两个人的路线不能相交（即除了出发点和终点外，两个人不同通过同一个格子），使得两条路径的和最大。
（这和一个人先从左上角到右下角，再回到左上角是相同的问题）。

这是双线程动态规划问题：假设网格为grid，dp[k][i][j]表示两个人都走了k步，第一个人向右走了i步，第二个人向右走了j步 时的最大路径和（只需要三个变量就可以定位出两个人的位置grid[k-i][i-1] 、 grid[k-j][j-1]），那么
dp[k][i][j] = max(dp[k-1][i-1][j-1], dp[k-1][i][j], dp[k-1][i-1][j], dp[k-1][i][j-1]) + grid[k-i][i-1] + grid[k-j][j-1]  （我们假设在起始位置时就已经走了一步）

这个方程的意思是从第k-1步到第k步，可以两个人都向右走、都向下走、第一个向下第二个向右、第一个向右第二个向下，这四种走法中选择上一步中路径和最大的。

由于要保证两条路线不能相交，即两个人走的过程中，有一个人向右走的步数永远大于另一个人向右走的步数，我们不妨设第二个人向右走的步数较大，即dp[k][i][j]中j > i才是有效的状态。走到终点的步数为：网格的行数+网格的列数-1

需要注意的是：当走了k步时，某个人向右走的步数必须 > k - 网格的行数，如果向右走的步数 <= k-行数，那么向下走的步数 = k-向右走的步数 >= 行数，此时超出了网格的范围。由于我们假设了 j > i,因此只要保证 i > k-网格行数即可。
*/
int max2PathSum(vector<vector<int> > grid){
    int row = grid.size(), col = grid[0].size();
	vector<vector<vector<int> > > dp(row + col, vector<vector<int> >(col+1, vector<int>(col+1, 0)));
	for(int step = 2; step <= row+col-2; step++)
		for(int i = max(1, step-row+1); i <= col && i <= step; i++)
			for(int j = i+1; j <= col && j <= step; j++){
				dp[step][i][j] = max(max(dp[k-1][i][j], dp[k-1][i-1][j-1]), max(dp[k-1][i][j-1], dp[k-1][i-1][j]));
				dp[step][i][j] += grid[k-i][i-1] + grid[k-j][j-1];
			}
	return dp[row+col-2][col-1][col] + 2*grid[0][0] + 2*grid[row-1][col-1];
}