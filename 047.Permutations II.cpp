/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

Tags: Backtracking
*/

/*
�㷨1���硰Permutations�������㷨1�����õݹ飬ע������ظ�Ԫ�ء�
���㷨1�Ļ����ϣ�������ö�ٵ�i��λ�õ�Ԫ��ʱ����Ҫ�Ѻ����j��Ԫ�غ�i����������Ҫ��֤[i��j-1]��Χ��û�к�λ��j��ͬ��Ԫ�ء�
����������������1������ÿ������Ҫ����ʱ����˳����ң���2���ù�ϣ�������ء�
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
	//������ָ������[begin, end)Ѱ��Ԫ��target
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