/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Tags: Backtracking
*/

/*
算法1：类似于DFS的递归. 对于包含n个元素的数组,先确定第一位置的元素，第一个位置有n中可能(每次把后面的元素和第一个元素交换)，然后求子数组[2…n]的全排列。
由于一个数列的总共有n!个排列，因此时间复杂度为O（n!）
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int> > res;
        int n = nums.size();
		if(n == 0) return res;
		vector<int> tempRes;
		generate(nums, res, tempRes, 0);
		return res;
    }
	void generate(vector<int>& nums, vector<vector<int> >& res, vector<int>& tempRes, int index){
		if(index == nums.size()){
			res.push_back(tempRes);
			return;
		}
		for(int i = index; i < nums.size(); i++){
			swap(nums[index], nums[i]);
			tempRes.push_back(nums[index]);
			generate(nums, res, tempRes, index + 1);
			tempRes.pop_back();
			swap(nums[index], nums[i]);
		}
	}
};
