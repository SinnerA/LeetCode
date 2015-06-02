/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Tags: Array Binary Search
*/

/*
�뵽STL�е�equal_range��������������ǵ���lower_bound��upper_bound, �������Ƿ���STL��ʵ�֡�
lower_bound��A[middle] == targetʱ����������벿�ֲ��ң������ص��ǵ�һ����С��Ŀ������Ԫ��λ�ã�
upper_bound��A[middle] == targetʱ���������Ұ벿�ֲ��ң������ص��ǵ�һ������Ŀ������Ԫ��λ�á�
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
		vector<int> res(2, -1);
		while(left <= right){
			mid = left + (right - left)/2;//��ֹ���
			if(nums[mid] < target){
				left = mid + 1;
			} else if(nums[mid] > target) {
				right = mid - 1;
			} else {
				res[0] = lowerBound(nums, left, mid - 1, target);
				res[1] = upperBound(nums, mid + 1, right, target) - 1;
				return res;
			}
		}
		return res;
    }
	//�ҵ���Χ��[left,right]�ڵ�һ����С��target��Ԫ��
	int lowerBound(vector<int>& nums, int left, int right, int target){
		while(left <= right){
			int mid = left + (right-left)/2;
			if(nums[mid] < target){
				left = mid + 1;
			} else {
				right = mid - 1;//��������target������right��Ȼ��ǰ�ƶ���ֱ�����rightָ���һ��С��target������
			}
		}
		return right + 1;
	}
	//�ҵ���Χ��[left,right]�ڵ�һ������target��Ԫ��
	int upperBound(vector<int>& nums, int left, int right, int target){
		while(left <= right){
			int mid = left + (right-left)/2;
			if(nums[mid] <= target){
				left = mid + 1; //��������target������left��Ȼ�����ƶ���ֱ�����leftָ���һ������target������
			} else {
				right = mid - 1;
			}
		}
		return left;
	}
};




