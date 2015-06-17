/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Tags: Array
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
		res[0] = 1;
		for(int i = 1; i <= rowIndex; i++)
			for(int j = i; j >= 1; j--)
				res[j] += res[j-1];
		return res;
    }
};