/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

Tags: Backtracking
*/

/*
算法1：如“Permutations”题中算法1，运用递归，注意存在重复元素。
在算法1的基础上，当我们枚举第i个位置的元素时，若要把后面第j个元素和i交换，则先要保证[i…j-1]范围内没有和位置j相同的元素。
有以下两种做法（1）可以每次在需要交换时进行顺序查找；（2）用哈希表来查重。
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
			if(!find(nums, index, i, nums[i])){
				swap(nums[index], nums[i]);
				tempRes.push_back(nums[index]);
				generate(nums, res, tempRes, index + 1);
				tempRes.pop_back();
				swap(nums[index], nums[i]);
			}
		}
	}
	//数组中指定区间[begin, end)寻找元素target
	bool find(vector<int>& nums, int begin, int end, int target){
		for(int i = begin; i < end; i++)
			if(nums[i] == target)
				return true;
		return false;
	}
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
		unordered_set<int> mySet;
		for(int i = index; i < nums.size(); i++){
			if(mySet.find(nums[i]) == mySet.end()){
				mySet.insert(nums[i]);
				swap(nums[index], nums[i]);
				tempRes.push_back(nums[index]);
				generate(nums, res, tempRes, index + 1);
				tempRes.pop_back();
				swap(nums[index], nums[i]);
			}
		}
	}
};