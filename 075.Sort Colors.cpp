/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

Tags: Array Two Pointers Sort
*/

/*
题目说了一大堆，就是让对一个数组排序，数组中的元素只有0、1、2，并且要求只能遍历一遍数组，常数空间复杂度。
借助于快速排序的partition思想，以1为枢纽元对数组进行划分，使0在数组的左边，2在数组的右边，1在数组的中间。
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
		//zeroEnd是放0那部分的尾部索引，twoBegin是放2那部分的首部索引
        //碰到0放到zeroEnd+1处，碰到2放到twoEnd-1处，碰到1指针后移
        if(nums.empty()) return;
		int zeroEnd = -1, twoBegin = nums.size(), i = 0;
		while(i < twoBegin){
			if(nums[i] == 0 && i != ++zeroEnd){
				swap(nums[i], nums[zeroEnd]);
			} else if(nums[i] == 2 && i != --twoBegin){
				swap(nums[i], nums[twoBegin]);
			} else {
				i++;
			}
		}
    }
};