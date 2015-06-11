/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

Tags: Array Dynamic Programming
*/

/*
动态规划：dp[j]表示到i,j位置的唯一路径数目。需要注意dp的初始化值，和循环的起始值
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
		if(m == 0) return 0;
		int n = obstacleGrid[0].size();
		vector<int> dp(n+1, 0);
		dp[1] = obstacleGrid[0][0] == 0 ? 1 : 0;
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= n; j++)
				if(obstacleGrid[i-1][j-1] == 0)
					dp[j] = dp[j] + dp[j-1];
				else
					dp[j] = 0;
		return dp[n];
    }
};