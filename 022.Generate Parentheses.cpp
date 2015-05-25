/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

Tags: Backtracking String
*/

/*
小括号串是一个递归结构，跟单链表、二叉树等递归结构一样，首先想到用递归。
一步步构造字符串。当左括号出现次数<n时，就可以放置新的左括号。
当右括号出现次数小于左括号出现次数时，就可以放置新的右括号。
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
		string tempRes;
		generate(res, tempRes, n, n);
		return res;
    }
	void generate(vector<string>& res, string &tempRes, int left, int right){
		//left:左括号剩余个数，right:右括号剩余个数
		if(left == 0 && right == 0){
			res.push_back(tempRes);
			return;
		}
		if(left > 0){
			tempRes.push_back('(');
			generate(res, tempRes, left-1, right);
			tempRes.pop_back();
		}
		if(right > 0 && left < right){
			tempRes.push_back(')');
			generate(res, tempRes, left, right-1);
			tempRes.pop_back();
		}
	}
};