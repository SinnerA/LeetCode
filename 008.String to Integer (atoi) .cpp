/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

Tags: Math String

实现字符串转整数的函数，需要注意的几点：

1、对于非法输入，函数输出0（除了溢出）

2、处理输入NULL

3、处理数字前面的空格

4、处理数字前面的0

5、处理溢出

6、注意“+ 123”输入是非法的
*/

/*
方法一：使用long long
*/
class Solution {
public:
    int myAtoi(string str) {
		if(str.empty()) return 0; //处理NULL
		int i = 0;
		while(str[i] == ' ') ++i; //处理前面空格
		bool sign = true;
		if(str[i] == '-'){          //判断符号位
			sign = false;
			++i;
		} else if(str[i] == '+'){
			++i;
		}
		while(str[i] == '0') ++i; //处理前面的0
		
		long long res = 0;
		while(str[i] != '\0' && str[i] >= '0' && str[i] <= '9'){
			res = (int)(str[i] - '0') + res*10;
			if(res > INT_MAX) return sign == true ? INT_MAX : INT_MIN; //处理溢出
			++i;
		}
		return sign == true ? res : res * (-1);
    }
};


/*
方法二：使用int
*/
class Solution {
public:
    int myAtoi(string str) {
		if(str.empty()) return 0; //处理NULL
		int i = 0;
		while(str[i] == ' ') ++i; //处理前面空格
		bool sign = true;
		if(str[i] == '-'){          //判断符号位
			sign = false;
			++i;
		} else if(str[i] == '+'){
			++i;
		}
		while(str[i] == '0') ++i; //处理前面的0
		
		int res = 0, lastRes = 0;
		int limit = INT_MAX/10;
		while(str[i] != '\0' && str[i] >= '0' && str[i] <= '9'){
			if(res > limit) return sign == true ? INT_MAX : INT_MIN;  //处理溢出(两个数相乘溢出后，溢出的结果不一定比两个乘数小)
			lastRes = res;
			res = res*10 + (int)(str[i] - '0');
			if(res < lastRes) return sign == true ? INT_MAX : INT_MIN; //处理溢出
			++i;
		}
		return sign == true ? res : res * (-1);
    }
};

















