/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

Tags: Array Two Pointers
*/

/*
�������и��߶����飬���൱�ڸ���ĸ߶ȣ��������������������ʢˮ��������������ľ�����ϵ͸���ĸ߶ȳ˻���Ϊʢˮ��������
ֱ�۵Ľ����ǣ��ݻ�����������ܳ��͸ߵ�Ӱ�죬�����ȼ�Сʱ�򣬸߱����������п�������������������Ǵӳ����ʱ��ʼ�ݼ���Ȼ��Ѱ�Ҹ��ߵ��������º򲹡�
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