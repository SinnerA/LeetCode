/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

Tags: Math Binary Search
*/

/*
最直观：被除数减去除数，知道被除数为0。但是会超时，如dividend = -2147483648，divisor = -1
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        int count = 0;
		bool isPositive = true;
		if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
			isPositive = false;
		if(dividend < 0) dividend *= -1;
		if(divisor < 0) divisor *= -1;
		while(true){
			dividend = dividend - divisor;
			if(dividend > 0) count++;
			else break;
		}
		if(dividend == 0) count++;
		return isPositive ? count : count*(-1);
    }
};

/*
算法1：按照上面的方法，每次减一，计算速度太慢。但是题目不能使用乘法，因此不能减去k*除数。
我们可以对除数进行左移位操作，这样每次相当于减去2^k个除数，如何确定k呢，只要使(2^k)*除数 <= 当前被除数 < (2^(k+1))*除数。
*/

/*
注意：计算机内部，数据的存储都是一致的，有正负以及溢出的概念，都是规定的表示方式不同而已。int会计算符号位，而unsigned int忽略符号位，
unsigned int范围：0 ~ 4294967295 (4 Bytes).使用long long时，要注意表达方式，如1写成1ll，这时计算时，int自动转换成long long。
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
		long long res = 0;
		long long divd = dividend, divs = divisor;
		if(dividend < 0) divd = divd*(-1);
		if(divisor < 0) divs = divs*(-1);
			
		while(divd >= divs){
			long long ldivs = divs;//防止移位溢出
			int i = 1;
			for(; ldivs <= divd; i++)
				ldivs <<= 1;
			res += (1ll << (i-2));
			divd -= (divs << (i-2));
		}
		bool isPositive = !(dividend > 0 ^ divisor > 0);
		if(isPositive && res > INT_MAX) return INT_MAX;
		return isPositive ? res : res*(-1);
	}
};

















