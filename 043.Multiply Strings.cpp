/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

Tags: Math String
*/

/*
把每一位相乘，得到一个没有进位的临时结果，如图中中间的一行红色数字就是临时结果，然后把临时结果从低位起依次进位。
对于一个m位整数乘以n位整数的结果，最多只有m+n位。
http://www.cnblogs.com/TenosDoIt/p/3735309.html
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
		int n1 = num1.size(), n2 = num2.size();
		if(n1 == 0 || n2 == 0) return res;
		vector<int> tempRes(n1 + n2, 0);
		int k = n1 + n2 - 2;
		for(int i = 0; i < n1; i++)
			for(int j = 0; j < n2; j++)
				tempRes[k-i-j] += (num1[i] - '0')*(num2[j] - '0');
		int carry = 0;
		for(int i = 0; i < n1 + n2; i++){
			tempRes[i] += carry;
			carry = tempRes[i]/10;
			tempRes[i] %= 10;
		}
		int i = n1 + n2 - 1;
		while(tempRes[i] == 0 && i >= 0) i--; //去掉乘积的前导0
		if(i < 0) return "0";                 //注意乘积为0的特殊情况
		for(; i >= 0; i--)
			res.push_back(tempRes[i] + '0');
		return res;
    }
};