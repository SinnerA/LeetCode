/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Tags: Array Binary Search
*/

/*
想到STL中的equal_range函数，这个函数是调用lower_bound和upper_bound, 下面我们仿照STL的实现。
lower_bound当A[middle] == target时，继续向左半部分查找，它返回的是第一个不小于目标数的元素位置；
upper_bound当A[middle] == target时，继续向右半部分查找，它返回的是第一个大于目标数的元素位置。
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
		vector<int> res(2, -1);
		while(left <= right){
			mid = left + (right - left)/2;//防止溢出
			if(nums[mid] < target){
				left = mid + 1;
			} else if(nums[mid] > target) {
				right = mid - 1;
			} else {
				res[0] = lowerBound(nums, left, mid - 1, target);
				res[1] = upperBound(nums, mid + 1, right, target) - 1;
				return res;
			}
		}
		return res;
    }
	//找到范围内[left,right]内第一个不小于target的元素
	int lowerBound(vector<int>& nums, int left, int right, int target){
		while(left <= right){
			int mid = left + (right-left)/2;
			if(nums[mid] < target){
				left = mid + 1;
			} else {
				right = mid - 1;//遇到等于target的数，right依然往前移动，直到最后right指向第一个小于target的数。
			}
		}
		return right + 1;
	}
	//找到范围内[left,right]内第一个大于target的元素
	int upperBound(vector<int>& nums, int left, int right, int target){
		while(left <= right){
			int mid = left + (right-left)/2;
			if(nums[mid] <= target){
				left = mid + 1; //遇到等于target的数，left依然往后移动，直到最后left指向第一个大于target的数。
			} else {
				right = mid - 1;
			}
		}
		return left;
	}
};




