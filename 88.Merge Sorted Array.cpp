/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

Tags: Array Two Pointers
*/

/*
分别从尾部开始遍历，将较大者放入num1尾部
时间复杂度O(m+n)，空间复杂度O(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, p = m + n - 1;
		//同时从两个数组尾部开始遍历，将较大者放在nums1的尾部
		while(i >= 0 && j >= 0)
			nums1[p--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
		while(j >= 0)
			nums1[p--] = nums2[j--];
    }
};