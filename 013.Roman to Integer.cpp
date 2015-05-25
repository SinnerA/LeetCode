/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Tags: Math String
*/

/*
罗马数字共有7个，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）。
1、相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
2、小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
3、小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；

分析：
1:3999范围内的罗马数字不会用到加上划线的字母
2:从第一个字符开始，如果当前字符对应的数字比下一个数字小，那么就把结果减去当前字符对应的数字，否则加上当前字符对应数字。
为了处理边界情况，在原字符串最后添加一个字符，该字符是原来的尾字符。
*/

class Solution {
public:
    int romanToInt(string s) {
        int map[26];
		map['I' - 'A'] = 1; map['V' - 'A'] = 5; map['X' - 'A'] = 10;
		map['L' - 'A'] = 50; map['C' - 'A'] = 100; map['D' - 'A'] = 500; map['M' - 'A'] = 1000;
		int res = 0, n = s.size();
		s.push_back(s[n-1]); //i+1最终等于n，处理边界情况
		for(int i = 0; i < n; i++){
			if(map[s[i] - 'A'] >= map[s[i + 1] - 'A'])
				res += map[s[i] - 'A'];
			else
				res -= map[s[i] - 'A'];
		}
		return res;
    }
};