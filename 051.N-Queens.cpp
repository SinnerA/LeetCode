/*
The n-queens puzzle is the problem of placing n queens on an n��n chessboard such that no two queens attack each other.

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
�㷨1:
�������������Ŀһ���ǻ��ݷ�, ���η���ÿ�еĻʺ��ڷ��õ�ʱ��Ҫ���ֵ�ǰ��״̬Ϊ�Ϸ�������ǰ����λ�õ�ͬһ�С�ͬһ�С������Խ����϶������ڻʺ�
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
	//�ж���cur[row][col]λ�÷�һ���ʺ��Ƿ��ǺϷ���״̬
	//�Ѿ���֤��ÿ��һ���ʺ�ֻ��Ҫ�ж����Ƿ�Ϸ��Լ��Խ����Ƿ�Ϸ�
	bool isValid(vector<string>& cur, int row, int col){
		//��
		for(int i = 0; i < row; i++)
			if(cur[i][col] == 'Q') return false;
		//��б�Ϸ�
		for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
			if(cur[i][j] == 'Q') return false;
		//��б�Ϸ�
		for(int i = row-1, j = col+1; i >= 0 && j < cur.size(); i--, j++)
			if(cur[i][j] == 'Q') return false;
		return true;
	}
};

/*
�㷨2��
�����ж�״̬�Ƿ�Ϸ��ĺ��������Ը��ӣ���ʵֻ��Ҫ��һ��һλ��������ŵ�ǰ�ʺ��״̬��
��������Ϊint state[n], state[i]��ʾ�� i �лʺ����ڵ��С���ô���µ�һ�� k ����һ���ʺ��:
�ж����Ƿ��ͻ��ֻ��Ҫ��state������state[0��k-1] �Ƿ��к�state[k]��ȣ�
�ж϶Խ����Ƿ��ͻ����������ʺ���ͬһ�Խ��ߣ���ô|row1-row2| = |column1 - column2|����row1��column1������row2��column2���ֱ�Ϊ��ͻ�������ʺ��λ��
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
�㷨3���㷨2�ķǵݹ��
�ǵݹ鷽����һ����Ҫ����ʱ��ʱ���ݼ���λ��ݵ����⡣
�������ȶ�N���е�ÿһ�н���̽�⣬Ѱ�Ҹ����п��Է��ûʺ��λ�ã����巽���ǶԸ��е�ÿһ�н���̽�⣬���Ƿ���Է��ûʺ�������ԣ����ڸ��з���һ���ʺ�Ȼ�����̽����һ�еĻʺ�λ�á�
����Ѿ�̽�������е��ж�û���ҵ����Է��ûʺ���У���ʱ��Ӧ�û��ݣ�����һ�лʺ��λ��������һ�У������һ�лʺ��ƶ���Ҳ�Ҳ���λ�ã����������ֱ��ĳһ���ҵ��ʺ��λ�û���ݵ���һ�У�
�����һ�лʺ�Ҳ�޷��ҵ����Է��ûʺ��λ�ã���˵���Ѿ��ҵ����еĽ������ֹ����������Ѿ������һ�У���̽������к�����ҵ����ûʺ��λ�ã���˵���ҵ�һ���������ӡ������
���Ǵ�ʱ�������ٴ˴�����������Ϊ����Ҫ�ҵ�������N�ʺ��������еĽ⣬��ʱӦ��������еĻʺ󣬴ӵ�ǰ���ûʺ���������һ�м���̽�⡣
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
�㷨4��helper�����У�����row��ld��rd�ֱ��ʾ���к������Խ��߷�������������£���ǰ�е���Щ�ط����ܷ��ûʺ�����λ��ʾ����
http://www.cnblogs.com/TenosDoIt/p/3801621.html
*/
class Solution {
private:
	vector<vector<string> > res;
	int upperlim;
public:
    vector<vector<string> > solveNQueens(int n) {
		upperlim = (1 << n) - 1;//��nλȫΪ1
		vector<string> cur(n, string(n, '.'));
		bfs(cur, 0, 0, 0, 0);
		return res;
    }
	void bfs(vector<string>& cur, int row, int ld, int rd, int index){
		int pos;
		if(row != upperlim){
			int pos = upperlim & (~((row | ld | rd)));//���Է��ûʺ��λ��
			while(pos){
				int p = pos & (~pos + 1);             //ȡ���ұ߿��Է��ûʺ��λ��
				pos = pos - p;                        //pos���ұ�1����
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