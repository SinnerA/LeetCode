/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Tags: Array Dynamic Programming
*/

/*
��̬�滮������Ŀ��062.Unique Paths���㷨2��˼·���ƣ�ע��dp�ĳ�ʼ�����ֵ
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
������չ��
�����и����⣬���������ͬʱ�����Ͻǳ�����Ŀ�ĵ������½ǣ������˵�·�߲����ཻ�������˳�������յ��⣬�����˲�ͬͨ��ͬһ�����ӣ���ʹ������·���ĺ����
�����һ�����ȴ����Ͻǵ����½ǣ��ٻص����Ͻ�����ͬ�����⣩��

����˫�̶߳�̬�滮���⣺��������Ϊgrid��dp[k][i][j]��ʾ�����˶�����k������һ������������i�����ڶ�������������j�� ʱ�����·���ͣ�ֻ��Ҫ���������Ϳ��Զ�λ�������˵�λ��grid[k-i][i-1] �� grid[k-j][j-1]������ô
dp[k][i][j] = max(dp[k-1][i-1][j-1], dp[k-1][i][j], dp[k-1][i-1][j], dp[k-1][i][j-1]) + grid[k-i][i-1] + grid[k-j][j-1]  �����Ǽ�������ʼλ��ʱ���Ѿ�����һ����

������̵���˼�Ǵӵ�k-1������k�������������˶������ߡ��������ߡ���һ�����µڶ������ҡ���һ�����ҵڶ������£��������߷���ѡ����һ����·�������ġ�

����Ҫ��֤����·�߲����ཻ�����������ߵĹ����У���һ���������ߵĲ�����Զ������һ���������ߵĲ��������ǲ�����ڶ����������ߵĲ����ϴ󣬼�dp[k][i][j]��j > i������Ч��״̬���ߵ��յ�Ĳ���Ϊ�����������+���������-1

��Ҫע����ǣ�������k��ʱ��ĳ���������ߵĲ������� > k - �������������������ߵĲ��� <= k-��������ô�����ߵĲ��� = k-�����ߵĲ��� >= ��������ʱ����������ķ�Χ���������Ǽ����� j > i,���ֻҪ��֤ i > k-�����������ɡ�
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