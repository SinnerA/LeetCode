/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Tags: Math
*/

//注意：x需要声明成long long，防止溢出
class Solution {
public:
    int reverse(int x) {
		long long res = 0;
		long long tempX = x;
		bool sign = false;
		if(tempX < 0){
			tempX *= -1;
			sign = true;
		}
		while(tempX){
			res = res*10 + tempX%10;
			tempX /= 10;
		}
		if(sign) res *= -1;
		if(res > INT_MAX || res < INT_MIN) return 0;
		return res;
    }
};