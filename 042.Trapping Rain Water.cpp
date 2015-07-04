/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Tags: Array Stack Two Pointers
*/

/*
�㷨1���������м��������¼��ǰ�ڶ��ߵ�secHight��Ȼ����������ڶ��ߵ��ȥ��ǰ���������ӣ�ʣ�¾�װˮ�����ˡ�
Ϊʲô�ǵڶ��ߵ㣿��Ϊ���߱Ƚϣ���ߵĵ㲻�ö���ֻ���ƶ��ڶ��ߵ㡣ʱ�临�Ӷ�ΪO(n)��
���ӱ߽翪ʼ��ÿ��ȡ�߽�����İ���Ϊ�������ˮ�������ߵ�ֹͣ����
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
				res += secHeight - height[left]; //���㵱ǰ�����װ��ˮ������
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
�㷨2����������ÿ��A[i]��trapped water��������Ȼ�����е�A[i]��trapped water������Ӽ��ɡ�
����ÿ��A[i]��trapped water��������ȡ����A[i]�������ߵĸ߶ȣ�����չ����Сֵ��A[i]�Ĳ�ֵ����volume[i] = [min(left[i], right[i]) - A[i]]��
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