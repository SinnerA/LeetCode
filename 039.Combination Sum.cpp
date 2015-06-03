/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

Tags: Array Backtracking
*/

//递归
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > res;
		if(candidates.size() == 0) return res;
		sort(candidates.begin(), candidates.end());//为了输出结果递增，因此先对数组排序
		vector<int> tempRes;
		dfs(candidates, res, tempRes, target, 0);
		return res;
    }
	//从数组candidates[index,...]寻找和为target的组合
	void dfs(vector<int>& candidates, vector<vector<int> > &res, vector<int> &tempRes, int target, int index){
		if(target == 0){
			res.push_back(tempRes);
			return;
		}
		for(int i = index; i < candidates.size() && candidates[i] <= target; i++){ //依次选择第一个数字，选择后从此数字开始寻找下一个数字
			if(i == 0 || candidates[i] != candidates[i-1]){ //由于每个数可以选取多次，因此数组中重复的数就不用考虑
				tempRes.push_back(candidates[i]);
				dfs(candidates, res, tempRes, target - candidates[i], i);
				tempRes.pop_back();
			}
		}
	}
};