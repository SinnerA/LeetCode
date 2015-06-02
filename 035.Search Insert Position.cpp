/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

Tags: Array Binary Search
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
		while(low <= high){
			mid = left + (high - left) / 2;
			if(nums[mid] < target)
				low = mid + 1;//遇到小于target的数，往后移，最后lower指向第一个大于target的数
			else if(nums[mid] > target)
				high = mid - 1;
			else
				return mid;
		}
		return low;
    }
};