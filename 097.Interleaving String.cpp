/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Tags: Dynamic Programming String
*/

/*
递归解法（大数据超时）：每次比较s1和s3的最后一个字符或者s2和s3的最后一个字符，如果相等去掉两者的最后一个字符进入子问题，只要一个子问题返回true，父问题就返回true

isInterleave(s1[0...n1], s2[0...n2], s3[0...n3]) = 
(s1[n1] == s3[n3] && isInterleave(s1[0...n1-1], s2[0...n2], s3[0...n3-1])) || 
(s2[n2] == s3[n3] && isInterleave(s1[0...n1], s2[0...n2-1], s3[0...n3-1]))
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleaveRecur(s1, s1.size() - 1, s2, s2.size() - 1, s3, s3.size() - 1);
    }
	
	bool isInterleaveRecur(string &s1, int end1, string &s2, int end2, string &s3, int end3){
		if(end1 == -1 && end2 == -1){
			if(end3 == -1) return true;
			else return false;
		}
		if(end1 >= 0 && s1[end1] == s3[end3] && isInterleaveRecur(s1, end1 - 1, s2, end2, s3, end3 - 1))
			return true;
		if(end2 >= 0 && s2[end2] == s3[end3] && isInterleaveRecur(s1, end1, s2, end2 - 1, s3, end3 - 1))
			return true;
		return false;
	}
};

/*
动态规划解法：根据递归的思想，我们一刻如下使用动态规划解此题。设dp[i][j]表示s1[0...i-1]和s2[0...j-1]能否组合成s3[0....i+j-1]，动态规划方程如下                                                                               本文地址

dp[i][j] = (dp[i][j-1] ==true && s3[i+j-1] == s2[j-1]) || (dp[i-1][j] == true && s3[i-1+j] == s1[i-1])
初始条件：if(s1[0] == s3[0])dp[1][0] = true，if(s2[0] == s3[0])dp[0][1] = true; 其他值均为false
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
		if(n1 == 0 && n2 == 0 && n3 == 0) return true;
		if(n1 + n2 != n3) return false;
		
		int dp[n1+1][n2+1]; //dp[i][j]表示s1[0...i-1]和s2[0...j-1]能否组合成s3[0....i+j-1]
		memset(dp, 0, sizeof(dp));
		if(s1[0] == s3[0]) dp[1][0] = 1;
		if(s2[0] == s3[0]) dp[0][1] = 1;
		
		for(int i = 0; i <= n1; i++){
			for(int j = 0; j <= n2; j++){
				int k = i + j;
				if((j > 0 && dp[i][j-1] && s2[j-1] == s3[k-1]) || (i > 0 && dp[i-1][j] && s1[i-1] == s3[k-1]))
					dp[i][j] = 1;
			}
		}
		return dp[n1][n2];
    }
};