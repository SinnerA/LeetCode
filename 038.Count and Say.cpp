/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Tags: String
*/

/*简单模拟即可*/
class Solution {
public:
    string countAndSay(int n) {
		if(n < 1) return "";
		string seq = "1";
		while(--n){
			string nextSeq;
			char ch = seq[0];
			int count = 1;       //ch出现的次数
			seq.push_back('#');  //处理边界情况
			for(int i = 1; i < seq.size(); i++){
				if(ch == seq[i]){
					count++;
				} else {
					nextSeq.push_back(count + '0');
					nextSeq.push_back(ch);
					ch = seq[i];
					count = 1;
				}
			}
			seq = nextSeq;
		}
		return seq;
    }
};