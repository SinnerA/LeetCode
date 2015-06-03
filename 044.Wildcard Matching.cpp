/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

Tags: Dynamic Programming Backtracking Greedy String
*/

//算法1：递归实现：会超时
bool isMatch(char* s, char* p) {
    if(*p == 0) return *s == 0;
	if(*p != '*'){
		if(*s != 0 && (*s == *p || *p == '?'))
			return isMatch(s+1, p+1);
		else
			return false;
	} else {
		while(*(p+1) == '*') p++;
		while(*s != 0){
			if(isMatch(s, p+1)) return true;
			s++;
		}
		return isMatch(s, p+1);
	}
}

//算法2：贪心
bool isMatch(char* s, char* p) {
    if(*p == 0) return *s == 0;
	char *savedP = NULL;
	char *savedS = NULL;
	while(*s != 0){
		if(*p == *s || *p == '?'){
			p++; s++;
			continue;
		}
		if(*p == '*'){
			savedP = p;
			savedS = s;
			p++;             //'*' match 0
			continue;
		}
		if(savedP != NULL){
			p = savedP + 1;
			s = savedS + 1;
			savedS++;        //'*' match 1,2,3......
			continue;
		}
		return false;
	}
	while(*p == '*') p++;
	return *p == 0;
}

//动态规划：http://blog.csdn.net/lanxu_yy/article/details/11905181