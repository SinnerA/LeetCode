/*
Write a function to find the longest common prefix string amongst an array of strings.

Tags: String
*/

/*
2���ַ����������ǰ׺���䳤�ȿ϶����ᳬ����̵��ַ����ĳ��ȣ�����̵��ַ�������Ϊn����ôֻҪ�Ƚ���2���ַ�����ǰn���ַ����ɡ�
��˵ó���2���ַ����������ǰ׺prefix������prefix��Ϊ�µ��ַ����������е���һ���ַ����Ƚϣ�����ͬ�ϡ�
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