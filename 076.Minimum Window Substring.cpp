/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

Tags: Hash Table Two Pointers String
*/

/*
可以利用两个指针扫描（两个指针分别为start，i），以S = “e b a d b a c c b”（忽略空格），T = “abc”为例：
                                                       0 1 2 3 4 5 6 7 8
1、初始化 start = i = 0
2、i 逐渐往后扫描S直到窗口S[start…i]包含所有T的字符，此时i = 6（字符c的位置）
3、缩减窗口：此时我们注意到窗口并不是最小的，需要调整 start 来缩减窗口。缩减规则为：如果S[start]不在T中或者 S[start]在T中但是删除后窗口依然可以包含T中的所有字符，
那么start = start+1， 直到不满足上述两个缩减规则。缩减后i即为窗口的起始位置，此例中从e开始窗口中要依次删掉e、b、a、d，start最后等于4 ，那么得到一个窗口大小为6-4+1 = 3
4、start = start+1(此时窗口肯定不会包含所有的T中的字符)，跳转到步骤2继续寻找下一个窗口。本例中还以找到一个窗口start = 5，i = 8，比上个窗口大，因此最终的最小窗口是S[4…6]

具体实现时，
要用哈希表来映射T中字符以便在O(1)时间内判断一个字符是否在T中，由于是字符缘故，可以用数组简单的来实现；
还需要一个哈希表来记录扫描时T中的某个字符在S中出现的次数，也可以用数组实现
*/

class Solution {
public:
    string minWindow(string s, string t) {
		int lenS = s.size(), lenT = t.size();
		if(lenT == 0 || lenS < lenT) return "";
		
		int curCnt[128] = {0};   //当前找到t中每个字母的个数
		int wordsCnt[128] = {0}; //t中每个字母的个数
		for(int i = 0; i < lenT; i++)
			++wordsCnt[t[i]];
		int winStart = -1, winEnd = lenS; //窗口的左右边界
		int cnt = 0;                      //已经找到的字母数目
		
		//两个指针start和i一起扫描，分别代表头尾
		for(int i = 0, start = 0; i < lenS; i++){
			if(wordsCnt[s[i]] > 0){
				curCnt[s[i]]++;
				if(curCnt[s[i]] <= wordsCnt[s[i]]) cnt++;
				if(cnt == lenT){
					//找到了一个满足的窗口
					while(wordsCnt[s[start]] == 0 || curCnt[s[start]] > wordsCnt[s[start]]){
						//缩减窗口
						if(wordsCnt[s[start]] > 0)
							curCnt[s[start]]--;
						start++;
					}
					if(winEnd - winStart > i - start){
						winStart = start;
						winEnd = i;
					}
					curCnt[s[start]]--;
					start++;
					cnt--;
				}
			}
		}
		return winStart == -1 ? "" : s.substr(winStart, winEnd - winStart + 1);
    }
};