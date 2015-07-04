/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

Tags: Array Two Pointers Sort
*/

/*
��Ŀ˵��һ��ѣ������ö�һ���������������е�Ԫ��ֻ��0��1��2������Ҫ��ֻ�ܱ���һ�����飬�����ռ临�Ӷȡ�
�����ڿ��������partition˼�룬��1Ϊ��ŦԪ��������л��֣�ʹ0���������ߣ�2��������ұߣ�1��������м䡣
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
		//zeroEnd�Ƿ�0�ǲ��ֵ�β��������twoBegin�Ƿ�2�ǲ��ֵ��ײ�����
        //����0�ŵ�zeroEnd+1��������2�ŵ�twoEnd-1��������1ָ�����
        if(nums.empty()) return;
		int zeroEnd = -1, twoBegin = nums.size(), i = 0;
		while(i < twoBegin){
			if(nums[i] == 0 && i != ++zeroEnd){
				swap(nums[i], nums[zeroEnd]);
			} else if(nums[i] == 2 && i != --twoBegin){
				swap(nums[i], nums[twoBegin]);
			} else {
				i++;
			}
		}
    }
};