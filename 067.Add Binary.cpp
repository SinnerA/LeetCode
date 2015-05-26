/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

Tags: Math String
*/

class Solution {
public:
    string addBinary(string a, string b) {
		string res;
		int i = a.size() - 1, j = b.size() - 1;
		int carry = 0;
		int num1, num2, sum;
		for(; i >=0 && j >= 0; i--,j--){
			num1 = a[i] - '0';
			num2 = b[j] - '0';
			sum = num1 + num2 + carry;
			if(sum > 1){
				carry = 1;
				sum -= 2;
			} else {
				carry = 0;
			}
			res.push_back(sum + '0');
		}
		for(; i >= 0; i--){
			num1 = a[i] - '0';
			sum = num1 + carry;
			if(sum > 1){
				carry = 1;
				sum -= 2;
			} else {
				carry = 0;
			}
			res.push_back(sum + '0');
		}
		for(; j >= 0; j--){
			num1 = b[j] - '0';
			sum = num1 + carry;
			if(sum > 1){
				carry = 1;
				sum -= 2;
			} else {
				carry = 0;
			}
			res.push_back(sum + '0');
		}
		if(carry == 1)
			res.push_back('1');
		reverse(res.begin(), res.end());
		return res;
    }
};