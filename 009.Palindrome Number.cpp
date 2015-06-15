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

/*����1�����԰����ֵ�ת�����������ԭ��������ͬ��ô���ǻ��������������ֵ�ת�����Խ�磬ʹ��long long*/
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

/*����2������Ƚ������ĵ�һ���ַ������һ���ַ�������12321 ��һ�αȽϳɹ������ֱ�Ϊ232���ٴαȼۺ��Ϊ3*/
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