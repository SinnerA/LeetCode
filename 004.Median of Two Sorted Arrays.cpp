/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Tags: Divide and Conquer Array Binary Search
*/

/*
算法1：
核心是将原问题转变成一个寻找第k小数的问题（假设两个原序列升序排列），这样中位数实际上是第(m+n)/2小的数。所以只要解决了第k小数的问题，原问题也得以解决。

首先假设数组A和B的元素个数都大于k/2，我们比较A[k/2-1]和B[k/2-1]两个元素，这两个元素分别表示A的第k/2小的元素和B的第k/2小的元素。
这两个元素比较共有三种情况：>、<和=。如果A[k/2-1]<B[k/2-1]，这表示A[0]到A[k/2-1]的元素都在A和B合并之后的前k小的元素中。
换句话说，A[k/2-1]不可能大于两数组合并之后的第k小值，所以我们可以将其抛弃。

证明也很简单，可以采用反证法。假设A[k/2-1]大于合并之后的第k小值，我们不妨假定其为第（k+1）小值。
由于A[k/2-1]小于B[k/2-1]，所以B[k/2-1]至少是第（k+2）小值。
但实际上，在A中至多存在k/2-1个元素小于A[k/2-1]，B中也至多存在k/2-1个元素小于A[k/2-1]，所以小于A[k/2-1]的元素个数至多有k/2+ k/2-2，小于k，这与A[k/2-1]是第（k+1）的数矛盾。

当A[k/2-1]>B[k/2-1]时存在类似的结论。

算法中每次迭代平均k都会减小k/2,因此算法复杂度为O（logk），而k =（n1+n2）/m, m是一个常数（在本题中，m=2），即复杂度为O（log(n1+n2)）
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if((m+n)%2)
			return findKthSmallest(nums1, m, nums2, n, (m+n)/2 + 1);
		else
			return (findKthSmallest(nums1, m, nums2, n, (m+n)/2) + findKthSmallest(nums1, m, nums2, n, (m+n)/2 + 1)) / 2.0;
    }
	int findKthSmallest(vector<int>& vec1, int n1, vector<int>& vec2, int n2, int k){
		//总是假设n1 <= n2
		if(n1 > n2)
			return findKthSmallest(vec2, n2, vec1, n1, k);
		if(n1 == 0)
			return vec2[k-1];
		if(k == 1)
			return min(vec1[0], vec2[0]);
		
		int idx1 = min(k/2, n1);
		int idx2 = k - idx1;
		if(vec1[idx1-1] == vec2[idx2-1]) return vec1[idx1-1];
		if(vec1[idx1-1] < vec2[idx2-1]){
			vector<int> newVec1(vec1.begin() + idx1, vec1.end());
			return findKthSmallest(newVec1, n1-idx1, vec2, n2, k-idx1);
		} else {
			vector<int> newVec2(vec2.begin() + idx2, vec2.end());
			return findKthSmallest(vec1, n1, newVec2, n2-idx2, k-idx2);
		} 	
	}
};

/*
算法2：跟算法1思路一样，但是findKthSmallest有所不同，idx1，idx2各自取vec1，vec2的中间元素
*/
//找到两个有序数组中第k小的数,k>=1
int findKthSmallest(vector<int>& vec1, int n1, vector<int>& vec2, int n2, int k){
	if(n1 == 0) return vec2[k-1];
	if(n2 == 0) return vec1[k-1];
	if(k == 1) return (vec1[0] < vec2[0]) ? vec1[0] : vec2[0];
	
	int idx1 = n1/(n1+n2)*k;
	int idx2 = k - idx1;
	if(vec1[idx1-1] == vec2[idx2]) return vec1[idx1-1];
	if(vec1[idx1-1] < vec2[idx2-1]){
		vector<int> newVec1(vec1.begin() + idx1, vec1.end());
		return findKthSmallest(newVec1, n1-idx1, vec2, idx2+1, k-idx1);
	} else {
		vector<int> newVec2(vec2.begin() + idx2, vec2.end());
		return findKthSmallest(vec1, idx1+1, newVec2, n2-idx2, k-idx2);
	}
}

/*
算法3：基本思路是从两个数组中依次移除最小最大的一对数，重复操作直到两个数组共剩下1个或者2个数，即为中位数。时间复杂度O(n1+n2)
*/

