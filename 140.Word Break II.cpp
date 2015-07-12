/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

Tags: Dynamic Programming Backtracking
*/
/*
不能直接DFS，要先剪枝
可以跟上题一样先动态规划，判断能否被break，如果s不能被break，那么也没有DFS的必要了，另外在DFS时也可以再利用dp所存的信息从而可以大大得剪掉不必要的操作。
*/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
		if(s.empty() || wordDict.empty()) return res;
		int n = s.size();
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		
		for(int len = 1; len <= n; len++){
			for(int i = len - 1; i >= 0; i--){
				if(dp[i] && wordDict.find(s.substr(i, len - i)) != wordDict.end()){
					dp[len] = 1;
					break;
				}
			}
		}
		
		if(dp[n])
			wordBreakDFS(res, s, wordDict, "", 0, dp);
		return res;
    }
	
	void wordBreakDFS(vector<string>& res, string& s, unordered_set<string>& wordDict, 
						string tempRes, int index, vector<int>& dp){
		int n = s.size();
		string substr;
		for(int len = 1; index + len <= n; len++){
			substr = s.substr(index, len);
			if(dp[index] && wordDict.find(substr) != wordDict.end()){
				if(index + len == n){
					res.push_back(tempRes + substr);
					return;
				} else {
					wordBreakDFS(res, s, wordDict, tempRes + substr + " ", index + len, dp);
				}
			}
		}
	}
};