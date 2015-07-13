/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

Tags: Stack
*/

/*这一题就是写程序计算逆波兰式的结果，遍历表达式，碰到操作数入栈，碰到操作符就从栈顶取出两个操作数，再将计算后的结果入栈，最后栈中剩余的唯一操作数就是计算结果。*/
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