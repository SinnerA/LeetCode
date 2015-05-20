/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Tags: Two Pointers String
*/

/*
暴力解决：依次循环比较，O(n*m)
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; ; i++){
			for(int j = 0; ; j++){
				if(j == needle.length())
					return i;
				if(i + j == haystack.length())
					return -1;
				if(haystack[i + j] != needle[j])
					break;
			}
		}
    }
};

/*
KMP算法：
1：向后移动，依次比较；
2：遇到不匹配字符，应该利用前面已经已匹配子串，向后移动n位，而不是仅仅移动一位；
3：移动位数n = 已匹配子串字符数 - 子串对应的部分匹配值

实现关键：
1：构建部分匹配值，存放于next数组中；
2：求解next数组：http://www.cnblogs.com/c-cloud/p/3224788.html；
3：依据next数组进行匹配；
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
		if(needle.empty())
			return 0;
		if(haystack.empty() && !needle.empty())
			return -1;
		
		int n = haystack.length();
		int m = needle.length();
		int *next = new int[m+1];
		next[0] = 0;
		//注意：最长公共子串一定出现在一头一尾，即是左右对称的
		for(int k = 0, p = 1; p < m; p++){
			if(k > 0 && needle[p] != needle[k])
				//不匹配，则在前面已匹配子串中寻找最长公共子串，再继续比较
				k = next[k-1];
			if(needle[p] == needle[k])
				k++;
			next[p] = k;
		}
		
		int i,j = 0;
		for(i = 0; i < n; ++i){
			while(j > 0 && haystack[i] != needle[j])
				j = next[j - 1];//相当于：移动位数 = j - next[j - 1];
			if(haystack[i] == needle[j])
				++j;
			if(j == m)
				break;
		}
		delete[] next;
		return j == m ? i - m + 1 : j;
    }
};