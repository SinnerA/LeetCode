/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space 
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution 

Tags: Array

������
O(m*n)�ⷨ����m*n���ռ��¼ĳ��λ���Ƿ�Ҫ��0
O(m+n)�ⷨ����һ�������¼ĳһ���Ƿ�Ҫ��0����һ�������¼ĳһ���Ƿ�Ҫ��0
O(1)�ⷨ������matrix����Ŀռ�����¼������Ҫ����Ŀռ�
*/

/*
O(1)�ⷨ������matrix����Ŀռ�����¼������Ҫ����Ŀռ�
1����һ�м�¼��Ҫ��0���У���һ�м�¼��Ҫ��0���У���¼֮ǰ����Ҫ��ǰ�жϵ�һ�У���һ���Ƿ���Ҫ��0�����ñ�־isClearFirstCol,isClearFirstRow
2��Ȼ�����matrix�����˵�һ�к͵�һ�У����matrix[i][j]����0����ômatrix[i][0] = 0 (�б�־)��matrix[0][j] = 0(�б�־)
3���ٴα���matrix�����˵�һ�к͵�һ�У�ֻҪ��Ӧλ�õ��б�־�����б�־����0����Ӧ��λ�þ���0
4�����ݱ�־isClearFirstCol,isClearFirstRow�������Ƿ���Ҫ����һ�к͵�һ����0
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		int row = matrix.size();
		if(row == 0) return;
		int col = matrix[0].size();
		
		bool isClearFirstCol = false, isClearFirstRow = false;
		for(int i = 0; i < col; i++)
			if(matrix[0][i] == 0){ isClearFirstRow = true; break; }
		for(int i = 0; i < row; i++)
			if(matrix[i][0] == 0){ isClearFirstCol = true; break; }
		
		for(int i = 1; i < row; i++)
			for(int j = 1; j < col; j++)
				if(matrix[i][j] == 0){
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
        for(int i = 1; i < row; i++)
			for(int j = 1; j < col; j++)
				if(matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
		
		if(isClearFirstRow)
			for(int i = 0; i < col; i++)
				matrix[0][i] = 0;
		if(isClearFirstCol)
			for(int i = 0; i < row; i++)
				matrix[i][0] = 0;
	}
};