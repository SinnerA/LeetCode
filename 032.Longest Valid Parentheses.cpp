/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Tags: Dynamic Programming String
*/

/*
�㷨1����̬�滮, �ַ���Ϊs����bool����dp[i][j]��ʾ�Ӵ�s[i��j]�Ƿ������ȫƥ�䣬��ô��̬�滮��������:

��ʼ��dp����Ϊfalse
���dp[i+1][j-1] == true && s[i] == ��(��&&s[j] == ��)������ ����k = i+1��j-1 ʹ��dp[i][k] == true && dp[k+1][j] = true ����dp[i][j] = true
���̵���˼�ǣ�Ҫʹ�Ӵ�s[i��j]�ܹ���ȫƥ�䣬��ô��������������������㣺a���Ӵ�s[i+1��j-1]��ȫƥ�䣬��s[i]��s[j]���������������ţ�b������ĳ��k��ʹ�������Ӵ�s[i��k]��s[k+1��j]������ȫƥ��.

�������dp[i][j]���ƥ���Ӵ��ĳ��� = max {j-i}, ���� dp[i][j] = true;

���������isValid�൱�ڷ����е�dp��ע�⵽�Ӵ�����Ϊ����ʱ���Ӵ���������ȫƥ�䡣�����ʱ�临�Ӷ�ΪO��n^3����oj�ϴ����ݳ�ʱ
*/
class Solution {
public:
    int longestValidParentheses(string s) {
		if(s.empty()) return 0;
		int n = s.size(), res = 0;
		int dp[n][n]; //dp[i][j]��ʾ�Ӵ��Ƿ������ȫƥ��
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n - 1; i++){
			if(s[i] == '(' && s[i+1] == ')'){
				dp[i][i+1] = 1;
				res = 2;
			}
		}
		
		for(int len = 4; len <= n; len += 2){ //k��ʾ�Ӵ����ȣ�ֻ�г���Ϊż�����Ӵ��ſ����ǺϷ�����
			for(int i = 0; i <= n-len; i++){  //i��ʾ�Ӵ�����ʼλ��
				int j = i + len - 1;
				if(dp[i+1][j-1] && s[i] == '(' && s[j] == ')'){
					dp[i][j] = 1;
				} else {
					for(int k = i+1; k < j-1; k++){
						if(dp[i][k] && dp[k+1][j]){
							dp[i][j] = 1;
						}
					}
				}
				if(dp[i][j]) res = len;
			}
		}
		return res;
    }
};

/*	
�㷨2���ڴ�������ƥ�������ϣ�����һ��ʹ��ջ�����

˳��ɨ���ַ�����
��ʼ������ջ��ѹ��-1
һ������������������ѵ�ǰλ��ѹ��ջ��
������������������
     ��1�������ջ��Ԫ�ز��ǡ���������ѵ�ǰλ��ѹ��ջ�У�
     ��2�������ջ��Ԫ��ʱ��������ջ��Ԫ�س�ջ����ǰ�ĺϷ��Ӵ����� = ��ǰ�ַ����� - �µ�ջ��Ԫ�أ���������Ӵ�����

���磺())()()
ɨ�赽��0���ַ�������ʱ��0��ջ
ɨ�赽��1���ַ�������ʱ��ջ����Ӧ�ַ�Ϊ����������ջ��0��ջ����ǰ�Ϸ��Ӵ����� = 1 - �µ�ջ��Ԫ�أ�-1�� = 2��
ɨ�赽��2���ַ�������ʱ��ջ��Ϊ-1�����2��ջ
ɨ�赽��3���ַ�������ʱ��3��ջ
ɨ�赽��4���ַ�������ʱ��ջ����Ӧ�ַ�Ϊ����������ջ��3��ջ����ǰ�Ϸ��Ӵ����� = 4 - �µ�ջ��Ԫ�أ�2�� = 2��
ɨ�赽��5���ַ�������ʱ��5��ջ
ɨ�赽��6���ַ�������ʱ��ջ����Ӧ�ַ�Ϊ����������ջ��5��ջ����ǰ�Ϸ��Ӵ����� = 6 - �µ�ջ��Ԫ�أ�2�� = 4��

��Ҫע����ǣ���ǰ�Ϸ��Ӵ������� != ��ǰ���� - �뵱ǰ�ġ�����ƥ��ġ����������� + 1, ����ɨ�赽��6���ַ�������ʱ����ǰ�Ϸ��Ӵ����Ȳ��ǵ���6-5+1 = 2����Ҫ���ǵ���ǰ���Ѿ�ƥ���3��4��λ
�㷨ʱ��ռ临�Ӷȶ���O��n��
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
		int n = s.size(), res = 0;
		stack<int> myStack;
		myStack.push(-1);//Ϊ�˴���߽���������ջ�����-1
		
		for(int i = 0; i < n; i++){
			if(s[i] == '('){
				myStack.push(i);
			} else {
				int topIndex = myStack.top();
				if(topIndex >= 0 && s[topIndex] == '('){
					//s[i]���Ժ�s[myStack.top()]ƥ��
					myStack.pop();
					if(i - myStack.top() > res) res = i - myStack.top();
				} else {
					myStack.push(i);
				}
			}
		}
		return res;
    }
};






























