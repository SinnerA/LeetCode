/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
Tags: Array Two Pointers
*/

/*
为了避免重复，对于排序后的数组，当枚举第一个数的时候，如果遇到重复的就直接跳过（已经计算过了，无需重复计算）
当找到一个符合的二元组（第二个数和第三个数）时，也分别去除重复
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > res;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for(int i = 0; i < n-2; ++i){
			if(i > 0 && nums[i] == nums[i - 1]) continue; //跳过重复，无需重复计算
			int target = 0 - nums[i];
			twoSum(nums, i + 1, target, res);
		}
		return res;
    }
	
	void twoSum(vector<int>& nums, int start, int target, vector<vector<int> >& res){
		int head = start, tail = nums.size() - 1;
		while(head < tail){
			if(nums[head] + nums[tail] < target){
				++head;
			} else if(nums[head] + nums[tail] > target){
				--tail;
			} else {
				res.push_back(vector<int>{nums[start - 1], nums[head], nums[tail]});
				
				//为了防止出现重复的二元组，使结果等于target
				int k = head + 1;
				while(k < tail && nums[k] == nums[head]) ++k;
				head = k;
				
				k = tail - 1;
				while(k > head && nums[k] == nums[tail]) --k;
				tail = k;
			}
		}
	}
};