/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

Tags: Backtracking String
*/

/*
С���Ŵ���һ���ݹ�ṹ�����������������ȵݹ�ṹһ���������뵽�õݹ顣
һ���������ַ������������ų��ִ���<nʱ���Ϳ��Է����µ������š�
�������ų��ִ���С�������ų��ִ���ʱ���Ϳ��Է����µ������š�
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
		//left:������ʣ�������right:������ʣ�����
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