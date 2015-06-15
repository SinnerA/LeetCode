/*
Write a function to find the longest common prefix string amongst an array of strings.

Tags: String
*/

/*
2个字符串的最长公共前缀，其长度肯定不会超过最短的字符串的长度，设最短的字符串长度为n，那么只要比较这2个字符串的前n个字符即可。
如此得出这2个字符串的最长公共前缀prefix后，再拿prefix作为新的字符串和数组中的下一个字符串比较，方法同上。
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
		if(strs.size() == 0) return res;
		
		string preStr = strs[0];
		int compLen = 0;
		for(int i = 1; i < strs.size(); i++){
			if(preStr.size() < strs[i].size())
				compLen = preStr.size();
			else
				compLen = strs[i].size();
			
			int j;
			for(j = 0; j < compLen; j++){
				if(preStr[j] != strs[i][j])
					break;
			}
			preStr = preStr.substr(0, j);
		}
		return preStr;
    }
};