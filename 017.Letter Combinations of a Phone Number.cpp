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
�㷨1���ݹ�bfs
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
�㷨2���ǵݹ飬��������ĵݹ��Ϊ�ǵݹ�
��digits='234'����"abc", "def", "ghi"�������α���"ghi"�������꣬��"def"ǰ��һλ���ٴα���"ghi"���Դ����ơ�
�൱�ڣ����ѭ��������Ϊdigits�ĳ��ȣ�������һ��ѭ���Ƕ����һ�����ʵ�ѭ����
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
		if(digits.size() == 0) return res;
		vector<int> ansIndex(digits.size(), 0); //�����ַ�λ�ڵ��ʵ�index������ȡ����λ�õ��ַ������������Ϊһ���µ���
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
					ansIndex[k] = 0; //��λ
					k--;
				}
			}
			if(k < 0) break;
		}
		return res;
    }
};

/*
�ǵݹ��dfs
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









