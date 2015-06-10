/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Tags: Backtracking
*/

/*
算法1:
这种棋盘类的题目一般是回溯法, 依次放置每行的皇后。在放置的时候，要保持当前的状态为合法，即当前放置位置的同一行、同一列、两条对角线上都不存在皇后。
*/
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
		if(n == 0) return res;
		vector<string> cur(n, string(n, '.'));
		dfs(res, cur, 0);
		return res;
    }
	void dfs(vector<vector<string> >& res, vector<string>& cur, int row){
		if(row == cur.size()){
			res.push_back(cur);
			return;
		}
		for(int col = 0; col < cur.size(); col++){
			if(isValid(cur, row, col)){
				cur[row][col] = 'Q';
				dfs(res, cur, row + 1);
				cur[row][col] = '.';
			}
		}
	}
	//判断在cur[row][col]位置放一个皇后，是否是合法的状态
	//已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法
	bool isValid(vector<string>& cur, int row, int col){
		//列
		for(int i = 0; i < row; i++)
			if(cur[i][col] == 'Q') return false;
		//左斜上方
		for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
			if(cur[i][j] == 'Q') return false;
		//右斜上方
		for(int i = row-1, j = col+1; i >= 0 && j < cur.size(); i--, j++)
			if(cur[i][j] == 'Q') return false;
		return true;
	}
};

/*
算法2：
上述判断状态是否合法的函数还是略复杂，其实只需要用一个一位数组来存放当前皇后的状态。
假设数组为int state[n], state[i]表示第 i 行皇后所在的列。那么在新的一行 k 放置一个皇后后:
判断列是否冲突，只需要看state数组中state[0…k-1] 是否有和state[k]相等；
判断对角线是否冲突：如果两个皇后在同一对角线，那么|row1-row2| = |column1 - column2|，（row1，column1），（row2，column2）分别为冲突的两个皇后的位置
*/
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
		if(n == 0) return res;
		vector<int> state(n, -1);
		dfs(res, state, 0);
		return res;
    }
	void dfs(vector<vector<string> >& res, vector<int>& state, int row){
		int n = state.size();
		if(row == n){
			vector<string> tempRes(n, string(n, '.'));
			for(int i = 0; i < n; i++)
				tempRes[i][state[i]] = 'Q';
			res.push_back(tempRes);
		}
		for(int col = 0; col < n; col++){
			if(isValid(state, row, col)){
				state[row] = col;
				dfs(res, state, row + 1);
				state[row] = -1;
			}
		}
	}
	bool isValid(vector<int>& state, int row, int col){
		for(int i = 0; i < row; i++)
			if(state[i] == col || abs(row - i) == abs(col - state[i]))
				return false;
		return true;
	}
};

/*
算法3：算法2的非递归版
非递归方法的一个重要问题时何时回溯及如何回溯的问题。
程序首先对N行中的每一行进行探测，寻找该行中可以放置皇后的位置，具体方法是对该行的每一列进行探测，看是否可以放置皇后，如果可以，则在该列放置一个皇后，然后继续探测下一行的皇后位置。
如果已经探测完所有的列都没有找到可以放置皇后的列，此时就应该回溯，把上一行皇后的位置往后移一列，如果上一行皇后移动后也找不到位置，则继续回溯直至某一行找到皇后的位置或回溯到第一行，
如果第一行皇后也无法找到可以放置皇后的位置，则说明已经找到所有的解程序终止。如果该行已经是最后一行，则探测完该行后，如果找到放置皇后的位置，则说明找到一个结果，打印出来。
但是此时并不能再此处结束程序，因为我们要找的是所有N皇后问题所有的解，此时应该清除该行的皇后，从当前放置皇后列数的下一列继续探测。
*/
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
		vector<int> state(n, -1);
		for(int row = 0, col; ;){
			for(col = state[row] + 1; col < n; col++){
				if(isValid(state, row, col)){
					state[row] = col;
					if(row == n-1){
						vector<string> tempRes(n,string(n, '.'));
						for(int i = 0; i < n; i++)
							tempRes[i][state[i]] = 'Q';
						res.push_back(tempRes);
					} else {
						row++;
						break;
					}
				}
			}
			if(col == n){
				if(row == 0)
					break;
				state[row] = -1;
				row--;
			}
		}
		return res;
    }
	bool isValid(vector<int>& state, int row, int col){
		for(int i = 0; i < row; i++)
			if(state[i] == col || abs(row - i) == abs(col - state[i]))
				return false;
		return true;
	}
};

/*
算法4：helper函数中，参数row、ld、rd分别表示在列和两个对角线方向的限制条件下，当前行的哪些地方不能放置皇后（利用位表示）。
http://www.cnblogs.com/TenosDoIt/p/3801621.html
*/
class Solution {
private:
	vector<vector<string> > res;
	int upperlim;
public:
    vector<vector<string> > solveNQueens(int n) {
		upperlim = (1 << n) - 1;//低n位全为1
		vector<string> cur(n, string(n, '.'));
		bfs(cur, 0, 0, 0, 0);
		return res;
    }
	void bfs(vector<string>& cur, int row, int ld, int rd, int index){
		int pos;
		if(row != upperlim){
			int pos = upperlim & (~((row | ld | rd)));//可以放置皇后的位置
			while(pos){
				int p = pos & (~pos + 1);             //取最右边可以放置皇后的位置
				pos = pos - p;                        //pos最右边1清零
				setQueen(cur, index, p, 'Q');
				bfs(cur, row | p, (ld | p) << 1, (rd | p) >> 1, index + 1);
				setQueen(cur, index, p, '.');
			}
		} else
			res.push_back(cur);
	}
	void setQueen(vector<string>& cur, int row, int p, char ch){
		int col = 0;
		while(!(p & 1)){
			p >>= 1;
			col++;
		}
		cur[row][col] = ch;
	}
};