/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Tags: Hash Table Bit Manipulation
*/

/*����һ������Ԫ��������ս�����ǳ���һ�ε���*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
		for(int i = 0; i < nums.size(); i++)
			res = res ^ nums[i];
		return res;
    }
};

/*��������hashtable���ռ临�Ӷ�ΪO(n)*/
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