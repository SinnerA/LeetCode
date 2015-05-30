/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
Tags: Backtracking
*/

/*
�㷨1��
���ȶ��ַ����������Ӵ��ж��Ƿ��ǻ��ģ���f[i][j] = true��ʾ��iΪ��㣬����Ϊj���Ӵ��ǻ���,����false��ʾ���ǻ��ģ���ô��f[i][j]�Ķ�̬�滮�������£�

��j = 1��f[i][j] = true;

��j = 2��f[i][j] = (s[i]==s[i+1]),����s�������ַ���	

��j > 2, f[i][j] = f[i+1][j-2] && (s[i] == s[i+j-1])�����ж�s[m..n]�Ƿ��ǻ���ʱ��ֻҪs[m+1...n-1]�ǻ��Ĳ���s[m] = s[n]����ô�����ǻ��ģ������ǻ��ģ�
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
		int len = s.size();
        vector<vector<string> > res;
		if(len == 0) return res;
		//f[i][j]��ʾ��iΪ��㣬����Ϊj���Ӵ��ǻ��Ĵ�
		bool **f = new bool* [len];
		for(int i = 0; i < len; i++){
			f[i] = new bool[len+1]
			for(int j = 0; j < len + 1; j++)
				f[i][j] = false;
			f[i][1] = true;
		}
		for(int j = 2; j <= len; j++)
			for(int i = 0; i <= len-j; i++){
				if(j == 2)
					f[i][j] = (s[i] == s[i+1]);
				else
					f[i][j] = f[i+1][j-2] && (s[i] == s[i+j-1]);
			}
		vector<string> tempRes;
		dfs(s, f, res, tempRes, 0);
		for(int i = 0; i < len; i++)
			delete [](f[i]);
		delete []f;
		return res;
    }
	void dfs(const string &s, bool **f, vector<vector<string> > &res, vector<string> &tempRes, int start){
		//startΪ���������
		if(start >= s.size()){
			res.push_back(tempRes);
			return;
		}
		for(int len = 1; len <= s.size() - start; len++){
			if(f[start][len] == true){
				tempRes.push_back(s.substr(start, len));
				dfs(s, f, res, tempRes, start+len);
				tempRes.pop_back();
			}
		}
	}
};











