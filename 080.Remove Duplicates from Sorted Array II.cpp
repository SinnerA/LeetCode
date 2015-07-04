/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Tags: Array Two Pointers
*/

/*����cnt���ڼ�������counter��2ʱ����ֱ���������ɣ�����˵��Ԫ�س��ִ���û�г����������������飬��������Ԫ��������counter��*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if(n == 0) return 0;
		int idx = 0, cnt = 0;
		for(int i = 0; i < n; i++){
			if(i > 0 && nums[i] == nums[i-1]){
				cnt++;
				if(cnt > 2)
					continue;
			} else {
				cnt = 1;
			}
			nums[idx++] = nums[i];
		}
		return idx;
    }
};


/*
��������Ҫ����ĳ��Ԫ��ʱ������ʱ����ã��ȵ���һ���ٸ��ǣ�����������ǰһ����ǰһ��Ԫ��A[i-2]ʱ���Ͳ������A[i-2]ԭ����ֵ�����ǵ��������û�и㶮�壩
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if(n == 0 || n == 1) return n;
		int cnt = 1, temp = nums[1];
		for(int i = 2; i < n; i++){
			if(nums[i] != nums[i-2]){
				nums[cnt++] = temp;
				temp = nums[i];
			}
		}
		nums[cnt++] = temp;
		return cnt;
    }
};