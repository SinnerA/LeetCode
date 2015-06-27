/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a �� b �� c �� d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

Tags: Array Hash Table Two Pointers
*/

/*
�㷨1�����ǿ��Է���3sum�Ľ������������ö�ٵ�һ���͵ڶ�������Ȼ�������������2sum���㷨���Ӷ�ΪO��n^3��,ȥ�ط�����3sum����
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
�㷨2������hash_map��ʱ�临�Ӷ�O��n^2��
��ǰ��һ���������ȶ���������
������ö�ٳ����ж������ĺʹ���ڹ�ϣmap�У�����map��key��Ӧ���Ƕ������ĺͣ���Ϊ���Ԫ����Ϳ�������ͬ��ֵ��
�ʹ�ϣmap��value��һ����������Ĵ�������������棩������ÿ���ڵ���������������������±ꣻ���Ԥ�����ʱ�临�Ӷ���O��n^2����
���ź��㷨1���ƣ�ö�ٵ�һ���͵ڶ���Ԫ�أ�����ֱ�Ϊv1,v2, Ȼ���ڹ�ϣmap�в��Һ�Ϊtarget-v1-v2�����ж�Ԫ�ԣ��ڶ�Ӧ�������У������ҵ�ʱ��ΪO��1����
Ϊ�˱�֤���ظ����㣬����ֻ�����������±궼����V2�Ķ�Ԫ�ԣ���ʵ������ǰ��3sum����������õ����������������������±궼�ǵ����ģ���
��ʱ������Ҳ�п����ظ�����˻�Ҫ�ж��¼���Ķ�Ԫ�Ժ���һ������Ķ�Ԫ���Ƿ��ظ����ɣ���Ϊ֮ǰ������������ظ���Ԫ�Ա�Ȼ���ڣ�
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
			if(i > 0 && nums[i] == nums[i-1]) continue;           //��ֹ��һ��Ԫ���ظ�
			int num1 = nums[i];
			for(int j = i + 1; j < n - 2; j++){
				if(j > i + 1 && nums[j] == nums[j-1]) continue;   //��ֹ�ڶ���Ԫ���ظ� 
				int num2 = nums[j];
				int newTarget = target - num1 - num2;
				if(pairs.find(newTarget) != pairs.end()){
					vector<pair<int, int> > vec = pairs[newTarget];
					bool isFirstPush = true;
					for(int k = 0; k < vec.size(); k++){
						if(vec[k].first <= j) continue;           //��֤�������Ԫ��������±��ǵ�����
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