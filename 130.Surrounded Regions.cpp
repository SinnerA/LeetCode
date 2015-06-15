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
���ҵ���Ե��O�����Ե��O��ͨ������O������ת����X��������ͨ����˼�Ǵӱ�Ե��O��ʼ��һ��ȫ��O��·�����Ե���õ㣩������������O�����X��
����ֻҪ�ӱ�Ե��O��ʼdfs�������������ͨ��O��Ȼ���ٰ�����δ��ǵ�O���X��
����Ĵ�������ʹ����һ��������顣������ʡ�ռ䣬�����Ȱ����ԵO��ͨ��O�ȱ��#��Ȼ���ٰ�ʣ���O��ΪX���ٰ�#���O
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
		//���ȱ������û�б���Χ��O
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				//�����ҵ����ܵ�O�������O����һƬ��O������ת��
				if(i == 0 || i == row - 1 || j == 0 || j == col - 1){
					if(!visited[i][j] && board[i][j] == 'O'){
						myQueue.push(Onode(i,j));
						visited[i][j] = 1;
						while(!myQueue.empty()){
							Onode oNode = myQueue.front();
							myQueue.pop();
							int cur_i = oNode.i;
							int cur_j = oNode.j;
							//��
							if(cur_i-1 >= 0 && !visited[cur_i-1][cur_j] && board[cur_i-1][cur_j] == 'O'){
								myQueue.push(Onode(cur_i-1,cur_j));
								visited[cur_i-1][cur_j] = 1;
							}
							//��
							if(cur_i+1 <= row-1 && !visited[cur_i+1][cur_j] && board[cur_i+1][cur_j] == 'O'){
								myQueue.push(Onode(cur_i+1,cur_j));
								visited[cur_i+1][cur_j] = 1;
							}
							//��
							if(cur_j-1 >= 0 && !visited[cur_i][cur_j-1] && board[cur_i][cur_j-1] == 'O'){
								myQueue.push(Onode(cur_i,cur_j-1));
								visited[cur_i][cur_j-1] = 1;
							}
							//��
							if(cur_j+1 <= col-1 && !visited[cur_i][cur_j+1] && board[cur_i][cur_j+1] == 'O'){
								myQueue.push(Onode(cur_i,cur_j+1));
								visited[cur_i][cur_j+1] = 1;
							}
						}
					}
				}
			}
		}
		//��δ����ǵ�Oת����X��������Χ��O��
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
				if(!visited[i][j] && board[i][j] == 'O')
					board[i][j] = 'X';
    }
};