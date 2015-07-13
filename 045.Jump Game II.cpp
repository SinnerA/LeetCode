/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Tags: Array Greedy
*/

/*（大数据超时）从最后一个开始，找到第一个能到最后的，再往前找第一个能到新的位置的，直到第0位*/
class Solution {
public:
    int jump(vector<int>& nums) {
		if(nums.empty()) return 0;
		int step = 0, i = nums.size() - 1;
		
		while(i > 0){
			for(int j = 0; j < i; j++){
				if(nums[j] + j >= i){
					++step;
					i = j;
					break;
				}
			}
		}
		return step;
    }
};