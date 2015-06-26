/* 
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which 
the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

Tags: Hash Table Two Pointers String
*/

/*
应用hashtable，以abcdbefdhij 为例
图中的start是一个标志位，表示当前不重复子串的起始位置，图中的数字表示记录字符出现位置的数组hashtable，比如字符b出现在第1位，那么hashtable[‘b’]=1。                              本文地址
顺序扫描字符串，第4个位置时，在hashtable中发现b已经出现过（记出现的位置为k，此时k=1），那么当前的不重复子串长度 = 当前位置-start；
下一个不重复子串就应该从第k+1个字符（2号位的c）开始，即令start = 2，并且把[start, k)位置的字符对应的hashtable清空，重新设置b在hashtable的位置为4。
继续扫描直到再次发现相同的字符，和前面一样处理。注意全部处理完字符串，还要判断一下末尾的不重复子串是否是最长的。
最坏情况下，相当于遍历了两遍字符串，时间复杂度是O（n）
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if(s.empty()) return 0;
		int res = 0;
		vector<int> bitmap(128, -1);
		int start = 0, lastStart = 0;
		for(int i= 0; i < s.size(); i++){
			if(bitmap[s[i]] != -1){
				res = max(res, i - start);
				lastStart = start;
				start = bitmap[s[i]] + 1;
				for(int j = lastStart; j < bitmap[s[i]]; j++)
					bitmap[s[j]] = -1;
			}
			bitmap[s[i]] = i;
		}
		res = max(res, (int)s.size() - start);
		return res;
    }
};