/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Tags: Array Backtracking Bit Manipulation
*/

/*
算法1：递归。每一个元素有两种状态：选择，不选择
求集合的所有子集问题。题目要求子集中元素非递减序排列，因此我们先要对原来的集合进行排序。
原集合中每一个元素在子集中有两种状态：要么存在、要么不存在。
这样构造子集的过程中每个元素就有两种选择方法：选择、不选择，因此可以构造一颗二叉树，例如对于例子中给的集合[1,2,3]，
构造的二叉树中最后得到的叶子节点就是子集。我们可以用dfs来得到树的所有叶子节点
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
		if(nums.size() == 0) return res;
		vector<int> tempRes;
		sort(nums.begin(), nums.end());
		dfs(0, nums.size(), nums, tempRes, res);
		return res;
    }
	//在[left,right]范围中寻找元素加入subset中
	void dfs(int left, int right, vector<int> &nums, vector<int> &tempRes, vector<vector<int> > &res){
		if(left == right){
			res.push_back(tempRes);
			return;
		}
		//选择nums[left]
		tempRes.push_back(nums[left]);
		dfs(left+1, right, nums, tempRes, res);
		tempRes.pop_back();
		//不选择nums[left]
		dfs(left+1, right, nums, tempRes, res);
	}
};

