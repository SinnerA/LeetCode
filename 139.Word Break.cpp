/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

Tags: Dynamic Programming
*/

/*算法1：dp[i]表示s[0...i)能否分割*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty() || wordDict.empty()) return false;
		int n = s.size();
		int dp[n+1];              //dp[i]表示s[0...i)能否分割
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		
		for(int i = 1; i <= n; i++){
			for(int j = i - 1; j >= 0; j--){
				if(dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()){
					dp[i] = 1;
					break;       //只要找到一种切分方式就说明长度为i的单词可以成功切分，因此可以跳出内层循环。  
				}
			}
		}
		return dp[n];
    }
};


/*算法2：自己的思路*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty() || wordDict.empty()) return false;
		int n = s.size();
		int dp[n+1][n];//dp[i][j]表示以j为起点，长度为i的子串是否能分割
		memset(dp, 0, sizeof(dp));
		for(int len = 1; len <= n; len++){
			for(int start = 0; start < n; start++){
				string curStr = s.substr(start, len);
				if(wordDict.find(curStr) != wordDict.end())
					dp[len][start] = 1;
			}
		}
		
		for(int len = 1; len <= n; len++){
			for(int start = 0; start < n; start++){
				for(int i = start; i < start + len; i++){
					if(dp[i - start][start] && dp[start + len - i][i])
						dp[len][start] = 1;
				}
			}
		}
		return dp[n][0];
    }
};