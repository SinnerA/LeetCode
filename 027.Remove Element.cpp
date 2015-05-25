/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Tags: Array Two Pointers
*/

//算法1：遍历，找到等于目标数字的元素后，只需要把数组尾部元素覆盖当前位置，不管尾部元素是否为目标数字
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size() - 1;
		int  i = 0;
		while(i <= k){
			if(nums[i] == val)
				nums[i] = nums[k--];
			else
				i++;
		}
		return k + 1;
    }
};

//算法2：把不等于目标数字的元素依次放到首部，如果不等于目标数字的元素较少，这种方法效率更高
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] != val)
				nums[k++] = nums[i];
		}
		return k;
    }
};