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
������һ�㿪ʼ���ϼ��㣬��dp[i][j]����λ��(i,j)Ϊ������С·���ͣ���̬�滮��������
dp[i][j] = value[i][j] + min(dp[i+1][j], dp[i+1][j+1])
����ԭ���ռ䣬����Ҫ����ռ䣬���ǻ��ƻ�ԭ����ṹ
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
����һά����dp[n]���赱ǰrow = i, ��dp[j]��ʾ��λ��(i, j)Ϊ������С·����
�ռ临�Ӷ�O(n)�����ƻ�ԭ����ṹ
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