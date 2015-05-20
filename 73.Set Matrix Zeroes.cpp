/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space 
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution 

Tags: Array

分析：
O(m*n)解法：用m*n个空间记录某个位置是否要置0
O(m+n)解法：用一个数组记录某一列是否要置0，用一个数组记录某一行是否要置0
O(1)解法：利用matrix本身的空间来记录，不需要额外的空间
*/

/*
O(1)解法：利用matrix本身的空间来记录，不需要额外的空间
1：第一行记录需要置0的列，第一列记录需要置0的行，记录之前，需要提前判断第一行，第一列是否需要置0，设置标志isClearFirstCol,isClearFirstRow
2：然后遍历matrix（除了第一行和第一列）如果matrix[i][j]等于0，那么matrix[i][0] = 0 (行标志)，matrix[0][j] = 0(列标志)
3：再次遍历matrix（除了第一行和第一列）只要对应位置的行标志或者列标志等于0，相应的位置就置0
4：根据标志isClearFirstCol,isClearFirstRow，决定是否需要将第一行和第一列置0
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