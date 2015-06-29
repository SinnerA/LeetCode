/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

Tags: Array Hash Table Stack Dynamic Programming
*/

/*
我们可以枚举矩形左上角的位置，那么知道了矩形左上角的位置，怎么计算以某一点为左上角的矩形的最大面积呢？举例如下，下面的矩阵我们以(0,0)为矩形的左上角：
1 1 1 1 0 0
1 1 1 0 1 1
1 0 1 0 1 1
0 1 1 1 1 1
1 1 1 1 1 1

矩形高度是1时，宽度为第一行中从第一个位置起连续的1的个数，为4，面积为4 * 1 = 4
矩形高度是2时，第二行从第一个位置起连续1的个数是3，宽度为min(3,4) = 3，面积为3*2 = 6
矩形高度为3时，第三行从第一个位置起连续1的个数是1，宽度为min(1,3) = 1，面积为1*3 = 3
矩形高度为4时，第四行从第一个位置起连续1的个数是0，宽度为min(0,1) = 0，面积为0*4 = 0

后面的行就不用计算了，因为上一行计算的宽度是0，下面所有宽度都是0
因此以(0,0)为左上角的矩形的最大面积是6，计算以某一点为左上角的矩形的最大面积复杂度是O(n)。

注意到上面我们用到了信息“从某一行某个位置开始连续的1的个数”，这个我们可以通过动态规划求得：
设dp[i][j]是从点(i,j)开始，这一行连续1的个数，动态规划方程如下：
初始条件：dp[i][column-1] = (matrix[i][column-1] == '1') （column是matrix的列数）
dp[i][j] = (matrix[i][j] == '1') ?  1 + dp[i][j + 1] : 0 ，(从方程看出我们应该从每一行的后往前计算)
计算dp复杂度O(n^2)，枚举左上角位置以及计算以该位置为左上角的矩形最大面积复杂度是O(n^2*n)=O(n^3)，总的复杂度是O(n^3)
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
		int row = matrix.size();
		if(row == 0) return 0;
		int col = matrix[0].size();
		int dp[row][col], res = 0;
		//求出所有的dp值
		for(int i = 0; i < row; i++)
			dp[i][col - 1] = (matrix[i][col - 1] == '1') ? 1 : 0;
		for(int i = 0; i < row; i++){
			for(int j = col - 2; j >= 0; j--){
				dp[i][j] = (matrix[i][j] == '1') ? dp[i][j + 1] + 1 : 0;
			}
		}
		
		//以每个点作为矩形的左上角计算所得的最大矩形面积
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				//剪枝，column-j是最大宽度，row-i是最大高度
				if((row - i) * (col - j) <= res) break;
				int width = dp[i][j];
				for(int k = i; k < row && width > 0; k++){
					//剪枝，row-i是以点(i,j)为左上角的矩形的最大高度
					if((width * (row - i)) <= res) break;
					if(dp[k][j] < width) width = dp[k][j]; //矩形宽度要取从第i行到第k行宽度的最小值
					res = max(res, width * (k - i + 1));
				}
			}
		}
		return res;
    }
};