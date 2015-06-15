/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Tags: Hash Table
*/

/*
�Ϸ�������1-9��ÿһ�����֣���һ����ֻ�ܳ���һ�Σ���һ����ֻ�ܳ���һ�Σ���3*3��С������ֻ�ܳ���һ��
ֻ��Ҫ�ж�9*9�����ÿһ�С�ÿһ�С�9��С�Ź����Ƿ�Ϸ����������ÿһ�С�ÿһ�С�ÿ��9��С�Ź����ڣ�ĳ�������ظ������ˣ���ǰ�������ǲ��Ϸ��ġ� 
��Ҫע����ǣ�����ѾŹ������д�0��ʼ��ţ���ô����board[i][j] λ�ڵ� i/3*3+j/3 ���Ź�����
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
���������㷨���������Ż��ռ䡣������㷨�У���˫��ѭ��ʱ������Ĭ���˵�һ��ѭ����ʾ������С��ڶ���ѭ����ʾ������С����Ի�һ��˼·��
�ڼ�����Ƿ�Ϸ�ʱ��i ��ʾ������У�j ��ʾ������У�
������Ƿ�Ϸ�ʱ��i ��ʾ������У�j ��ʾ������У�
���Ź����Ƿ�Ϸ�ʱ��i ��ʾ�Ź���ı�ţ�j ��ʾ�Ź������ÿ��Ԫ�أ�ֻ��������Ҫ����i��j��λ��Ӧ��Ԫ�ص�ԭ���ľ��󣺵� i ���Ź�������ĵ� j ��Ԫ����ԭ����ĵ� 3*(i/3) + j/3 �У��� 3*(i%3) + j%3���У���/�� ��ʾ����������
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