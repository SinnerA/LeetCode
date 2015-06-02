/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Tags: Array Binary Search
*/

/*
���ö��ֲ��ң����������������ת�ģ���������ͨ�Ķ��ֲ���������ͬ��
��target��Ӧ����midǰ��β��ң�����targetʵ����mid���Σ���Ϊ������ת������Ӧ�õõ�ʲô�����£������������������
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
		while(start <= end){
			mid = start + (end - start) / 2; //��ֹ���
			if(nums[mid] > target){
				if(nums[start] > nums[end] && target <= nums[end] && nums[mid] > nums[end])
					start = mid + 1;
				else
					end = mid - 1;
			} else if(nums[mid] < target){
				if(nums[start] > nums[end] && target >= nums[start] && nums[mid] < nums[end])
					end = mid - 1;
				else
					start = mid + 1;
			} else
				return mid;
		}
		return -1;
    }
};