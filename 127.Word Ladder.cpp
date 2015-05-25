/*
Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
Tags: Breadth-first Search
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        int res = 1;
		int strLen = beginWord.size(); //strlen只能用于char*
		queue<string> myQueue;
		myQueue.push(beginWord);
		myQueue.push(""); //""表示每一层节点的分割标志
		while(!myQueue.empty()){
			string s = myQueue.front();
			myQueue.pop();
			if(s != ""){
				for(int i = 0; i < strLen; i++){
					string savedStr = s; //保存，以便恢复
					char temp = s[i];
					for(char ch = 'a'; ch <= 'z'; ch++){
						if(temp == ch) continue;
						s[i] = ch;
						if(s == endWord){
							res++;
							return res;
						}
						if(wordDict.find(s) != wordDict.end()){
							myQueue.push(s);
							wordDict.erase(s); //要从字典中删除，因为不删除的话会造成类似于hog->hot->hog的死循环
						}
					}
					s = savedStr;
				}
			} else {
				res++;
				if(!myQueue.empty()) myQueue.push("");
			}
		}
		return 0;
    }
};