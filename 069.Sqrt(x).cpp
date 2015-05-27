/*Implement int sqrt(int x).

Compute and return the square root of x.

Tags: Math Binary Search
*/

/*
算法1：二分法，两种可能的结果：
1:直接找到能够麻烦要求的数；
2:找到相邻的两个数，可以比较两个数哪一个离target更近，不过题目当中希望找的是更小的那个数。
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
		int left = 1, right = x;
		while(left <= right){
			int mid = left + ((right - left) >> 1);
			if(mid == x/mid)
				return mid;
			else if(mid < x/mid)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return right;//此时right < left，right值更小
    }
};

/*算法2:牛顿法*/
