/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

Tags: Array Two Pointers
*/

/*
题意是有个高度数组，就相当于隔板的高度，求数组中任意两隔板间盛水的最大量。隔板间的距离与较低隔板的高度乘积即为盛水的容量。
直观的解释是：容积即面积，它受长和高的影响，当长度减小时候，高必须增长才有可能提升面积，所以我们从长度最长时开始递减，然后寻找更高的线来更新候补。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
		int watar = 0;
		int left = 0, right = height.size() - 1;
		while(left < right){
			int tmpWatar = min(height[left], height[right]) * (right - left);
			if(watar < tmpWatar) watar = tmpWatar;
			
			if(height[left] < height[right]){
				left++;
			} else {
				right--;
			}
		}
		return watar;
    }
};