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
算法2：运用hash_map，时间复杂度O（n^2）
和前面一样，都是先对数组排序。
我们先枚举出所有二个数的和存放在哈希map中，其中map的key对应的是二个数的和，因为多对元素求和可能是相同的值，
故哈希map的value是一个链表（下面的代码中用数组代替），链表每个节点存的是这两个数在数组的下标；这个预处理的时间复杂度是O（n^2）。
接着和算法1类似，枚举第一个和第二个元素，假设分别为v1,v2, 然后在哈希map中查找和为target-v1-v2的所有二元对（在对应的链表中），查找的时间为O（1），
为了保证不重复计算，我们只保留两个数下标都大于V2的二元对（其实我们在前面3sum问题中所求得的三个数在排序后的数组中下标都是递增的），
即时是这样也有可能重复，因此还要判断新加入的二元对和上一个加入的二元对是否重复即可（因为之前排序过，所以重复二元对必然相邻）
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
		if(nums.empty()) return res;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		
		unordered_map<int, vector<pair<int, int> > > pairs;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				pairs[nums[i] + nums[j]].push_back(make_pair(i, j));
			
		for(int i = 0; i < n - 3; i++){
			if(i > 0 && nums[i] == nums[i-1]) continue;           //防止第一个元素重复
			int num1 = nums[i];
			for(int j = i + 1; j < n - 2; j++){
				if(j > i + 1 && nums[j] == nums[j-1]) continue;   //防止第二个元素重复 
				int num2 = nums[j];
				int newTarget = target - num1 - num2;
				if(pairs.find(newTarget) != pairs.end()){
					vector<pair<int, int> > vec = pairs[newTarget];
					bool isFirstPush = true;
					for(int k = 0; k < vec.size(); k++){
						if(vec[k].first <= j) continue;           //保证所求的四元组的数组下标是递增的
						if(isFirstPush || (res.back())[2] != nums[vec[k].first]){
							res.push_back(vector<int>{num1, num2, nums[vec[k].first], nums[vec[k].second]});
							isFirstPush = false;
						}
					}
				}
			}
		}
		return res;
    }
};