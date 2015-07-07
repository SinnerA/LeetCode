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
递归解法：s2[0...j]是否可以由s1[0...i]转换 isScramble(s2[0...j], s1[0...i])，可以分解成 i 个子问题（i 其实等于j，因为两个字符串长度不一样，肯定不能互相转换）：
( isScramble(s2[0...k], s1[0...k]) &&  isScramble(s2[k+1...j], s1[k+1...i]) ) || ( isScramble(s2[0...k], s1[i-k...i]) &&  isScramble(s2[k+1...j], s1[0...i-k-1]) )，（k = 0,1,2 ... i-1，k相当于字符串的分割点)
只要一个子问题返回ture，那么就表示两个字符串可以转换。
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
		if(tmpS1 != tmpS2) return false;  //两个字符串所含字母不同
		
		int n = s1.size();
		for(int i = 1; i < n; i++){       //分割位置
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
动态规划解法：
递归解法有很多重复子问题，比如s2 = rgeat, s1 = great 当我们选择分割点为0时，要解决子问题 isScramble(reat, geat)，
再对该子问题选择分割点0时，要解决子问题 isScramble(eat,eat)；而当我们第一步选择1作为分割点时，也要解决子问题 isScramble(eat,eat)。
相同的子问题isScramble(eat,eat)就要解决2次。

动态规划用数组来保存子问题，设dp[k][i][j]表示s2从j开始长度为k的子串是否可以由s1从i开始长度为k的子串转换而成，那么动态规划方程如下
   初始条件：dp[1][i][j] = (s1[i] == s2[j] ? true : false)
   dp[k][i][j] = ( dp[divlen][i][j] && dp[k-divlen][i+divlen][j+divlen] )  ||  ( dp[divlen][i][j+k-divlen] && dp[k-divlen][i+divlen][j] ) 
   (divlen = 1,2,3...k-1, 它表示子串分割点到子串起始端的距离) ，只要一个子问题返回真，就可以停止计算
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
		int n = s1.size();
		int dp[n+1][n][n];//dp[k][i][j]表示s2从j开始长度为k的子串是否可以由s1从i开始长度为k的子串转换而成
		memset(dp, 0, sizeof(dp));
		
		//初始化长度为1的子串的dp值
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(s1[i] == s2[j]) dp[1][i][j] = 1;
			}
		}
		
		for(int len = 2; len <= n; len++){         //子串的长度
			for(int i = 0; i <= n - len; i++){     //s1的起始位置
				for(int j = 0; j <= n - len; j++){ //s2的起始位置
				    //divlen表示两个子串分割点到子串起始端的距离
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



















