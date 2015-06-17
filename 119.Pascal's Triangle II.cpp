/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Tags: Array
*/

/*
指定层由上一层生成，而上一层由上上层生成...因此可在同一数组内，依次生成每层数据
比如：rowIndex = 4
1 0 0 0 0
1 1 0 0 0
1 2 1 0 0
1 3 3 1 0
1 4 6 4 1
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