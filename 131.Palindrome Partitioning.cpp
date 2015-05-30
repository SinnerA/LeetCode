/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
Tags: Backtracking
*/

/*
算法1：
首先对字符串的所有子串判断是否是回文，设f[i][j] = true表示以i为起点，长度为j的子串是回文,等于false表示不是回文，那么求f[i][j]的动态规划方程如下：

当j = 1，f[i][j] = true;

当j = 2，f[i][j] = (s[i]==s[i+1]),其中s是输入字符串	

当j > 2, f[i][j] = f[i+1][j-2] && (s[i] == s[i+j-1])（即判断s[m..n]是否是回文时：只要s[m+1...n-1]是回文并且s[m] = s[n]，那么它就是回文，否则不是回文）
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
		int len = s.size();
        vector<vector<string> > res;
		if(len == 0) return res;
		//f[i][j]表示已i为起点，长度为j的子串是回文串
		bool **f = new bool* [len];
		for(int i = 0; i < len; i++){
			f[i] = new bool[len+1]
			for(int j = 0; j < len + 1; j++)
				f[i][j] = false;
			f[i][1] = true;
		}
		for(int j = 2; j <= len; j++)
			for(int i = 0; i <= len-j; i++){
				if(j == 2)
					f[i][j] = (s[i] == s[i+1]);
				else
					f[i][j] = f[i+1][j-2] && (s[i] == s[i+j-1]);
			}
		vector<string> tempRes;
		dfs(s, f, res, tempRes, 0);
		for(int i = 0; i < len; i++)
			delete [](f[i]);
		delete []f;
		return res;
    }
	void dfs(const string &s, bool **f, vector<vector<string> > &res, vector<string> &tempRes, int start){
		//start为遍历的起点
		if(start >= s.size()){
			res.push_back(tempRes);
			return;
		}
		for(int len = 1; len <= s.size() - start; len++){
			if(f[start][len] == true){
				tempRes.push_back(s.substr(start, len));
				dfs(s, f, res, tempRes, start+len);
				tempRes.pop_back();
			}
		}
	}
};











