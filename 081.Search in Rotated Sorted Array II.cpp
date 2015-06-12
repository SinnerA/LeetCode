/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Tags: Array Binary Search
*/

/*
�㷨1��˼·���⡰033.Search in Rotated Sorted Array��һ��
������������з����ǻ���������û���ظ�Ԫ�صģ���������ظ�Ԫ�أ������������ͬ��
��������a��������һ������������е�a����������������β��Ԫ�ص����ײ�Ԫ��ʱ��Ҳ�п��ܱ�ʾ�������䲻������ģ�����1 1 1 3 1
��������c�����м�Ԫ�ص���β��Ԫ��ʱ��Ҳ�����������������������target = 3������Ϊ1 1 1 3 1������target = 1������Ϊ3 3 3 1 3
����������������ʱ������м�Ԫ�ص���β��Ԫ�أ����ǲ���ȷ�������ĸ�����������ң�
����target = 3����������Ϊ1 1 1 3 1��1 3 1 1 1������target > �м�Ԫ��ʱ������������������������ֱ�����middle�Ĳ�ͬ������ң���˴�ʱ�������䲻���۰룬ֻ����������ұ߽��1
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int col = nums.size();
		if(col == 0) return false;
		int left = 0, right = col - 1;
		while(left <= right){
			int middle = left + (right - left) / 2;
			if(nums[middle] < target){
				if(nums[left] >= nums[right] && target >= nums[left] && nums[middle] <= nums[left]){
					if(nums[middle] == nums[left])
						left++;
					else
						right = middle - 1;
				} else {
					left = middle + 1;
				}
			} else if(nums[middle] > target){
				if(nums[left] >= nums[right] && target <= nums[right] && nums[middle] >= nums[right]){
					if(nums[middle] == nums[right])
						right--;
					else
						left = middle + 1;
				} else {
					right = middle - 1;
				}
			} else{
				return true;
			}
		}
		return false;
    }
};

/*
�㷨2��ͨ���жϲ��������ײ�Ԫ�غ��м�Ԫ�صĹ�ϵ���жϲ����������һ�����������

û���ظ�Ԫ�ص������£�
����м�Ԫ�ش����ײ�Ԫ�أ���ô��������������벿��������ģ�Ȼ���ٸ���target�Ƿ��������һ�������������������ҵķ���
����м�Ԫ��С���ײ�Ԫ�أ���ô���������а벿��������ģ�Ȼ���ٸ���target�Ƿ��������һ�������������������ҵķ���
����м�Ԫ�ص����ײ�Ԫ�أ���ʱֻ�п����ǲ����������һ��������Ԫ�ص����Σ�����߽��1�������Ҽ��ɣ��൱����߽� = middle + 1����Ϊ��ʱmidlle������߽磩

�����ظ�Ԫ�ص����Σ�
ǰ�������һ�������һ��������м�Ԫ�ص����ײ�Ԫ��ʱ�����������п��ܲ���ֻ����һ��������Ԫ�أ���ʱû���ж���һ��������ֻ�ܽ�����������߽��1����ʵ��������������ͬ��
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int col = nums.size();
		if(col == 0) return false;
		int left = 0, right = col - 1;
		
		while(left <= right){
			int middle = left + (right - left) / 2;
			if(nums[middle] == target) return true;
			if(nums[middle] > nums[left]){          //��벿������
				if(nums[middle] > target && target >= nums[left])
					right = middle - 1;
				else
					left = middle + 1;
			} else if(nums[middle] < nums[left]){  //�Ұ벿������
				if(nums[middle] < target && target <= nums[right])
					left = middle + 1;
				else
					right = middle - 1;
			} else {
				left++;
			}
		}
		return false;
    }
};