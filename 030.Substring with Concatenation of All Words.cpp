/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

Tags: Hash Table Two Pointers String
*/

/*
���ڻ�������
����s = ��a1b2c3a1d4�� words={��a1��,��b2��,��c3������d4��}

�����ʼΪ��
a1��L�У����봰�� ��a1��b2c3a1d4
b2��L�У����봰�� ��a1b2��c3a1d4
c3��L�У����봰�� ��a1b2c3��a1d4
a1��L���ˣ�����ǰ��a1�Ѿ�����һ�Σ���ʱֻ��Ҫ�Ѵ��������ƶ�һ������a1��b2c3a1��d4
d4��L�У����봰��a1��b2c3a1d4���ҵ���һ��ƥ��
�����s��Ϊ��a1b2c3kka1d4������ô�ڵ��Ĳ��л���������kk��kk����L�У���ʱ������ʼλ���ƶ���kk����a1b2c3kk��a1d4

ע�⣺words�еĵ��ʿ����ظ���ʹ��map��
*/

/*�ο���http://m.blog.csdn.net/blog/yapian8/28095025������forѭ����ģ��windows���𵽴��ڻ���������*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
		if(words.empty()) return res;
		int n = words.size(), size = words[0].size(), totalSize = n * size;
		if(totalSize > s.size()) return res;
		
		unordered_map<string, int> curCnt;   //���map��¼��ǰ�����и������ʵ��ظ�����
		unordered_map<string, int> wordsCnt; //words�е��ʵ��ظ�����
		for(int i = 0; i < n; i++)
			++wordsCnt[words[i]];
		
		for(int i = 0; i <= s.size() - totalSize; i++){
			curCnt.clear();
			int j;
			for(j = 0; j < n; j++){
				string curStr = s.substr(i + j * size, size);
				if(find(words.begin(), words.end(), curStr) == words.end()) break;
				++curCnt[curStr];
				if(curCnt[curStr] > wordsCnt[curStr]) break; //���ִ���̫��
			}
			if(j == n) res.push_back(i);
		}
		return res;
    }
};

/*�Լ�ʵ�֣����һ����������û��o(�s���t)o*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
		if(words.empty()) return res;
		int size = words[0].size();
		int n = words.size();
		int totalSize = size * n;
		if(s.size() < totalSize) return res;
		
		unordered_map<string, int> curCnt;
		unordered_map<string, int> wordsCnt;
		for(int i = 0; i < words.size(); i++){
			++wordsCnt[words[i]];
		}
			
		string windows = "";
		int start = 0, end = 0, pos = 0;
		while(start <= s.size() - totalSize){
			string curStr = s.substr(end, size);
			if(find(words.begin(), words.end(), curStr) == words.end()){
				start = start + 1; //ע�⣺����һ��ֻ����һ��λ��
				end = start;
				windows.clear();
				curCnt.clear();
			} else {
				++curCnt[curStr];
				if(curCnt[curStr] > wordsCnt[curStr]){
					int moveDist = windows.find(curStr);
					moveDist += size;
					start += moveDist;
					curCnt.clear();
				} else {
					end += size;
					windows = windows + curStr;
					if(end - start == totalSize){
						res.push_back(start);
						windows.clear();
						curCnt.clear();
						start = start + 1;
						end = start;
					}
				}
			}
		}
		return res;
    }
};