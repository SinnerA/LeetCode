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
�ҵ���ֵ�±�Ĺ���
��������ϵ������ַ��������ַ���ԭ������±�, ��������Ϊn = 5, ���Է������¹���:
(1)��һ�к����һ���±�������interval = n*2-2 = 8;
(2)�м��еļ���������Ե�,��i�еļ����: interval�C2*i,  2*i,  interval�C2*i, 2*i, interval�C2*i, 2*i, �������ڵļ�����Ϊinterval��
*/
class Solution {
public:
    string convert(string s, int numRows) {
		int len = s.size();
		if(len == 0) return "";
		if(numRows == 1) return s;
		string res(len, ' ');
		int k = 0, interval = (numRows << 1) - 2;
		//��һ��
		for(int i = 0; i < len; i += interval)
			res[k++] = s[i];
		//�м���
		for(int i = 1; i < numRows - 1; i++){
			int inter = i << 1;
			for(int j = i; j < len; j += inter){
				res[k++] = s[j];
				inter = interval - inter;
			}
		}
		//���һ��
		for(int i = numRows - 1; i < len; i += interval)
			res[k++] = s[i];
		return res;
    }
};