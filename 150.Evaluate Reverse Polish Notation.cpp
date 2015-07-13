/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

Tags: Stack
*/

/*��һ�����д��������沨��ʽ�Ľ�����������ʽ��������������ջ�������������ʹ�ջ��ȡ���������������ٽ������Ľ����ջ�����ջ��ʣ���Ψһ���������Ǽ�������*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
		stack<int> numsStack;
		
		for(int i = 0; i < tokens.size(); i++){
			string ops = tokens[i];
			if(ops == "+" || ops == "-" || ops == "*" || ops == "/"){
				int num2 = numsStack.top();
				numsStack.pop();
				int num1 = numsStack.top();
				numsStack.pop();
				numsStack.push(op(num1, num2, ops));
			} else {
				numsStack.push(stoi(ops));
			}
		}
		return numsStack.top();
    }
	
	int op(int num1, int num2, string ops){
		if(ops == "+") return num1 + num2;
		if(ops == "-") return num1 - num2;
		if(ops == "*") return num1 * num2;
		if(ops == "/") return num1 / num2;
	}
};