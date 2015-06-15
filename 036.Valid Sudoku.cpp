/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Tags: Hash Table
*/

/*
合法数独：1-9的每一个数字，在一行中只能出现一次，在一列中只能出现一次，在3*3的小方框中只能出现一次
只需要判断9*9网格的每一行、每一列、9个小九宫格是否合法。即如果在每一行、每一列、每个9个小九宫格内，某个数字重复出现了，当前数独就是不合法的。 
需要注意的是：如果把九宫格按照行从0开始标号，那么数字board[i][j] 位于第 i/3*3+j/3 个九宫格内
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		int rowValid[10] = {0};
		int colValid[9][10] = {0};
		int subBoardValid[9][10] = {0};
		for(int i = 0; i < 9; i++){
			memset(rowValid, 0, sizeof(rowValid));
			for(int j = 0; j < 9; j++){
				if(board[i][j] != '.'){
					if(!checkValid(rowValid, board[i][j] - '0') 
					   || !checkValid(colValid[j], board[i][j] - '0') 
					   || !checkValid(subBoardValid[i/3*3 + j/3], board[i][j] - '0'))
					return false;
				}
			}
		}
		return true;
    }
	bool checkValid(int nums[], int x){
		if(nums[x] == 1)
			return false;
		nums[x] = 1;
		return true;
	}
};

/*
针对上面的算法，还可以优化空间。上面的算法中，在双重循环时，我们默认了第一重循环表示矩阵的行、第二重循环表示矩阵的列。可以换一种思路：
在检测行是否合法时，i 表示矩阵的行，j 表示矩阵的列；
检测列是否合法时，i 表示矩阵的列，j 表示矩阵的行；
检测九宫格是否合法时，i 表示九宫格的标号，j 表示九宫格里的每个元素（只是我们需要根据i、j定位相应的元素到原来的矩阵：第 i 个九宫格里面的第 j 个元素在原矩阵的第 3*(i/3) + j/3 行，第 3*(i%3) + j%3）列，“/” 表示整数除法）
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		int rowValid[10];
		int colValid[10];
		int subBoardValid[10];
		for(int i = 0; i < 9; i++){
			memset(rowValid, 0, sizeof(rowValid));
			memset(colValid, 0, sizeof(colValid));
			memset(subBoardValid, 0, sizeof(subBoardValid));
			for(int j = 0; j < 9; j++){
				if(!checkValid(rowValid, board[i][j] - '0') ||
				   !checkValid(colValid, board[j][i] - '0') ||
				   !checkValid(subBoardValid, board[3*(i/3) + j/3][3*(i%3) + j%3] - '0'))
				   return false;
			}
		}
		return true;
    }
	bool checkValid(int vec[], int val){
		if(val + '0' == '.') return true;
		if(vec[val] == 1) return false;
		vec[val] = 1;
		return true;
	}
};