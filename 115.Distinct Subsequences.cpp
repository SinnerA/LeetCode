/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

Tags: Dynamic Programming String
*/

/*
算法1：递归解法，首先，从个字符串S的尾部开始扫描，找到第一个和T最后一个字符相同的位置k。
此时S[i]==T[j]，那么当前这个字母即可以保留也可以抛弃，所以变换方法等于保留这个字母的变换方法加上不用这个字母的变换方法。
那么总的删除方法等于a、b两种情况的删除方法的和。递归解法代码如下，但是通过大数据会超时。
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        return numDistinctRecur(s, s.size() - 1, t, t.size() - 1);
    }
	
	int numDistinctRecur(string &s, int ends, string &t, int endt){
		if(ends < 0) return 0;
		else if(endt < 0) return 1;
		
		while(ends >= 0 && s[ends] != t[endt]) ends--;
		if(ends < 0) return 0;
		
		return numDistinctRecur(s, ends - 1, t, endt - 1) + numDistinctRecur(s, ends - 1, t, endt);
	}
};

/*
算法2：动态规划，设dp[i][j]是从字符串S[0...i-1](长度为i)中变换得到字符串T[0...j-1](长度为j)的方法种类，有上面递归的分析可知，动态规划方程如下

初始条件：dp[i][0] = 1（把任意一个字符串变换为一个空串只有一个方法）
如果S[i] == T[j], dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
如果S[i] != T[j], dp[i][j] = dp[i-1][j]
*/
class Solution {
public:
    int numDistinct(string s, string t) {
		int n1 = s.size(), n2 = t.size();
		if(n2 == 0) return 1;
		if(n1 < n2) return 0;
		int dp[n1+1][n2+1];
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= n1; i++)
			dp[i][0] = 1;
		
		for(int i = 1; i <= n1; i++){
			for(int j = 1; j <= n2; j++){
				if(s[i-1] == t[j-1]){
					dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
				} else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		return dp[n1][n2];
    }
};