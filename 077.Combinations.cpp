/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Tags: Backtracking
*/

//算法1：递归。我们对选取的元素组合加一个约定：选取的k个元素的相对顺序和他们在原始数组中的顺序一致，对于组合问题，这个条件对结果没有影响。
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
		if(k <= 0) return res;
		vector<int> tempRes;
		generate(1, n, k, tempRes, res);
		return res;
    }
	//从[left, right]范围内选取k个数
	void generate(int left, int right, int k, vector<int>& tempRes, vector<vector<int> >& res){
		if(k == 0){
			res.push_back(tempRes);
			return;
		}
		for(int i = left; i <= right-k+1; i++){
			tempRes.push_back(i);
			generate(i+1, right, k-1, tempRes, res);
			tempRes.pop_back();
		}
 	}
};

//算法2：递归。每一个元素有两种状态：选择，不选择
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
		if(k <= 0) return res;
		vector<int> tempRes;
		generate(1, n, k, tempRes, res);
		return res;
    }
	//在[left, right]范围内选取k个数
	void generate(int left, int right, int k, vector<int> &tempRes, vector<vector<int> > &res){
		if(right-left+1 < k) return;
		if(k == 0){
			res.push_back(tempRes);
			return;
		}
		//选择left
		tempRes.push_back(left);
		generate(left+1, right, k-1, tempRes, res);
		tempRes.pop_back();
		//不选择left
		generate(left+1, right, k, tempRes, res);
	}
};

/*
算法3：
*/

/*
算法4：
*/