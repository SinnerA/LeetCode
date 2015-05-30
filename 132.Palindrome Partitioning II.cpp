/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

Tags: Dynamic Programming
*/

/*
算法1：
如题"Palindrome Partitioning"，用f来记录子串是否是回文，
另外优化最小分割次数的动态规划方程如下,mins[i] 表示子串s[0...i]的最小分割次数：
如果s[0...i]是回文，mins[i] = 0
如果s[0...i]不是回文，mins[i] = min{mins[k] +1 (s[k+1...i]是回文)  或  mins[k] + i-k  (s[k+1...i]不是回文)} ，其中0<= k < i
*/
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
		if(len <= 1) return 0;
		bool **f = new bool* [len];
		for(int i = 0; i < len; i++){
			f[i] = new bool[len+1]; //f[i][j]用于表示从i位置开始，长度为j的子串是回文串
			for(int j = 0; j <= len; j++)
				f[i][j] = false;
			f[i][1] = true;
		}
		for(int j = 2; j <= len; j++){
			for(int i = 0; i <= len - j; i++){
				if(j == 2)
					f[i][2] = (s[i] == s[i+1]);
				else
					f[i][j] = f[i+1][j-2] && (s[i] == s[i+j-1]);
			}
		}
		
		int mins[len]; //mins[i]表示子串s[0,...,i]的最小分割次数
		mins[0] = 0;
		for(int j = 2; j <= len; j++){
			if(f[0][j]){
				mins[j-1] = 0;
				continue;
			}
			mins[j-1] = j - 1; //初始化，最大值
			for(int i = 0; i < j-1; i++){ //因为求mins[j-1]，也就是区间[0,...,j-1]，所以i+1最大为j-1，即i < j-1
				int temp;
				if(f[i+1][j-i-1])
					temp = mins[i] + 1;
				else
					temp = mins[i] + j - i - 1;
				if(temp < mins[j-1]) mins[j-1] = temp;
			}
		}
		
		for(int i = 0; i < len; i++)
			delete [](f[i]);
		delete []f;
		return mins[len-1];
    }
};

/*
算法2：
设f[i][j]是i为起点，长度为j的子串的最小分割次数，f[i][j] = 0时，该子串是回文，f的动态规划方程是：
f[i][j] = min{f[i][k] + f[i+k][j-k] +1} ,其中 1<= k <j
这里f充当了两个角色，一是记录子串是否是回文，二是记录子串的最小分割次数，可以结合上一题的动态规划方程，算法复杂度是O(n^3)
*/
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
		if(len <= 1) return 0;
		int **f = new int* [len];
		for(int i = 0; i < len; i++){
			f[i] = new int* [len+1]; //f[i][j]表示以i为起点，长度为j的子串的最小分割数
			for(int j = 0; j < len+1; i++)
				f[i][j] = len;
			f[i][1] = 0;
		}
		for(int j = 2; j <= len; j++){
			for(int i = 0; i <= len - j; i++){
				if(j == 2)
					f[i][j] = (s[i] == s[i+1]) ? 0 : 1;
				else if(f[i+1][j-2] == 0 && s[i] == s[i+j-1])
					f[i][j] = 0;
				else{
					f[i][j] = j - 1;
					for(int k = 1; k < j; k++){
						if(f[i][k] + f[i+k][j-k] + 1 < f[i][j])
							f[i][j] = f[i][k] + f[k+1][j-k] + 1;
					}
				}
			}
		}
		
		for(int i = 0; i < len; i++)
			delete [](f[i]);
		delete []f;
		return f[0][len];
    }
};


