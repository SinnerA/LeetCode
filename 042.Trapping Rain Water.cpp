/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Tags: Array Stack Two Pointers
*/

/*
算法1：两边往中间遍历，记录当前第二高点secHight，然后利用这个第二高点减去当前历经的柱子，剩下就装水容量了。
为什么是第二高点？因为两边比较，最高的点不用动，只需移动第二高点。时间复杂度为O(n)。
（从边界开始，每次取边界上最矮的板作为往里面灌水，遇到高的停止。）
*/
class Solution {
public:
    int trap(vector<int>& height) {
		int n = height.size();
		if(n == 0) return 0;
		int left = 0, right = n - 1;
		int secHeight = 0, res = 0;
		while(left < right){
			if(height[left] < height[right]){
				secHeight = max(secHeight, height[left]);
				res += secHeight - height[left]; //计算当前格的能装雨水的容量
				left++;
			} else {
				secHeight = max(secHeight, height[right]);
				res += secHeight - height[right];
				right--;
			}
		}
		return res;
    }
};

/*
算法2：挨个分析每个A[i]能trapped water的容量，然后将所有的A[i]的trapped water容量相加即可。
对于每个A[i]能trapped water的容量，取决于A[i]左右两边的高度（可延展）较小值与A[i]的差值，即volume[i] = [min(left[i], right[i]) - A[i]]。
*/
class Solution {
public:
    int trap(vector<int>& height) {
		int n = height.size();
		if(n == 0) return 0;
		int res = 0, leftMax = 0, rightMax = 0;
		int left[n], right[n];
		
		for(int i = 0; i < n; i++){
			if(height[i] > leftMax){
				leftMax = height[i];
			}
			left[i] = leftMax;
		}
		
		for(int i = n-1; i >= 0; i--){
			if(height[i] > rightMax){
				rightMax = height[i];
			}
			right[i] = rightMax;
		}
		
		for(int i = 0; i < n; i++){
			res += min(left[i], right[i]) - height[i];
		}
		return res;
    }
};