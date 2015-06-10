/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Tags: Divide and Conquer Array Dynamic Programming
*/

/*
算法1：DP，O(n)
已知了前k个元素的最大子序列和为maxSub（已经被记录下来了），以及一个临时和sum，
如果添加了第k+1这个元素，由于是连续子序列这个限制，所以如果k+1这个元素之前的和是小于0的，那么对于增大k+1这个元素从而去组成最大子序列是没有贡献的，所以可以把sum 置0。
举个例子：-1，-2，4，-5，7这里假定7为第k+1个元素，那么很明显可以看出，之前的sum = -5+4 = -1，那么这样对于7来说只会减少它，所以直接置sum = 0，0 + 7才能得到正确的答案。
再拓展这个数组：-1， -2， 4， -5， 7， 1 这里1之前的sum = 7 > 0，对于后面的1来组成最大子序列是有贡献的，所以sum = 7 + 1 =8。
再注意一点，只要sum不减到负数，中间出现小于0的元素是没关系的，sum仍然可以继续累加。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -1;
		int res = INT_MIN;
		for(int i = 0; i< nums.size(); i++){
			if(sum > 0)
				sum += nums[i];
			else
				sum = nums[i];
			if(res < sum) res = sum;
		}
		return res;
    }
};

/*
算法2：分治法，O(logn)
由于我们知道最大子序列可能存在于A数组的左边，右边，或者一点左边一点右边。 
所以我们很容易可以联想到，既然这样我们可以把A数组划分成若干个小的子数组，
对子数组求出左边的最大值，和右边的最大值，再求出从中间位置到左边的某个位置的最大值、从中间位置到右边的某个位置的最大值，
得到了这四个值之后剩下的我们就可以通过比较得到这个子数组的最大值了。（递归的过程） 
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
	int helper(vector<int>& nums, int start, int end){
		if(start == end) return nums[end];
		int middle = (start + end) / 2;
		int maxLeft = helper(nums, start, middle);
		int maxRight = helper(nums, middle + 1, end);
		
		int leftNum = nums[middle];
		int temp = leftNum;
		for(int i = middle - 1; i >= start; i--){
			temp += nums[i];
			if(leftNum < temp) leftNum = temp;
		}
		
		int rightNum = nums[middle + 1];
		temp = rightNum;
		for(int i = middle + 2; i <= end; i++){
			temp += nums[i];
			if(rightNum < temp) rightNum = temp;
		}
		return max(max(maxLeft, maxRight), leftNum + rightNum);
	}
};