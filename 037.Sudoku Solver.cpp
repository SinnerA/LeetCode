/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

Tags: Backtracking Hash Table
*/

/*这种类型的游戏一般回溯法来解决，设置某个空格时，如果该空格无论设置什么数字都无法达到合法状态，那么回溯重新设置上一个空格，详细见代码注释*/
class Solution {
private:
	int rowValid[9][10];     //rowValid[i][j]表示第i行数字j是否已经使用
	int colValid[9][10];     //columnValid[i][j]表示第i列数字j是否已经使用
	int subBoardValid[9][10];//subBoardValid[i][j]表示第i个小格子内数字j是否已经使用
public:
    void solveSudoku(vector<vector<char>>& board) {
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
				if(board[i][j] != '.')
					fill(i, j, board[i][j] - '0');
		slove(board, 0);
    }
	
	bool slove(vector<vector<char>>& board, int index){
		//0 <= index <= 80，index表示接下来要填充第index个格子
		if(index > 80) return true;
		int row = index/9, col = index%9;
		if(board[row][col] != '.')
			return slove(board, index + 1);
		
		//每个填充的格子有9种可能的填充数字
		for(int val = '1'; val <= '9'; val++){
			if(isValid(row, col, val - '0')){
				board[row][col] = val;
				fill(row, col, val - '0');
				if(slove(board, index+1)) return true;
				clear(row, col, val - '0');
			}
		}
		board[row][col] = '.'; //恢复board状态
		return false;
	}
	
	//判断在第row行col列填充数字val后，是否是合法的状态
	bool isValid(int row, int col, int val){
		if(rowValid[row][val] == 0 &&
		   colValid[col][val] == 0 &&
		   subBoardValid[row/3*3 + col/3][val] == 0)
			return true;
		return false;
	}
	
	//更新填充状态
	void fill(int row, int col, int val){
		rowValid[row][val] = 1;
		colValid[col][val] = 1;
		subBoardValid[row/3*3 + col/3][val] = 1;
	}
	
	//清除填充状态
	void clear(int row, int col, int val){
		rowValid[row][val] = 0;
		colValid[col][val] = 0;
		subBoardValid[row/3*3 + col/3][val] = 0;
	}
};