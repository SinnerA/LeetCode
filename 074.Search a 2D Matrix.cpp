/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

Tags: Array Binary Search
*/

/*
分两步，
（1）先二分搜索的元素定位到行：当目标小于第一列某个元素时，向前面的行中去搜索；当目标大于第一列某个元素分两种情况 
     a、大于该元素所在行的最后一个元素时，往后面的行中去搜索，b、小于等于该元素所在行的最后一个元素，则可以定位到该元素所在的行。
（2）在定位好的行中二分搜索*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
		if(row == 0) return false;
		int col = matrix[0].size();
		
		int low = 0, high = row - 1;
		while(low < high){
			int middle = (low + high)/2;
			if(target < matrix[middle][0])
				high = middle - 1;
			else
				if(target > matrix[middle][col-1])
					low = middle + 1;	
				else{
					low = middle;
					break;
				}
		}
		
		int targetRow = low;
		int left = 0, right = col-1;
		while(left <= right){
			int mid = (left + right) / 2;
			if(matrix[targetRow][mid] < target)
				left = mid + 1;
			else if(matrix[targetRow][mid] > target)
				right = mid - 1;
			else
				return true;
		}
		return false;
    }
};