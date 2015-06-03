/*	
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true     //此时，.重复了2次，而.可以表示任何字符
isMatch("aab", "c*a*b") → true //此时c重复了0次，a重复了2次

Tags: Dynamic Programming Backtracking String

注意：这里的a*表示a可以重复0次或者多次，不是a和*分开的。
*/

/*
算法1：递归。根据下一个字符是否是'*'分情况判断。
如果p的下一个字符不是'*'，只需判断当前字符是否相等，或者p[cur]='.'，递归处理s[1]和p[1]；
如果是p的下一个'*'，则当前s和p相等或者p='.'情况下，依次判断s[0...s.length]和p[cur+2]是否match；
*/
class Solution {
public:
    bool isMatch(string s, string p) {
		if(p.size() == 0) return s.size() == 0;
		if(p.size() == 1) return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
		if(p[1] != '*'){
			if(s.size() != 0 && (s[0] == p[0] || p[0] == '.')){
				string newS(s.begin() + 1, s.end());
				string newP(p.begin() + 1, p.end());
				return isMatch(newS, newP);
			} else
				return false;
		} else {
			while(s.size() != 0 && (s[0] == p[0] || p[0] == '.')){
				string newP(p.begin() + 2, p.end());
				if(isMatch(s, newP)) return true;    //*的前一个字符重复了0次，直接跳过p的*，s与p的*之后的字符比较
				string newS(s.begin() + 1, s.end());
				s = newS;                            //*的前一个字符重复了1次（2次，3次...）
			}
			string newP(p.begin() + 2, p.end());
			return isMatch(s, newP);
		}
	}
};

bool isMatch(char* s, char* p) {
    if(*p == 0) return *s == 0;
	if(*(p+1) != '*'){
		if(*s != 0 && (*s == *p || *p == '.'))
			return isMatch(s+1, p+1);
		else return false;
	} else {
		while(*s != 0 && (*s == *p || *p == '.')){
			if(isMatch(s, p+2)) return true; //*的前一个字符重复了0次，直接跳过p的*，s与p的*之后的字符比较
			s++;						     //*的前一个字符重复了1次（2次，3次...）
		}
		return isMatch(s, p+2);
	}
}













