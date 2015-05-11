/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

ע�⣺Ԫ�ؿ����ظ�
��򵥣�������ѭ����O(n^2)
*/

/*
����һ��
������ӳ�䵽hash��key��Ԫ��ֵ��value�Ǹ�ֵ�������е�����������Ԫ�ؿ������ظ���ʹ��unordered_multimap��
ӳ���Ժ󣬶��������е�ĳ��Ԫ��num1��ֻ��Ҫ�ҵ�num2 = target-num1�������ҵ�num2������һ���ҵ�����Ҫ����������
��Ϊ�п���num2 = num����ʱ��Ҫ��֤��ϣ����num2�ĸ���>=2��
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
		unordered_multimap<int, int> umap;
		bool isOk = false;
		for(int i = 0; i < nums.size(); ++i){
			umap.insert(make_pair(nums[i], i));
		}
		
		for(int i = 0; i < nums.size(); ++i){
			auto range = umap.equal_range(target - nums[i]);
			if(range.first != umap.end()){ //found
				auto range2 = umap.equal_range(nums[i]);
				if(target - nums[i] != nums[i]){
					res.push_back(min(range.first->second, range2.first->second) + 1);
					res.push_back(max(range.first->second, range2.first->second) + 1);
					isOk = true;
				} else {
					auto ite = ++(range.first);
					if(ite != range.second){//>=2
						res.push_back(min(ite->second, range2.first->second) + 1);
						res.push_back(max(ite->second, range2.first->second) + 1);
						isOk = true;
					}
				}
			}
			if(isOk)
				return res;
		}
    }
};

/*
��������
��������д�С��������Ȼ����ָ��head,tail�ֱ�ָ����βԪ�أ�
1�����headԪ�� + tailԪ�� = target���ҵ��ˣ�
2�����headԪ�� + tailԪ�� < target��head++
3�����headԪ�� + tailԪ�� < target��tail--
4�����head == tail������

ע�⣺����Ҫ������������ԭ�����˳���ܸı䣬ֻ�ǰ�Ԫ�ص����������µ������У�������µ�������������
*/
class Solution {
private:
	static vector<int> *numbersCopy;
	static bool cmp(int idx1, int idx2){
		return (*numbersCopy)[idx1] < (*numbersCopy)[idx2];
	}
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		numbersCopy = &nums;
		int n = nums.size();
		vector<int> idx(n);
		for(int i = 0; i < n; ++i){
			idx[i] = i;
		}
		sort(idx.begin(), idx.end(), cmp);
		
		int head = 0, tail = n - 1;
		while(head < tail){
			if(nums[idx[head]] + nums[idx[tail]] < target){
				++head;
			} else if(nums[idx[head]] + nums[idx[tail]] > target){
				--tail;
			} else { //found
				res.push_back(min(idx[head], idx[tail]) + 1);
				res.push_back(max(idx[head], idx[tail]) + 1);
				break;
			}
		}
		return res;
	}
};
vector<int> *Solution::numbersCopy = NULL;





























