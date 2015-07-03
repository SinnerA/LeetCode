/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Tags: Array Two Pointers
*/

/*
对于本题要求的求最接近解，只需要保存当前解以及当前解和目标的距离，如果新的解更接近，则更新解。算法复杂度为O（n^2）;
注意：我们这里是求的和是一个非确定性的数，因此2sum问题的hashtable解法就不适合这里了
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
		sort(nums.begin(), nums.end());
		int res, dis = INT_MAX;
		
		for(int i = 0; i < n - 2; i++){
			int target2 = target - nums[i];
			int tempDis, tempRes = twoSumClosest(nums, i + 1, target2);
			if((tempDis = abs(target2 - tempRes)) < dis){
				dis = tempDis;
				res = tempRes + nums[i];
				if(res == target)
					return res;
			}
		}
		return res;
    }
	int twoSumClosest(vector<int>& nums, int start, int target){
		int res, dis = INT_MAX;
		int end = nums.size() - 1;
		while(start < end){
			int tmpRes = nums[start] + nums[end];
			if(tmpRes < target){
				if(dis > target - tmpRes){
					dis = target - tmpRes;
					res = tmpRes;
				}
				start++;
			} else if(tmpRes > target){
				if(dis > tmpRes - target){
					dis = tmpRes - target;
					res = tmpRes;
				}
				end--;
			} else {
				return target;
			}
		}
		return res;
	}
};