/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Tags: Array Math
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits);
		int carry = 1, len = digits.size(), i;
		for(i = len-1; i >= 0; i--){
			if(carry == 0){
				break;
			} else {
				res[i] += carry;
				if(res[i] >= 10){
					carry = 1;
					res[i] -= 10;
				} else {
					carry = 0;
				}
			}
		}
		if(i < 0 && carry == 1)
			res.insert(res.begin(), carry);
		return res;
    }
};