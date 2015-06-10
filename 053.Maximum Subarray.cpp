/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Tags: Divide and Conquer Array Dynamic Programming
*/

/*
�㷨1��DP��O(n)
��֪��ǰk��Ԫ�ص���������к�ΪmaxSub���Ѿ�����¼�����ˣ����Լ�һ����ʱ��sum��
�������˵�k+1���Ԫ�أ�����������������������ƣ��������k+1���Ԫ��֮ǰ�ĺ���С��0�ģ���ô��������k+1���Ԫ�شӶ�ȥ��������������û�й��׵ģ����Կ��԰�sum ��0��
�ٸ����ӣ�-1��-2��4��-5��7����ٶ�7Ϊ��k+1��Ԫ�أ���ô�����Կ��Կ�����֮ǰ��sum = -5+4 = -1����ô��������7��˵ֻ�������������ֱ����sum = 0��0 + 7���ܵõ���ȷ�Ĵ𰸡�
����չ������飺-1�� -2�� 4�� -5�� 7�� 1 ����1֮ǰ��sum = 7 > 0�����ں����1�����������������й��׵ģ�����sum = 7 + 1 =8��
��ע��һ�㣬ֻҪsum�������������м����С��0��Ԫ����û��ϵ�ģ�sum��Ȼ���Լ����ۼӡ�
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -1;
		int res = INT_MIN;
		for(int i = 0; i< nums.size(); i++){
			if(sum > 0)
				sum += nums[i];
			else
				sum = nums[i];
			if(res < sum) res = sum;
		}
		return res;
    }
};

/*
�㷨2�����η���O(logn)
��������֪����������п��ܴ�����A�������ߣ��ұߣ�����һ�����һ���ұߡ� 
�������Ǻ����׿������뵽����Ȼ�������ǿ��԰�A���黮�ֳ����ɸ�С�������飬
�������������ߵ����ֵ�����ұߵ����ֵ����������м�λ�õ���ߵ�ĳ��λ�õ����ֵ�����м�λ�õ��ұߵ�ĳ��λ�õ����ֵ��
�õ������ĸ�ֵ֮��ʣ�µ����ǾͿ���ͨ���Ƚϵõ��������������ֵ�ˡ����ݹ�Ĺ��̣� 
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
	int helper(vector<int>& nums, int start, int end){
		if(start == end) return nums[end];
		int middle = (start + end) / 2;
		int maxLeft = helper(nums, start, middle);
		int maxRight = helper(nums, middle + 1, end);
		
		int leftNum = nums[middle];
		int temp = leftNum;
		for(int i = middle - 1; i >= start; i--){
			temp += nums[i];
			if(leftNum < temp) leftNum = temp;
		}
		
		int rightNum = nums[middle + 1];
		temp = rightNum;
		for(int i = middle + 2; i <= end; i++){
			temp += nums[i];
			if(rightNum < temp) rightNum = temp;
		}
		return max(max(maxLeft, maxRight), leftNum + rightNum);
	}
};