/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Tags: Array Two Pointers
*/

/*设置cnt用于计数。当counter是2时，就直接跳过即可，否则说明元素出现次数没有超，继续放入结果数组，若遇到新元素则重置counter。*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if(n == 0) return 0;
		int idx = 0, cnt = 0;
		for(int i = 0; i < n; i++){
			if(i > 0 && nums[i] == nums[i-1]){
				cnt++;
				if(cnt > 2)
					continue;
			} else {
				cnt = 1;
			}
			nums[idx++] = nums[i];
		}
		return idx;
    }
};


/*
当我们需要留下某个元素时，先暂时保存好，等到下一轮再覆盖，这样我们找前一个的前一个元素A[i-2]时，就不会出现A[i-2]原来的值被覆盖的情况。（没有搞懂囧）
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