/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

Tags: Math String
*/

/*
??????:??????????,?????????????,????????????????????m?????n??????,????m+n??
???:http://www.cnblogs.com/TenosDoIt/p/3735309.html
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
		while(tempRes[i] == 0 && i >= 0) i--; //???????0
		if(i < 0) return "0";                 //???0?????
		for(; i >= 0; i--)
			res.push_back(tempRes[i] + '0');
		return res;
    }
};