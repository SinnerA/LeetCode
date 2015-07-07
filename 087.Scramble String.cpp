/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Tags: Dynamic Programming String
*/

/*
�ݹ�ⷨ��s2[0...j]�Ƿ������s1[0...i]ת�� isScramble(s2[0...j], s1[0...i])�����Էֽ�� i �������⣨i ��ʵ����j����Ϊ�����ַ������Ȳ�һ�����϶����ܻ���ת������
( isScramble(s2[0...k], s1[0...k]) &&  isScramble(s2[k+1...j], s1[k+1...i]) ) || ( isScramble(s2[0...k], s1[i-k...i]) &&  isScramble(s2[k+1...j], s1[0...i-k-1]) )����k = 0,1,2 ... i-1��k�൱���ַ����ķָ��)
ֻҪһ�������ⷵ��ture����ô�ͱ�ʾ�����ַ�������ת����
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScrambleRecur(s1, s2);
    }
	
	bool isScrambleRecur(string &s1, string &s2){
		if(s1 == s2) return true;
		string tmpS1 = s1, tmpS2 = s2;
		sort(tmpS1.begin(), tmpS1.end());
		sort(tmpS2.begin(), tmpS2.end());
		if(tmpS1 != tmpS2) return false;  //�����ַ���������ĸ��ͬ
		
		int n = s1.size();
		for(int i = 1; i < n; i++){       //�ָ�λ��
			string leftS1 = s1.substr(0, i);
			string rightS1 = s1.substr(i);
			string leftS2 = s2.substr(0, i);
			string rightS2 = s2.substr(i);
			
			if(isScrambleRecur(leftS1, leftS2) && isScrambleRecur(rightS1, rightS2))
				return true;
			leftS2 = s2.substr(0, n - i);
			rightS2 = s2.substr(n - i);
			if(isScrambleRecur(leftS1, rightS2) && isScrambleRecur(rightS1, leftS2))
				return true;
		}
		return false;
	}
};

/*
��̬�滮�ⷨ��
�ݹ�ⷨ�кܶ��ظ������⣬����s2 = rgeat, s1 = great ������ѡ��ָ��Ϊ0ʱ��Ҫ��������� isScramble(reat, geat)��
�ٶԸ�������ѡ��ָ��0ʱ��Ҫ��������� isScramble(eat,eat)���������ǵ�һ��ѡ��1��Ϊ�ָ��ʱ��ҲҪ��������� isScramble(eat,eat)��
��ͬ��������isScramble(eat,eat)��Ҫ���2�Ρ�

��̬�滮�����������������⣬��dp[k][i][j]��ʾs2��j��ʼ����Ϊk���Ӵ��Ƿ������s1��i��ʼ����Ϊk���Ӵ�ת�����ɣ���ô��̬�滮��������
   ��ʼ������dp[1][i][j] = (s1[i] == s2[j] ? true : false)
   dp[k][i][j] = ( dp[divlen][i][j] && dp[k-divlen][i+divlen][j+divlen] )  ||  ( dp[divlen][i][j+k-divlen] && dp[k-divlen][i+divlen][j] ) 
   (divlen = 1,2,3...k-1, ����ʾ�Ӵ��ָ�㵽�Ӵ���ʼ�˵ľ���) ��ֻҪһ�������ⷵ���棬�Ϳ���ֹͣ����
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
		int n = s1.size();
		int dp[n+1][n][n];//dp[k][i][j]��ʾs2��j��ʼ����Ϊk���Ӵ��Ƿ������s1��i��ʼ����Ϊk���Ӵ�ת������
		memset(dp, 0, sizeof(dp));
		
		//��ʼ������Ϊ1���Ӵ���dpֵ
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(s1[i] == s2[j]) dp[1][i][j] = 1;
			}
		}
		
		for(int len = 2; len <= n; len++){         //�Ӵ��ĳ���
			for(int i = 0; i <= n - len; i++){     //s1����ʼλ��
				for(int j = 0; j <= n - len; j++){ //s2����ʼλ��
				    //divlen��ʾ�����Ӵ��ָ�㵽�Ӵ���ʼ�˵ľ���
					for(int divLen = 1; divLen < len && !dp[len][i][j]; divLen++){
						if((dp[divLen][i][j] && dp[len - divLen][i + divLen][j + divLen]) || (dp[divLen][i][j + len - divLen] && dp[len - divLen][i + divLen][j]))
							dp[len][i][j] = 1;
					}
				}
			}
		}
		return dp[n][0][0];
    }
};



















