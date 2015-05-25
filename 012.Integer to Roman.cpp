/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

Tags: Math String
*/

/*
罗马数字共有7个，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）。

个位上的数字1~9的分别为: I II III IV V VI VII VIII IX
十位上的数字1~9，只要把原来个位上的I 替换成 X， V 替换成L，X替换成C，即十位上的1~9表示的是10~90.
*/

class Solution {
public:
    string intToRoman(int num) {
		string res;
		char romanChar[] = {'I','V','X','L','C','D','M'};
		int factor = 1000;
		int i = 6;
		while(num != 0){
			convert(num/factor, &romanChar[i], str);
			i -= 2;
			num %= factor;
			factor /= 10;
		}
		return res;
    }
	void convert(int k, char romanChar[], string& res){
		//0 <= k <= 9
		if(k <= 0);
		else if(k <= 3){
			res.append(k, romanChar[0]);
		} else if(k == 4){
			res.push_back(remanChar[0]);
			res.push_back(remanChar[1]);
		} else if(k <= 8){
			res.push_back(romanChar[1]);
			res.append(k-5, romanChar[0]);
		} else if(k == 9){
			res.push_back(romanChar[0]);
			res.push_back(romanChar[2]);
		}
	}
};