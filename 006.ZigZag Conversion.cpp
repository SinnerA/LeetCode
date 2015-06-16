/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

Tags: String
*/

/*
找到数值下标的规律
如果把以上的数字字符看做是字符在原数组的下标, 给定行数为n = 5, 可以发现以下规律:
(1)第一行和最后一行下标间隔都是interval = n*2-2 = 8;
(2)中间行的间隔是周期性的,第i行的间隔是: interval–2*i,  2*i,  interval–2*i, 2*i, interval–2*i, 2*i, …（相邻的间隔相加为interval）
*/
class Solution {
public:
    string convert(string s, int numRows) {
		int len = s.size();
		if(len == 0) return "";
		if(numRows == 1) return s;
		string res(len, ' ');
		int k = 0, interval = (numRows << 1) - 2;
		//第一行
		for(int i = 0; i < len; i += interval)
			res[k++] = s[i];
		//中间行
		for(int i = 1; i < numRows - 1; i++){
			int inter = i << 1;
			for(int j = i; j < len; j += inter){
				res[k++] = s[j];
				inter = interval - inter;
			}
		}
		//最后一行
		for(int i = numRows - 1; i < len; i += interval)
			res[k++] = s[i];
		return res;
    }
};