/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

Tags: Dynamic Programming String
*/

/*
典型的动态规划问题，设dp[i][j]表示从word1[0...i-1]到word2[0...j-1]的编辑距离，动态规划方程如下：

初始条件：dp[0][i] = i, dp[i][0] = i
dp[i][j] = (word1[i - 1] == word2[j - 1]) ? dp[i-1][j-1] : 1 + min( dp[i][j-1],  dp[i-1][j],  dp[i-1][j-1] )，
解释：如果两个单词的最后一个字母相同，那么这个字母可以不用变化，编辑距离等于两个单词都去掉最后一个字母后的编辑距离；
如果最后一个字母不同，可以有三种处理方式：
a、给word1插入一个和word2最后的字母相同的字母，这时word1和word2的最后一个字母就一样了，此时编辑距离等于1（插入操作） + 插入前的word1到word2去掉最后一个字母后的编辑距离 
b、删除word1的最后一个字母，此时编辑距离等于1（删除操作） + word1去掉最后一个字母到word2的编辑距离 
c 、把word1的最后一个字母替换成word2的最后一个字母，此时编辑距离等于 1（替换操作） + word1和word2去掉最后一个字母的编辑距离，然后取三种情况下的最小距离
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
		int len1 = word1.size(), len2 = word2.size();
		int dp[len1+1][len2+1];//dp[i][j]表示从word1[0...i-1]到word2[0...j-1]的编辑距离
		for(int i = 0; i <= len1; i++) dp[i][0] = i;
		for(int i = 0; i <= len2; i++) dp[0][i] = i;
		
		for(int i = 1; i <= len1; i++)
			for(int j = 1; j <= len2; j++)
				if(word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
		return dp[len1][len2];
    }
};
