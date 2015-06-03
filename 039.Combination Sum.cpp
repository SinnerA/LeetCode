/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, �� , ak) must be in non-descending order. (ie, a1 �� a2 �� �� �� ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

Tags: Array Backtracking
*/

//�ݹ�
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > res;
		if(candidates.size() == 0) return res;
		sort(candidates.begin(), candidates.end());//Ϊ������������������ȶ���������
		vector<int> tempRes;
		dfs(candidates, res, tempRes, target, 0);
		return res;
    }
	//������candidates[index,...]Ѱ�Һ�Ϊtarget�����
	void dfs(vector<int>& candidates, vector<vector<int> > &res, vector<int> &tempRes, int target, int index){
		if(target == 0){
			res.push_back(tempRes);
			return;
		}
		for(int i = index; i < candidates.size() && candidates[i] <= target; i++){ //����ѡ���һ�����֣�ѡ���Ӵ����ֿ�ʼѰ����һ������
			if(i == 0 || candidates[i] != candidates[i-1]){ //����ÿ��������ѡȡ��Σ�����������ظ������Ͳ��ÿ���
				tempRes.push_back(candidates[i]);
				dfs(candidates, res, tempRes, target - candidates[i], i);
				tempRes.pop_back();
			}
		}
	}
};