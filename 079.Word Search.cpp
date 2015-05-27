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
����board�ҵ���word����ĸ��ͬ��λ�ã�Ȼ��Ӹ�λ��dfs���ܷ�����word��
����dfsʱ���Ե�ǰλ�÷ֱ�������������ĸ�λ�ã������Щλ���е���ĸ��word����һ����ĸ��ͬ�������Щλ�ü���������
����board��Ԫ���ѷ��ʵı�־������һ�����ʱ�־���飬Ҳ���԰��ѷ��ʵ�Ԫ�����ó�ĳ���ַ������籾�ĵĴ���������óɡ�#�����Ը�λ���������Ҫ�ָ�ԭ������ĸ��
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
		//��
		if(row - 1  >= 0 && board[row-1][col] == word[index+1])
			if(dfs(board, row-1, col, word, index+1))
				return true;
		//��
		if(row + 1 < board.size() && board[row+1][col] == word[index+1])
			if(dfs(board, row+1, col, word, index+1))
				return true;
		//��
		if(col - 1 >= 0 && board[row][col-1] == word[index+1])
			if(dfs(board, row, col-1, word, index+1))
				return true;
		//��
		if(col + 1 < board[0].size() && board[row][col+1] == word[index+1])
			if(dfs(board, row, col+1, word, index+1))
				return true;
		board[row][col] = savedChar;
		return false;
	}
};