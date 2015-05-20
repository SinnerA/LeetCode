/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

Tags: Two Pointers String
*/

/*����ָ��ֱ����β��ʼ�жϣ���������ĸ�����ַ���ע���Сд*/
class Solution {
public:
    bool isPalindrome(string s) {
		if(s.empty()) return true;
        int len = s.size();
		int i = 0, j = len - 1;
		while(i < j){
			while(!isAlphaNumeric(s[i])){
				i++; 
				if(i == j) return true; //i��j֮�䶼�ǷǷ��ַ�
			}
			while(!isAlphaNumeric(s[j])){
				j--;
				if(i == j) return true; //i��j֮�䶼�ǷǷ��ַ�
			}
			if(!isSame(s[i], s[j])) return false;
			i++; j--;
		}
		return true;
    }
	bool isAlphaNumeric(char c){
		if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			return true;
		return false;
	}
	bool isSame(char a, char b){
		if(a >= 'A' && a <= 'Z')
			a += 'a' - 'A';
		if(b >= 'A' && b <= 'Z')
			b += 'a' - 'A';
		return a == b;
	}
};