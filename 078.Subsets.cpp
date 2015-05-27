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
�㷨1���ݹ顣ÿһ��Ԫ��������״̬��ѡ�񣬲�ѡ��
�󼯺ϵ������Ӽ����⡣��ĿҪ���Ӽ���Ԫ�طǵݼ������У����������Ҫ��ԭ���ļ��Ͻ�������
ԭ������ÿһ��Ԫ�����Ӽ���������״̬��Ҫô���ڡ�Ҫô�����ڡ�
���������Ӽ��Ĺ�����ÿ��Ԫ�ؾ�������ѡ�񷽷���ѡ�񡢲�ѡ����˿��Թ���һ�Ŷ�������������������и��ļ���[1,2,3]��
����Ķ����������õ���Ҷ�ӽڵ�����Ӽ������ǿ�����dfs���õ���������Ҷ�ӽڵ�
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
	//��[left,right]��Χ��Ѱ��Ԫ�ؼ���subset��
	void dfs(int left, int right, vector<int> &nums, vector<int> &tempRes, vector<vector<int> > &res){
		if(left == right){
			res.push_back(tempRes);
			return;
		}
		//ѡ��nums[left]
		tempRes.push_back(nums[left]);
		dfs(left+1, right, nums, tempRes, res);
		tempRes.pop_back();
		//��ѡ��nums[left]
		dfs(left+1, right, nums, tempRes, res);
	}
};

