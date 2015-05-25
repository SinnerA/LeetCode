/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Tags: Array Two Pointers
*/

//�㷨1���������ҵ�����Ŀ�����ֵ�Ԫ�غ�ֻ��Ҫ������β��Ԫ�ظ��ǵ�ǰλ�ã�����β��Ԫ���Ƿ�ΪĿ������
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size() - 1;
		int  i = 0;
		while(i <= k){
			if(nums[i] == val)
				nums[i] = nums[k--];
			else
				i++;
		}
		return k + 1;
    }
};

//�㷨2���Ѳ�����Ŀ�����ֵ�Ԫ�����ηŵ��ײ������������Ŀ�����ֵ�Ԫ�ؽ��٣����ַ���Ч�ʸ���
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] != val)
				nums[k++] = nums[i];
		}
		return k;
    }
};