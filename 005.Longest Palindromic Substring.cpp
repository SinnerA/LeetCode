/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Tags: String
*/

/*算法1：暴力解法，枚举所有子串，对每个子串判断是否为回文，复杂度为O(n^3)*/

/*
算法2：删除暴力解法中有很多重复的判断。很容易想到动态规划，时间复杂度O（n^2）,空间O（n^2）,动态规划方程如下：

dp[i][j] 表示子串s[i…j]是否是回文
初始化：dp[i][i] = true (0 <= i <= n-1);  dp[i][i-1] = true (1 <= i <= n-1); 其余的初始化为false
dp[i][j] = (s[i] == s[j] && dp[i+1][j-1] == true)

在动态规划中保存最长回文的长度及起点即可
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
		if(n <= 1) return s;
		int dp[n][n]; //表示子串是否是s[i...j]是否是回文
		memset(dp, 0, sizeof(dp));
		dp[0][0] = true;
		for(int i = 1; i < n; i++){
			dp[i][i] = true;
			dp[i][i-1] = true;
		}
		string res;
		int resLeft = 0, resRight = 0;
		
		for(int len = 2; len <= n; len++){
			for(int i = 0; i <= n - len; i++){
				int j = i + len - 1;
				if(s[i] == s[j] && dp[i + 1][j - 1]){
					dp[i][j] = true;
					if(len > res.size()){
						resLeft = i;
						resRight = j;
						res = s.substr(resLeft, resRight - resLeft + 1);
					}
				}
			}
		}
		return res;
    }
};