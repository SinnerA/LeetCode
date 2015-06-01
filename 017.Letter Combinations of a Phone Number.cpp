/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Tags: Backtracking String
*/

/*
算法1：递归bfs
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
		if(digits.size() == 0) return res;
		string tempRes;
		string umap[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		dfs(res, tempRes, umap, digits, 0);
		return res;
    }
	void dfs(vector<string> &res, string &tempRes, string umap[], string &digits, int index){
		if(index == digits.size()){
			res.push_back(tempRes);
			return;
		}
		for(int i = 0; i < umap[digits[index] - '0'].size(); i++){
			tempRes.push_back(umap[digits[index] - '0'][i]);
			dfs(res, tempRes, umap, digits, index+1);
			tempRes.pop_back();
		}
	}
};

/*
算法2：非递归，即将上面的递归改为非递归
如digits='234'，即"abc", "def", "ghi"，则依次遍历"ghi"，遍历完，将"def"前进一位，再次遍历"ghi"，以此类推。
相当于，多层循环，次数为digits的长度，最里面一层循环是对最后一个单词的循环。
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
		if(digits.size() == 0) return res;
		vector<int> ansIndex(digits.size(), 0); //各个字符位于单词的index，用于取各个位置的字符，组合起来即为一个新单词
		string umap[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		
		while(true){
			string tempRes;
			for(int i = 0; i < digits.size(); i++){
				tempRes.push_back(umap[digits[i] - '0'][ansIndex[i]]);
			}
			res.push_back(tempRes);
			int k = digits.size() - 1;
			while(k >= 0){
				if(ansIndex[k] < umap[digits[k] - '0'].size() - 1){
					ansIndex[k]++;
					break;
				} else {
					ansIndex[k] = 0; //复位
					k--;
				}
			}
			if(k < 0) break;
		}
		return res;
    }
};

/*
非递归的dfs
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
		if(digits.size() == 0) return res;
		res.push_back("");
		string umap[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		
		for(int i = 0; i < digits.size(); i++){
			vector<string> tempRes;
			for(int j = 0; j < res.size(); j++)
				for(int k = 0; k < umap[digits[i] - '0'].size(); k++)
					tempRes.push_back(res[j] + umap[digits[i] - '0'][k]);
			res = tempRes;
		}
		return res;
    }
};









