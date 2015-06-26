/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

Tags: Array Hash Table Two Pointers
*/

/*
算法1：我们可以仿照3sum的解决方法。这里枚举第一个和第二个数，然后对余下数的求2sum，算法复杂度为O（n^3）,去重方法和3sum类似
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
		if(nums.empty()) return res;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		for(int i = 0; i < len - 3; i++){
			if(i > 0 && nums[i] == nums[i-1]) continue;
			int num1 = nums[i];
			for(int j = i + 1; j < len - 2; j++){
				if(j > i + 1 && nums[j] == nums[j-1]) continue;
				int num2 = nums[j];
				
				int head = j + 1, tail = len - 1;
				int target2 = target - num1 - num2;
				while(head < tail){
					if(nums[head] + nums[tail] < target2){
						head++;
					} else if(nums[head] + nums[tail] > target2){
						tail--;
					} else {
						res.push_back(vector<int>{num1, num2, nums[head], nums[tail]});
						
						int k = head + 1;
						while(k < tail && nums[k] == nums[head]) k++;
						head = k;
						
						k = tail - 1;
						while(k > head && nums[k] == nums[tail]) k--;
						tail = k;
					}
				}
			}
		}
		return res;
    }
};

/*
算法2：运用hash_table
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
		if(nums.empty()) return res;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		
		unordered_map<int, vector<pair<int, int> > > pairs;
		pairs.reserve(n * n);
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				pairs[nums[i] + nums[j]].push_back(make_pair(i, j));
		
		for(int i = 0; i < n - 3; i++){
			if(i > 0 && nums[i] == nums[i-1]) continue;
			int num1 = nums[i];
			for(int j = i + 1; j < n - 2; j++){
				if(j > i + 1 && nums[j] == nums[j-1]) continue;
				int num2 = nums[j];
				int newTarget = target - num1 - num2;
				if(pairs.find(newTarget) != pairs.end()){
				    vector<pair<int, int> > vec = pairs[newTarget];
					for(int k = 0; k < vec.size(); k++){
						if(vec[k].first <= j) continue;
						res.push_back(vector<int>{num1, num2, nums[vec[k].first], nums[vec[k].second]});
						int m = k + 1;
						while(m < vec.size() && nums[vec[m].first] == nums[vec[k].first]) m++;
						k = m;
					}
				}
			}
		}
		return res;
    }
};