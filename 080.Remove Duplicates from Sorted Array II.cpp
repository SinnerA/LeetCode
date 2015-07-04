/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Tags: Array Two Pointers
*/

/*
当我们需要留下某个元素时，先暂时保存好，等到下一轮再覆盖，这样我们找前一个的前一个元素A[i-2]时，就不会出现A[i-2]原来的值被覆盖的情况。
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if(n == 0 || n == 1) return n;
		int cnt = 1, temp = nums[1];
		for(int i = 2; i < n; i++){
			if(nums[i] != nums[i-2]){
				nums[cnt++] = temp;
				temp = nums[i];
			}
		}
		nums[cnt++] = temp;
		return cnt;
    }
};