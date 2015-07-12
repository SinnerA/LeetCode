/*	
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

Tags: Array Backtracking
*/

/*
算法1：dfs解法。
每个元素都有两种选择：选择或不选择。此集合中可能包含重复元素。
因此dfs时，面对当前元素，如果要选择加入vector中，则必须满足条件：当前处理的数字前面出现了k次，那么我们要处理的集合中必须包含k个该元素。
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int> > res;
		sort(nums.begin(), nums.end());
		vector<int> tempRes;
		subsetsWithDupRecur(res, tempRes, nums, 0);
		return res;
    }
	
	void subsetsWithDupRecur(vector<vector<int> >& res, vector<int>& tempRes, vector<int>& nums, int index){
		if(index == nums.size()){
			res.push_back(tempRes);
			return;
		}
		int firstIndex = index - 1, cnt = 0;//nums[firstIndex]是第一个和nums[index]相同的数字，cnt是子集中与nums[index]相同数字的个数
		while(firstIndex >= 0 && nums[index] == nums[firstIndex--]) cnt++;
		firstIndex++;
		if(cnt == 0 || (tempRes.size() - cnt >= 0 && tempRes[tempRes.size() - cnt] == nums[index])){
			//选择nums[index]
			tempRes.push_back(nums[index]);
			subsetsWithDupRecur(res, tempRes, nums, index + 1);
			tempRes.pop_back();
		}
		//不选择nums[index]
		subsetsWithDupRecur(res, tempRes, nums, index + 1);
	}
};