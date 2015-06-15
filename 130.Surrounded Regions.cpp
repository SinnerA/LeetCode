/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Tags: Breadth-first Search
*/

/*
先找到边缘的O，与边缘的O连通的所有O均不用转化成X（这里连通的意思是从边缘的O开始有一条全是O的路径可以到达该点），其他的所有O都变成X。
我们只要从边缘的O开始dfs标记所有与它连通的O，然后再把所有未标记的O变成X。
下面的代码中是使用了一个标记数组。如果想节省空间，可以先把与边缘O连通的O先变成#，然后再把剩余的O变为X，再把#变成O
*/
class Solution {
private:
	struct Onode{
		int i;
		int j;
		Onode(){};
		Onode(int i_, int j_):i(i_),j(j_){};
	};
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
		if(row == 0) return;
		int col = board[0].size();
		int visited[row][col];
		memset(visited, 0, sizeof(visited));
		queue<Onode> myQueue;
		//首先标记所有没有被包围的O
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				//首先找到四周的O，和这个O连成一片的O都不用转换
				if(i == 0 || i == row - 1 || j == 0 || j == col - 1){
					if(!visited[i][j] && board[i][j] == 'O'){
						myQueue.push(Onode(i,j));
						visited[i][j] = 1;
						while(!myQueue.empty()){
							Onode oNode = myQueue.front();
							myQueue.pop();
							int cur_i = oNode.i;
							int cur_j = oNode.j;
							//上
							if(cur_i-1 >= 0 && !visited[cur_i-1][cur_j] && board[cur_i-1][cur_j] == 'O'){
								myQueue.push(Onode(cur_i-1,cur_j));
								visited[cur_i-1][cur_j] = 1;
							}
							//下
							if(cur_i+1 <= row-1 && !visited[cur_i+1][cur_j] && board[cur_i+1][cur_j] == 'O'){
								myQueue.push(Onode(cur_i+1,cur_j));
								visited[cur_i+1][cur_j] = 1;
							}
							//左
							if(cur_j-1 >= 0 && !visited[cur_i][cur_j-1] && board[cur_i][cur_j-1] == 'O'){
								myQueue.push(Onode(cur_i,cur_j-1));
								visited[cur_i][cur_j-1] = 1;
							}
							//右
							if(cur_j+1 <= col-1 && !visited[cur_i][cur_j+1] && board[cur_i][cur_j+1] == 'O'){
								myQueue.push(Onode(cur_i,cur_j+1));
								visited[cur_i][cur_j+1] = 1;
							}
						}
					}
				}
			}
		}
		//把未被标记的O转换成X（即被包围的O）
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
				if(!visited[i][j] && board[i][j] == 'O')
					board[i][j] = 'X';
    }
};