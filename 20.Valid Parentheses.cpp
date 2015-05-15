/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Tags: Stack String
*/

/*
直接用栈
*/
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return false;
		stack<int> sta;
		sta.push('#'); //防止pop时stack为空
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
};