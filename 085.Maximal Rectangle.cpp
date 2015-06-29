/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

Tags: Array Hash Table Stack Dynamic Programming
*/

/*
���ǿ���ö�پ������Ͻǵ�λ�ã���ô֪���˾������Ͻǵ�λ�ã���ô������ĳһ��Ϊ���Ͻǵľ��ε��������أ��������£�����ľ���������(0,0)Ϊ���ε����Ͻǣ�
1 1 1 1 0 0
1 1 1 0 1 1
1 0 1 0 1 1
0 1 1 1 1 1
1 1 1 1 1 1

���θ߶���1ʱ�����Ϊ��һ���дӵ�һ��λ����������1�ĸ�����Ϊ4�����Ϊ4 * 1 = 4
���θ߶���2ʱ���ڶ��дӵ�һ��λ��������1�ĸ�����3�����Ϊmin(3,4) = 3�����Ϊ3*2 = 6
���θ߶�Ϊ3ʱ�������дӵ�һ��λ��������1�ĸ�����1�����Ϊmin(1,3) = 1�����Ϊ1*3 = 3
���θ߶�Ϊ4ʱ�������дӵ�һ��λ��������1�ĸ�����0�����Ϊmin(0,1) = 0�����Ϊ0*4 = 0

������оͲ��ü����ˣ���Ϊ��һ�м���Ŀ����0���������п�ȶ���0
�����(0,0)Ϊ���Ͻǵľ��ε���������6��������ĳһ��Ϊ���Ͻǵľ��ε����������Ӷ���O(n)��

ע�⵽���������õ�����Ϣ����ĳһ��ĳ��λ�ÿ�ʼ������1�ĸ�������������ǿ���ͨ����̬�滮��ã�
��dp[i][j]�Ǵӵ�(i,j)��ʼ����һ������1�ĸ�������̬�滮�������£�
��ʼ������dp[i][column-1] = (matrix[i][column-1] == '1') ��column��matrix��������
dp[i][j] = (matrix[i][j] == '1') ?  1 + dp[i][j + 1] : 0 ��(�ӷ��̿�������Ӧ�ô�ÿһ�еĺ���ǰ����)
����dp���Ӷ�O(n^2)��ö�����Ͻ�λ���Լ������Ը�λ��Ϊ���Ͻǵľ������������Ӷ���O(n^2*n)=O(n^3)���ܵĸ��Ӷ���O(n^3)
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
		int row = matrix.size();
		if(row == 0) return 0;
		int col = matrix[0].size();
		int dp[row][col], res = 0;
		//������е�dpֵ
		for(int i = 0; i < row; i++)
			dp[i][col - 1] = (matrix[i][col - 1] == '1') ? 1 : 0;
		for(int i = 0; i < row; i++){
			for(int j = col - 2; j >= 0; j--){
				dp[i][j] = (matrix[i][j] == '1') ? dp[i][j + 1] + 1 : 0;
			}
		}
		
		//��ÿ������Ϊ���ε����ϽǼ������õ����������
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				//��֦��column-j������ȣ�row-i�����߶�
				if((row - i) * (col - j) <= res) break;
				int width = dp[i][j];
				for(int k = i; k < row && width > 0; k++){
					//��֦��row-i���Ե�(i,j)Ϊ���Ͻǵľ��ε����߶�
					if((width * (row - i)) <= res) break;
					if(dp[k][j] < width) width = dp[k][j]; //���ο��Ҫȡ�ӵ�i�е���k�п�ȵ���Сֵ
					res = max(res, width * (k - i + 1));
				}
			}
		}
		return res;
    }
};