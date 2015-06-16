/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

Tags: String
*/

/*����1������strlen���൱����������ַ���*/
class Solution {
public:
    int lengthOfLastWord(string s) {
		if(s.empty()) return 0;
		int res = 0, len = strlen(s), i;
		for(i = len-1; i >= 0 && s[i] == ' '; i++);//��β����ʼ�ҵ���һ���ǿո��ַ�
		for(; i >= 0 && s[i] != ' '; i--) res++;
		return res;
    }
};

/*����2������һ��*/
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