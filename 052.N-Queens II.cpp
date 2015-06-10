/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

Tags: Backtracking
*/

/*利用题目N-Queens中的算法2*/
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
		vector<int> state(n, -1);
		dfs(res, state, 0);
		return res;
    }
	void dfs(int &res, vector<int> &state, int row){
		int n = state.size();
		if(row == n){
			res++;
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
		for(int i = 0; i < row; i++){
			if(state[i] == col || abs(row - i) == abs(col - state[i]))
				return false;
		}
		return true;
	}
};
