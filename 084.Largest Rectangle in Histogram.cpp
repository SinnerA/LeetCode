/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

Tags: Array Stack
*/

/*�㷨1��ö��ȫ���������ݲ��ܹ�����ÿ�������i���յ�j���������Ϊ��h�������Ϊ(j - i + 1) * h*/
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.empty()) return 0;
		int n = height.size();
		int maxArea = 0, minHeight = 0;
		
		for(int i = 0; i < n; i++){
			//��iΪ��������ȵ�ǰmaxAreaС����һ����㣺i+1
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

/*�㷨2��http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html*/