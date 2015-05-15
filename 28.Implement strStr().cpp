/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Tags: Two Pointers String
*/

/*
�������������ѭ���Ƚϣ�O(n*m)
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
KMP�㷨��
1������ƶ������αȽϣ�
2��������ƥ���ַ���Ӧ������ǰ���Ѿ���ƥ���Ӵ�������ƶ�nλ�������ǽ����ƶ�һλ��
3���ƶ�λ��n = ��ƥ���Ӵ��ַ��� - �Ӵ���Ӧ�Ĳ���ƥ��ֵ

ʵ�ֹؼ���
1����������ƥ��ֵ�������next�����У�
2�����next���飺http://www.cnblogs.com/c-cloud/p/3224788.html��
3������next�������ƥ�䣻
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
		//ע�⣺������Ӵ�һ��������һͷһβ���������ҶԳƵ�
		for(int k = 0, p = 1; p < m; p++){
			if(k > 0 && needle[p] != needle[k])
				//��ƥ�䣬����ǰ����ƥ���Ӵ���Ѱ��������Ӵ����ټ����Ƚ�
				k = next[k-1];
			if(needle[p] == needle[k])
				k++;
			next[p] = k;
		}
		
		int i,j = 0;
		for(i = 0; i < n; ++i){
			while(j > 0 && haystack[i] != needle[j])
				j = next[j - 1];//�൱�ڣ��ƶ�λ�� = j - next[j - 1];
			if(haystack[i] == needle[j])
				++j;
			if(j == m)
				break;
		}
		delete[] next;
		return j == m ? i - m + 1 : j;
    }
};