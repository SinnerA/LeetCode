/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

Tags: String
*/

/*方法1：借助strlen，相当于两遍遍历字符串*/
class Solution {
public:
    int lengthOfLastWord(string s) {
		if(s.empty()) return 0;
		int res = 0, len = strlen(s), i;
		for(i = len-1; i >= 0 && s[i] == ' '; i++);//从尾部开始找到第一个非空格字符
		for(; i >= 0 && s[i] != ' '; i--) res++;
		return res;
    }
};

/*方法2：遍历一遍*/
class Solution {
public:
    int lengthOfLastWord(string s) {
		if(s.empty()) return 0;
		int res = 0, cnt = 0;
		for(int i = 0; s[i] != '\0'; i++){
			if(s[i] == ' '){
				if(cnt != 0){
					res = cnt;
				}
				cnt = 0;
			} else {
				cnt++;
			}
		}
		return cnt == 0 ? res : cnt;
    }
};