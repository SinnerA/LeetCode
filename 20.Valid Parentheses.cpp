/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Tags: Stack String
*/

/*
<<<<<<< HEAD
Ö±½ÓÓÃÕ»
=======
ç›´æŽ¥ç”¨æ ˆ
>>>>>>> e5be46318e0111412a04ae1d0df1c120c2d93f11
*/
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return false;
		stack<int> sta;
<<<<<<< HEAD
		sta.push('#'); //·ÀÖ¹popÊ±stackÎª¿Õ
=======
		sta.push('#'); //é˜²æ­¢popæ—¶stackä¸ºç©º
>>>>>>> e5be46318e0111412a04ae1d0df1c120c2d93f11
		for(int i = 0; i < s.size(); ++i){
			switch(s[i]){
				case '(': sta.push(s[i]);break;
				case '[': sta.push(s[i]);break;
				case '{': sta.push(s[i]);break;
				case ')': 
				{
					char top = sta.top();
					if(top == '(')
						sta.pop();
					else
						return false;
					break;
				}
				case ']': 
				{
					char top = sta.top();
					if(top == '[')
						sta.pop();
					else
						return false;
					break;
				}
				case '}': 
				{
					char top = sta.top();
					if(top == '{')
						sta.pop();
					else
						return false;
					break;
				}
			}
		}
		if(sta.size() == 1) return true;
		else return false;
    }
<<<<<<< HEAD
};
=======
};
>>>>>>> e5be46318e0111412a04ae1d0df1c120c2d93f11
