/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.

Tags: String
*/

/*
这一题需要注意两个点：
a、当该行只放一个单词时，空格全部在右边 
b、最后一行中单词间只有一个空格，其余空格全部在右边。然后只要贪心选择，在一行中尽量放多的单词。  
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		if(words.empty()) return res;
		int n = words.size(), i = 0;
		
		while(i < n){
			int j = i, rowLen = 0;
			string rowStr = "";
			
			while(j < n && rowLen + words[j].size() <= maxWidth){
				rowLen += (words[j++].size() + 1);
			}
			//j-i是该行放入单词的数目
			if(j - i == 1){
				//处理放入一个单词的特殊情况
				rowStr = words[j-1];
				addSpace(rowStr, maxWidth - words[j-1].size());
				res.push_back(rowStr);
				i = j;
				continue;
			}
			
			int charLen = rowLen - (j - i);                                                                 //charaLen是当前行字母总长度
			int meanSpace = (j < n) ? (maxWidth - charLen) / (j - i - 1) : 1;                               //平均每个单词后的空格,j < len 表示不是最后一行
			int leftSpace = (j < n) ? (maxWidth - charLen) % (j - i - 1) : maxWidth - charLen - (j - i - 1);//多余的空格
            for(int k = i; k < j - 1; k++){
				rowStr += words[k];
				addSpace(rowStr, meanSpace);
				if(j < n && leftSpace > 0){
					addSpace(rowStr, 1);
					leftSpace--;
				}
			}
			rowStr += words[j - 1];         //放入最后一个单词
			
			if(leftSpace > 0){
				addSpace(rowStr, leftSpace);//最后一行
			}
			res.push_back(rowStr);
			i = j;
		}
		return res;
    }
	
	void addSpace(string &s, int cnt){
		while(cnt--)
			s.push_back(' ');
	}
};