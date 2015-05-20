/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

Tags: Math String
*/

/*
方法一：设置标志位
*/
class Solution {
public:
    bool isNumber(string s) {
		if(s.empty()) return false;
		//标示可能遇到的情况
		bool canSign = true;           //下次能否出现+-
		bool canE = false;             //下次能否出现e
		bool haveE = false;            //是否已经出现e
		bool canDot = true;            //下次能否出现.
		bool havaSpaceAfterNum = false;//是否在数值后面已经出现空格
		bool canNum = false;           //下次能否出现数值
		bool haveNum = false;          //是否已经出现数值
		int i = 0;
		char ch = ' ';
		while((ch = s[i++]) != '\0'){
			if(ch == ' '){
				if(canNum)
					havaSpaceAfterNum = true; //canNum == true，说明前面已经出现数值相关内容，如+-以及.之类的
				continue;
			} else if(havaSpaceAfterNum){
				return false;
			}
			if(ch == '+' || ch == '-'){
				if(!canSign) return false;
				canSign = false;
				canNum = true;
				continue;
			}
			if(ch == 'e'){
				if(!canE) return false;
				canSign = true;  //e之后可以紧接着出现+-
				canE = false;
				haveE = true;
				canDot = false;
				canNum = true;
				haveNum = false; //遇到e，重新记录是否出现数值
				continue;
			}
			if(ch == '.'){
				if(!canDot) return false;
				canSign = false;
				//canE = false; //.之后可以紧接着出现e
				canDot = false;
				canNum = true;
				continue;
			}
			if(ch >= '0' && ch <= '9'){
				//if(!canNum) return false; //canNum不对此约束
				canSign = false;
				if(!haveE) canE = true;
				canNum = true;
				haveNum = true;
				continue;
			} else {
				return false;
			}
		}
		return haveNum;
    }
};

/*
方法二：纯粹判断，逻辑性差 http://www.cnblogs.com/TenosDoIt/p/3475305.html
*/


/*
方法三：有限状态机 http://www.cnblogs.com/chasuner/p/validNumber.html
*/