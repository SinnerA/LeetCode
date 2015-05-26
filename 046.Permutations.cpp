/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Tags: Backtracking
*/

/*
�㷨1��������DFS�ĵݹ�. ���ڰ���n��Ԫ�ص�����,��ȷ����һλ�õ�Ԫ�أ���һ��λ����n�п���(ÿ�ΰѺ����Ԫ�غ͵�һ��Ԫ�ؽ���)��Ȼ����������[2��n]��ȫ���С�
����һ�����е��ܹ���n!�����У����ʱ�临�Ӷ�ΪO��n!��
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
