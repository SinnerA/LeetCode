/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
Tags: Array Backtracking
*/

/*
遍历board找到和word首字母相同的位置，然后从该位置dfs看能否生成word。
进行dfs时，对当前位置分别访问上下左右四个位置，如果这些位置中的字母和word的下一个字母相同，则从这些位置继续搜索。
对于board中元素已访问的标志可以设一个访问标志数组，也可以把已访问的元素设置成某个字符，比如本文的代码就是设置成“#”，对该位置搜索完后要恢复原来的字母。
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		int row = board.size();
		if(row == 0) return false;
		int col = board[0].size();
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
				if(board[i][j] == word[0] && dfs(board, i, j, word, 0))
					return true;
		return false;
    }
	bool dfs(vector<vector<char>>& board, int row, int col, string word, int index){
		if(index == word.size()-1) return true;
		char savedChar = board[row][col];
		board[row][col] = '#';
		//上
		if(row - 1  >= 0 && board[row-1][col] == word[index+1])
			if(dfs(board, row-1, col, word, index+1))
				return true;
		//下
		if(row + 1 < board.size() && board[row+1][col] == word[index+1])
			if(dfs(board, row+1, col, word, index+1))
				return true;
		//左
		if(col - 1 >= 0 && board[row][col-1] == word[index+1])
			if(dfs(board, row, col-1, word, index+1))
				return true;
		//右
		if(col + 1 < board[0].size() && board[row][col+1] == word[index+1])
			if(dfs(board, row, col+1, word, index+1))
				return true;
		board[row][col] = savedChar;
		return false;
	}
};