/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order.  (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

Tags: Array Backtracking
*/

/*
注意：事先要对candidates排序。
由于有重复元素的存在，比如数组为[1(1),1(2),2,3]，target = 6. 可能出现重复结果1(1),2,3 和 1(2),2,3
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
		if(candidates.size() == 0) return res;
		sort(candidates.begin(), candidates.end());
		vector<int> tempRes;
		dfs(candidates, res, tempRes, target, 0);
		return res;
    }
	//从数组candidates[index,...]寻找和为target的组合
	void dfs(vector<int> &candidates, vector<vector<int> > &res, vector<int> &tempRes, int target, int index){
		if(target == 0){
			res.push_back(tempRes);
			return;
		}
		for(int i = index; i < candidates.size() && candidates[i] <= target; i++){
			if(i > index && candidates[i] == candidates[i-1]) continue;//当前子问题中，重复数字都不选择
			tempRes.push_back(candidates[i]);
			dfs(candidates, res, tempRes, target - candidates[i], i + 1);
			tempRes.pop_back();
		}
	}
};