/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Tags: Dynamic Programming String
*/

/*
分析：需要注意的是，如果序列中有不能匹配的0，那么解码方法是0，比如序列012 、100（第二个0可以和1组成10，第三个0不能匹配）。
递归的解法很容易，但是大集合会超时。转换成动态规划的方法，假设dp[i]表示序列s[0...i-1]的解码数目，动态规划方程如下：                                                                                                                                                               本文地址

初始条件：dp[0] = 1, dp[1] = (s[0] == '0') ? 0 : 1
dp[i] = ( s[i-1] == 0 ? 0 : dp[i-1] ) + ( s[i-2,i-1]可以表示字母 ？ dp[i-2] : 0 )， 
其中第一个分量是把s[0...i-1]末尾一个数字当做一个字母来考虑，第二个分量是把s[0...i-1]末尾两个数字当做一个字母来考虑

例如，当我们知道了n-2长度的字符串能够解释的数目以及n-1长度的字符串能够解释的数目时，我们可以判读如下两个条件：
1）若第n个字符在1到9之间，则n长度的字符串能够解释的数目包含n-1长度字符串能够解释的数目。
2）若第n-1个字符与第n个字符可以解释为一个字母时，则n长度的字符串能够解释的数目包含n-2长度字符串能够解释的数目。
*/
class Solution {
public:
    int numDecodings(string s) {
		int len = s.size();
		if(len == 0) return 0;
		int dp[len+1]; //dp[i]表示s[0...i-1]解码方法数目
		dp[0] = 1;     //为了i=2时，dp[2] = dp[0] + dp[1]
		dp[1] = (s[0] == '0') ? 0 : 1;
		for(int i = 2; i <= len; i++){
			dp[i] = (s[i-1] != '0') ? dp[i-1] : 0;
			if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))
				dp[i] += dp[i-2];
		}
		return dp[len];
    }
};