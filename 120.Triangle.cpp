/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Tags: Array Dynamic Programming
*/

/*
最下面一层开始往上计算，设dp[i][j]是以位置(i,j)为起点的最小路径和，动态规划方程如下
dp[i][j] = value[i][j] + min(dp[i+1][j], dp[i+1][j+1])
利用原来空间，不需要额外空间，但是会破坏原数组结构
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		for(int i = triangle.size() - 2; i >= 0; i--){
			for(int j = 0; j < triangle[i].size(); j++){
				triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
			}
		}
		return triangle[0][0];
    }
};

/*
利用一维数组dp[n]，设当前row = i, 则dp[j]表示从位置(i, j)为起点的最小路径和
空间复杂度O(n)，不破坏原数组结构
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		int dp[n];
		for(int i = 0; i < triangle[n-1].size(); i++)
			dp[i] = triangle[n-1][i];
		
		for(int i = n-2; i >= 0; i--){
			for(int j = 0; j < triangle[i].size(); j++){
				dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
			}
		}
		return dp[0];
    }
};