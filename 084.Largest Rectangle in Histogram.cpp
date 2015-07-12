/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

Tags: Array Stack
*/

/*算法1：枚举全部（大数据不能过），每次找起点i，终点j，最矮的柱形为高h，则面积为(j - i + 1) * h*/
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.empty()) return 0;
		int n = height.size();
		int maxArea = 0, minHeight = 0;
		
		for(int i = 0; i < n; i++){
			//以i为起点的面积比当前maxArea小，则换一个起点：i+1
			if(height[i] > 0 && maxArea/height[i] >= n - i)
				continue;
			minHeight = height[j];
			for(int j = i; j < n; j++){
				minHeight = min(minHeight, height[j]);
				if(maxArea < minHeight * (j - i + 1))
					maxArea = minHeight * (j - i + 1);
			}
		}
		return maxArea;
    }
};

/*算法2：http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html*/