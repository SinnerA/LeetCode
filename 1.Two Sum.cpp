/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

注意：元素可能重复
最简单：做两次循环，O(n^2)
*/

/*
方法一：
将数组映射到hash表，key是元素值，value是该值在数组中的索引。由于元素可能有重复，使用unordered_multimap。
映射以后，对于数组中的某个元素num1，只需要找到num2 = target-num1。但是找到num2，并不一定找到所需要的两个数，
因为有可能num2 = num，此时需要保证哈希表中num2的个数>=2。
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
方法二：
对数组进行从小到大排序，然后用指针head,tail分别指向首尾元素：
1：如果head元素 + tail元素 = target，找到了！
2：如果head元素 + tail元素 < target，head++
3：如果head元素 + tail元素 < target，tail--
4：如果head == tail，结束

注意：由于要找索引，所以原数组的顺序不能改变，只是把元素的索引放在新的数组中，对这个新的索引数组排序
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





























