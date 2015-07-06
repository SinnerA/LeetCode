/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Tags: Dynamic Programming String
*/

/*
算法1：动态规划, 字符串为s，设bool数组dp[i][j]表示子串s[i…j]是否可以完全匹配，那么动态规划方程如下:

初始化dp数组为false
如果dp[i+1][j-1] == true && s[i] == ‘(’&&s[j] == ‘)’或者 存在k = i+1…j-1 使得dp[i][k] == true && dp[k+1][j] = true ，则dp[i][j] = true
方程的意思是：要使子串s[i…j]能够完全匹配，那么有以下两种情况可以满足：a、子串s[i+1…j-1]完全匹配，且s[i]、s[j]是左右两个半括号；b、存在某个k，使得两个子串s[i…k]、s[k+1…j]都能完全匹配.

求得所有dp[i][j]后，最长匹配子串的长度 = max {j-i}, 其中 dp[i][j] = true;

下面代码中isValid相当于方程中的dp，注意到子串长度为奇数时，子串不可能完全匹配。概算大时间复杂度为O（n^3），oj上大数据超时
*/
class Solution {
public:
    int longestValidParentheses(string s) {
		if(s.empty()) return 0;
		int n = s.size(), res = 0;
		int dp[n][n]; //dp[i][j]表示子串是否可以完全匹配
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n - 1; i++){
			if(s[i] == '(' && s[i+1] == ')'){
				dp[i][i+1] = 1;
				res = 2;
			}
		}
		
		for(int len = 4; len <= n; len += 2){ //k表示子串长度，只有长度为偶数的子串才可能是合法括号
			for(int i = 0; i <= n-len; i++){  //i表示子串的起始位置
				int j = i + len - 1;
				if(dp[i+1][j-1] && s[i] == '(' && s[j] == ')'){
					dp[i][j] = 1;
				} else {
					for(int k = i+1; k < j-1; k++){
						if(dp[i][k] && dp[k+1][j]){
							dp[i][j] = 1;
						}
					}
				}
				if(dp[i][j]) res = len;
			}
		}
		return res;
    }
};

/*	
算法2：在处理括号匹配问题上，我们一般使用栈来解决

顺序扫描字符串：
初始化：在栈中压入-1
一、若碰到‘（’，则把当前位置压入栈中
二、若碰到‘）’：
     （1）、如果栈顶元素不是‘（’，则把当前位置压入栈中；
     （2）、如果栈顶元素时‘（’：栈顶元素出栈，当前的合法子串长度 = 当前字符索引 - 新的栈顶元素；更新最大子串长度

例如：())()()
扫描到第0个字符‘（’时，0入栈
扫描到第1个字符‘）’时，栈顶对应字符为‘（’，把栈顶0出栈，当前合法子串长度 = 1 - 新的栈顶元素（-1） = 2；
扫描到第2个字符‘）’时，栈顶为-1，因此2入栈
扫描到第3个字符‘（’时，3入栈
扫描到第4个字符‘）’时，栈顶对应字符为‘（’，把栈顶3出栈，当前合法子串长度 = 4 - 新的栈顶元素（2） = 2；
扫描到第5个字符‘（’时，5入栈
扫描到第6个字符‘）’时，栈顶对应字符为‘（’，把栈顶5出栈，当前合法子串长度 = 6 - 新的栈顶元素（2） = 4；

需要注意的是：当前合法子串当长度 != 当前索引 - 与当前的‘）’匹配的‘（’的索引 + 1, 例如扫描到第6个字符‘）’时，当前合法子串长度不是等于6-5+1 = 2，还要考虑到它前面已经匹配的3、4号位
算法时间空间复杂度都是O（n）
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
		int n = s.size(), res = 0;
		stack<int> myStack;
		myStack.push(-1);//为了处理边界条件，在栈底添加-1
		
		for(int i = 0; i < n; i++){
			if(s[i] == '('){
				myStack.push(i);
			} else {
				int topIndex = myStack.top();
				if(topIndex >= 0 && s[topIndex] == '('){
					//s[i]可以和s[myStack.top()]匹配
					myStack.pop();
					if(i - myStack.top() > res) res = i - myStack.top();
				} else {
					myStack.push(i);
				}
			}
		}
		return res;
    }
};






























