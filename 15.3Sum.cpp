/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a �� b �� c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
Tags: Array Two Pointers
*/

/*
Ϊ�˱����ظ����������������飬��ö�ٵ�һ������ʱ����������ظ��ľ�ֱ���������Ѿ�������ˣ������ظ����㣩
���ҵ�һ�����ϵĶ�Ԫ�飨�ڶ������͵���������ʱ��Ҳ�ֱ�ȥ���ظ�
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > res;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for(int i = 0; i < n-2; ++i){
			if(i > 0 && nums[i] == nums[i - 1]) continue; //�����ظ��������ظ�����
			int target = 0 - nums[i];
			twoSum(nums, i + 1, target, res);
		}
		return res;
    }
	
	void twoSum(vector<int>& nums, int start, int target, vector<vector<int> >& res){
		int head = start, tail = nums.size() - 1;
		while(head < tail){
			if(nums[head] + nums[tail] < target){
				++head;
			} else if(nums[head] + nums[tail] > target){
				--tail;
			} else {
				res.push_back(vector<int>{nums[start - 1], nums[head], nums[tail]});
				
				//Ϊ�˷�ֹ�����ظ��Ķ�Ԫ�飬ʹ�������target
				int k = head + 1;
				while(k < tail && nums[k] == nums[head]) ++k;
				head = k;
				
				k = tail - 1;
				while(k > head && nums[k] == nums[tail]) --k;
				tail = k;
			}
		}
	}
};