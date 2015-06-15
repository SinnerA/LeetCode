/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

Tags: Math
*/

/*方法1：可以把数字倒转过来，如果和原来数字相同那么就是回文数，但是数字倒转后可能越界，使用long long*/
class Solution {
public:
    bool isPalindrome(int x) {
		long long reversedX = 0;
		long long savedX = x;
		if(x < 0){
			savedX = savedX * (-1);
		}
		while(x){
			reversedX = reversedX*10 + x%10;
			x /= 10;
		}
		if(reversedX == savedX) return true;
		else return false;
    }
};

/*方法2：逐个比较整数的第一个字符和最后一个字符，比如12321 第一次比较成功后数字变为232，再次比价后变为3*/
class Solution {
public:
    bool isPalindrome(int x) {
		if(x < 0) return false;
		int len = getIntegerLen(x);
		int factor = pow(10, len-1);
		
		while(x){
			if(x/factor != x%10)
				return false;
			x %= factor;
			x /= 10;
			factor /= 100;
		}
		return true;
    }
	int getIntegerLen(int x){
		int count = 0;
		while(x){
			count++;
			x /= 10;
		}
		return count;
	}
};