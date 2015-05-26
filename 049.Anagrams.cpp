/*
Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.

For example:
Input:　["tea","and","ate","eat","den"]
Output: ["tea","ate","eat"]

Tags: Hash Table String
Anagram（回文构词法）。Anagrams是指由颠倒字母顺序组成的单词，比如“dormitory”颠倒字母顺序会变成“dirty room”，“tea”会变成“eat”。
就是某个单词打乱其字母顺序形成的新单词，新单词和原单词包含的字母种类相同，每个字母的数目相同。
*/

/*
用哈希map存储排序后的字符串，map中key为排序后字符串，value为该字符串对应的第一个原字符串在数组中的位置。
如果value = -1，表示该字符串对应的第一个源字符串已经输出过
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