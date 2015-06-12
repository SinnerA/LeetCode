/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Tags: Array Binary Search
*/

/*
算法1：思路与题“033.Search in Rotated Sorted Array”一样
但是上题的所有分析是基于数组中没有重复元素的，这里存在重复元素，情况会有所不同：
修正条件a：对于上一题的三个条件中的a条件，当查找区间尾部元素等于首部元素时，也有可能表示查找区间不是有序的，比如1 1 1 3 1
修正条件c：当中间元素等于尾部元素时，也可能满足上面的条件，比如target = 3，数组为1 1 1 3 1，或者target = 1，数组为3 3 3 1 3
当三个条件都满足时，如果中间元素等于尾部元素，我们不能确定是向哪个方向继续查找，
例如target = 3，查找区间为1 1 1 3 1和1 3 1 1 1都满足target > 中间元素时的三个条件，但是两个区间分别是向middle的不同方向查找，因此此时查找区间不能折半，只能让区间的右边界减1
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int col = nums.size();
		if(col == 0) return false;
		int left = 0, right = col - 1;
		while(left <= right){
			int middle = left + (right - left) / 2;
			if(nums[middle] < target){
				if(nums[left] >= nums[right] && target >= nums[left] && nums[middle] <= nums[left]){
					if(nums[middle] == nums[left])
						left++;
					else
						right = middle - 1;
				} else {
					left = middle + 1;
				}
			} else if(nums[middle] > target){
				if(nums[left] >= nums[right] && target <= nums[right] && nums[middle] >= nums[right]){
					if(nums[middle] == nums[right])
						right--;
					else
						left = middle + 1;
				} else {
					right = middle - 1;
				}
			} else{
				return true;
			}
		}
		return false;
    }
};

/*
算法2：通过判断查找区间首部元素和中间元素的关系来判断查找区间的哪一部分是有序的

没有重复元素的情形下：
如果中间元素大于首部元素，那么表明查找区间左半部分是有序的，然后再根据target是否在有序的一部分来决定接下来查找的方向
如果中间元素小于首部元素，那么查找区间有半部分是有序的，然后再根据target是否在有序的一部分来决定接下来查找的方向
如果中间元素等于首部元素，此时只有可能是查找区间包含一个或两个元素的情形，让左边界加1继续查找即可（相当于左边界 = middle + 1，因为此时midlle等于左边界）

包含重复元素的情形：
前两种情况一样，最后一种情况当中间元素等于首部元素时，查找区间有可能不再只包含一个或两个元素，此时没法判断哪一部分有序，只能将查找区间左边界加1，其实操作和上面是相同的
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int col = nums.size();
		if(col == 0) return false;
		int left = 0, right = col - 1;
		
		while(left <= right){
			int middle = left + (right - left) / 2;
			if(nums[middle] == target) return true;
			if(nums[middle] > nums[left]){          //左半部分有序
				if(nums[middle] > target && target >= nums[left])
					right = middle - 1;
				else
					left = middle + 1;
			} else if(nums[middle] < nums[left]){  //右半部分有序
				if(nums[middle] < target && target <= nums[right])
					left = middle + 1;
				else
					right = middle - 1;
			} else {
				left++;
			}
		}
		return false;
    }
};