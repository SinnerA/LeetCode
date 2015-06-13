/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Tags: Backtracking String
*/

/*回溯*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
		if(s.empty()) return res;
		string tempRes;
		dfs(s, 0, 4, res, tempRes);
		return res;
    }
	void dfs(string& s, int start, int num, vector<string>& res, string& tempRes){
		int len = s.size();
		if(num == 0){
			if(start == len){
				tempRes.erase(--tempRes.end()); //删除最后的"."
				res.push_back(tempRes);
				tempRes.push_back('.');
			}
			return;
		}
		//字符串长度不符合要求
		if(len - start < num || len - start > num*3) return;
		for(int i = 1; i <= 3 && start + i <= len; i++){
			if(validAddress(s, start, start + i - 1)){
				string tempStr = s.substr(start, i) + ".";
				tempRes += tempStr;
				dfs(s, start + i, num-1, res, tempRes);
				tempRes.erase(tempRes.end() - (i+1), tempRes.end());//注意要删除i+1个元素，因为末尾添加了"."
			}
		}
	}
	bool validAddress(string &s, int start, int end){
		if(start < end && s[start] == '0') return false;
		int res = 0;
		for(int i = start; i <= end; i++)
			res = res*10 +  (s[i] - '0');
		if(res >= 0 && res <= 255) return true;
		return false;
	}
};