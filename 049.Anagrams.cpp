/*
Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.

For example:
Input:��["tea","and","ate","eat","den"]
Output: ["tea","ate","eat"]

Tags: Hash Table String
Anagram�����Ĺ��ʷ�����Anagrams��ָ�ɵߵ���ĸ˳����ɵĵ��ʣ����硰dormitory���ߵ���ĸ˳����ɡ�dirty room������tea�����ɡ�eat����
����ĳ�����ʴ�������ĸ˳���γɵ��µ��ʣ��µ��ʺ�ԭ���ʰ�������ĸ������ͬ��ÿ����ĸ����Ŀ��ͬ��
*/

/*
�ù�ϣmap�洢�������ַ�����map��keyΪ������ַ�����valueΪ���ַ�����Ӧ�ĵ�һ��ԭ�ַ����������е�λ�á�
���value = -1����ʾ���ַ�����Ӧ�ĵ�һ��Դ�ַ����Ѿ������
*/
class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
		typedef unordered_map<string, int> Umap;
		vector<string> res;
        Umap dict;
		for(int i = 0; i < strs.size(); i++){
			string s = strs[i];
			sort(s.begin(), s.end());
			Umap::iterator it = dict.find(s);
			if(it == dict.end()){
				dict.insert(Umap::value_type(s, i));
			} else {
				if(it->second != -1){
					res.push_back(strs[it->second]);
					it->second = -1;
				}
				res.push_back(strs[i]);
			}
		}
		return res;
    }
};