/*	
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "a*") �� true
isMatch("aa", ".*") �� true
isMatch("ab", ".*") �� true     //��ʱ��.�ظ���2�Σ���.���Ա�ʾ�κ��ַ�
isMatch("aab", "c*a*b") �� true //��ʱc�ظ���0�Σ�a�ظ���2��

Tags: Dynamic Programming Backtracking String

ע�⣺�����a*��ʾa�����ظ�0�λ��߶�Σ�����a��*�ֿ��ġ�
*/

/*
�㷨1���ݹ顣������һ���ַ��Ƿ���'*'������жϡ�
���p����һ���ַ�����'*'��ֻ���жϵ�ǰ�ַ��Ƿ���ȣ�����p[cur]='.'���ݹ鴦��s[1]��p[1]��
�����p����һ��'*'����ǰs��p��Ȼ���p='.'����£������ж�s[0...s.length]��p[cur+2]�Ƿ�match��
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
				if(isMatch(s, newP)) return true;    //*��ǰһ���ַ��ظ���0�Σ�ֱ������p��*��s��p��*֮����ַ��Ƚ�
				string newS(s.begin() + 1, s.end());
				s = newS;                            //*��ǰһ���ַ��ظ���1�Σ�2�Σ�3��...��
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
			if(isMatch(s, p+2)) return true; //*��ǰһ���ַ��ظ���0�Σ�ֱ������p��*��s��p��*֮����ַ��Ƚ�
			s++;						     //*��ǰһ���ַ��ظ���1�Σ�2�Σ�3��...��
		}
		return isMatch(s, p+2);
	}
}













