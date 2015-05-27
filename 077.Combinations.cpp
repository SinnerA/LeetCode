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

//�㷨1���ݹ顣���Ƕ�ѡȡ��Ԫ����ϼ�һ��Լ����ѡȡ��k��Ԫ�ص����˳���������ԭʼ�����е�˳��һ�£�����������⣬��������Խ��û��Ӱ�졣
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
		if(k <= 0) return res;
		vector<int> tempRes;
		generate(1, n, k, tempRes, res);
		return res;
    }
	//��[left, right]��Χ��ѡȡk����
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

//�㷨2���ݹ顣ÿһ��Ԫ��������״̬��ѡ�񣬲�ѡ��
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
		if(k <= 0) return res;
		vector<int> tempRes;
		generate(1, n, k, tempRes, res);
		return res;
    }
	//��[left, right]��Χ��ѡȡk����
	void generate(int left, int right, int k, vector<int> &tempRes, vector<vector<int> > &res){
		if(right-left+1 < k) return;
		if(k == 0){
			res.push_back(tempRes);
			return;
		}
		//ѡ��left
		tempRes.push_back(left);
		generate(left+1, right, k-1, tempRes, res);
		tempRes.pop_back();
		//��ѡ��left
		generate(left+1, right, k, tempRes, res);
	}
};

/*
�㷨3��
*/

/*
�㷨4��
*/