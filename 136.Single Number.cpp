/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Tags: Hash Table Bit Manipulation
*/

/*方法一：所有元素异或，最终结果就是出现一次的数*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
		for(int i = 0; i < nums.size(); i++)
			res = res ^ nums[i];
		return res;
    }
};

/*方法二：hashtable，空间复杂度为O(n)*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
		int n = nums.size();
		unordered_map<int, int> map;
		for(int i = 0; i < n; i++){
			map[nums[i]] = -1;
		}
		for(int i = 0; i < n; i++){
			if(map[nums[i]] == -1){
				map[nums[i]] = 1;
			} else {
				map[nums[i]] = 2;
			}
		}
		for(int i = 0; i < n; i++){
			if(map[nums[i]] == 1){
				res = nums[i];
				break;
			}
		}
		return res;
    }
};