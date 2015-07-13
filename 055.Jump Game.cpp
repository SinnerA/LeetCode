/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

Tags: Array Greedy
*/

/*只需要顺序扫描数组，记录下能够到达的最远位置*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
		int canArrive = 0, n = nums.size();
		
		for(int i = 0; canArrive < n-1 && i <= canArrive; i++){
			if(i + nums[i] > canArrive)
				canArrive = i + nums[i];
		}
		return canArrive >= n - 1;
    }
};