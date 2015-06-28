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
窗口滑动机制
比如s = “a1b2c3a1d4” words={“a1”,“b2”,“c3”，“d4”}

窗口最开始为空
a1在L中，加入窗口 【a1】b2c3a1d4
b2在L中，加入窗口 【a1b2】c3a1d4
c3在L中，加入窗口 【a1b2c3】a1d4
a1在L中了，但是前面a1已经算了一次，此时只需要把窗口向右移动一个单词a1【b2c3a1】d4
d4在L中，加入窗口a1【b2c3a1d4】找到了一个匹配
如果把s改为“a1b2c3kka1d4”，那么在第四步中会碰到单词kk，kk不在L中，此时窗口起始位置移动到kk后面a1b2c3kk【a1d4

注意：words中的单词可能重复（使用map）
*/

/*参考：http://m.blog.csdn.net/blog/yapian8/28095025，利用for循环来模拟windows，起到窗口滑动的作用*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
		if(words.empty()) return res;
		int n = words.size(), size = words[0].size(), totalSize = n * size;
		if(totalSize > s.size()) return res;
		
		unordered_map<string, int> curCnt;   //这个map记录当前窗口中各个单词的重复次数
		unordered_map<string, int> wordsCnt; //words中单词的重复次数
		for(int i = 0; i < n; i++)
			++wordsCnt[words[i]];
		
		for(int i = 0; i <= s.size() - totalSize; i++){
			curCnt.clear();
			int j;
			for(j = 0; j < n; j++){
				string curStr = s.substr(i + j * size, size);
				if(find(words.begin(), words.end(), curStr) == words.end()) break;
				++curCnt[curStr];
				if(curCnt[curStr] > wordsCnt[curStr]) break; //出现次数太多
			}
			if(j == n) res.push_back(i);
		}
		return res;
    }
};

/*自己实现：最后一个测试用例没过o(╯□╰)o*/
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
				start = start + 1; //注意：窗口一次只滑动一个位置
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