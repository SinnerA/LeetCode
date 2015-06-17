/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Tags: Array
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
		if(numRows == 0) return res;
		vector<int> tempRes;
		tempRes.push_back(1);
		res.push_back(tempRes);
		if(numRows == 1) return res;
		for(int i = 1; i < numRows; i++){
			tempRes.clear();
			tempRes.push_back(1);
			for(int j = 1; j < i; j++)
				tempRes.push_back(res[i-1][j-1] + res[i-1][j]);
			tempRes.push_back(1);
			res.push_back(tempRes);
		}
		return res;
    }
};

/*更加精简*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res(numRows);
		for(int i = 0; i < numRows; i++){
			res[i].resize(i + 1);
			res[i][0] = res[i][i] = 1;
			for(int j = 1; j < i; j++)
				res[i][j] = res[i-1][j-1] + res[i-1][j];
		}
		return res;
    }
};