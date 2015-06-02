/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Tags: Array Binary Search
*/

/*
运用二分查找，但是数组可能是旋转的，所以与普通的二分查找有所不同。
如target本应该在mid前半段查找，但是target实际在mid后半段，因为数组旋转，所以应该得到什么条件下，存在这种特殊情况。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
		while(start <= end){
			mid = start + (end - start) / 2; //防止溢出
			if(nums[mid] > target){
				if(nums[start] > nums[end] && target <= nums[end] && nums[mid] > nums[end])
					start = mid + 1;
				else
					end = mid - 1;
			} else if(nums[mid] < target){
				if(nums[start] > nums[end] && target >= nums[start] && nums[mid] < nums[end])
					end = mid - 1;
				else
					start = mid + 1;
			} else
				return mid;
		}
		return -1;
    }
};