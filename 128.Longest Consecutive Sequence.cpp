/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

Tags: Array
*/

/*
算法1：
想要O(n)的算法，我们只有以时间换空间，先把数组中所有元素映射到哈希表。
然后以题目给出的数组为例：对于100，先向下查找99没找到，然后向上查找101也没找到，那么连续长度是1，从哈希表中删除100；
然后是4，向下查找找到3,2,1，向上没有找到5，那么连续长度是4，从哈希表中删除4,3,2,1。
这样对哈希表中已存在的某个元素向上和向下查找，直到哈希表为空。算法相当于遍历了一遍数组，然后再遍历了一遍哈希表，复杂度为O(n)。
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.size() == 0) return 0;
		int res = 1;
		unordered_set<int> hashtable;
		for(int i = 0; i < nums.size(); i++)
			hashtable.insert(nums[i]);
		while(!hashtable.empty()){
			int cur = *(hashtable.begin());
			int curLen = 1;
			hashtable.erase(cur);
			
			//递增查找
			int temp = cur + 1;
			while(!hashtable.empty() && hashtable.find(temp) != hashtable.end()){
				curLen++;
				hashtable.erase(temp);
				temp++;
			}
			
			//递减查找
			temp = cur - 1;
			while(!hashtable.empty() && hashtable.find(temp) != hashtable.end()){
				curLen++;
				hashtable.erase(temp);
				temp--;
			}
			if(curLen > res) res = curLen;
		}
		return res;
    }
};

/*
算法2：
首先想到的是排序，排序后遍历一遍就可以找出最长连续序列的长度，只是要稍微注意下判断连续序列的过程中有可能两个元素相同，比如1 2 2 3，排序复杂度n*log(n)
虽然题目要求O(n)复杂度，但是这个解法也可以通过OJ
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.size() == 0) return 0;
		int res = 1;
		sort(nums.begin(), nums.end());
		int curLen = 1;
		for(int i = 1; i < nums.size(); i++){
			if(nums[i] - nums[i-1] == 1){
				curLen++;
			} else if(nums[i] - nums[i-1] == 0){
				;
			} else {
				curLen = 1;
			}
			if(curLen > res) res = curLen;
		}
		return res;
    }
};