/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

Tags: Backtracking
*/
/*
关于格雷码参考wikipedia（https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81#.E4.BA.8C.E9.80.B2.E4.BD.8D.E6.95.B8.E8.BD.89.E6.A0.BC.E9.9B.B7.E7.A2.BC）。
模拟，二进制转格雷码：gray = (binary) xor (binary >> 1)
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
		n = 1<<n;
		
		for(int i = 0; i < n; i++){
			res.push_back(i ^ (i>>1));
		}
		return res;
    }
};

/*回溯（错误）：由于必须按照格雷码的定义来，如n = 2时，[0,2,3,1]是错误的，而[0,1,3,2]才是正确的*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
		
		grayCodeRecur(res, n, 0);
		return res;
    }
	
	void grayCodeRecur(vector<int>& res, int n, int tempRes){
		if(n == 0){
			res.push_back(tempRes);
			return;
		}
		grayCodeRecur(res, n - 1, tempRes*2 + 1);
		grayCodeRecur(res, n - 1, tempRes*2 + 0);
	}
};