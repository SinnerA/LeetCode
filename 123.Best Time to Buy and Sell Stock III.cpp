/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Tags: Array Dynamic Programming
*/

/*
��һ��Լ�����ֻ���������ι�Ʊ�������������Ҳֻ�ܳ���һ֧��Ʊ��
��Ϊ���������������ι�Ʊ�������������ο϶��ֲ���ǰ��������ͬ�����䡣
��p(i) = ����[0,1,2...i]��������� + ����[i,i+1,....n-1]���������ʽ�������������ڷֱ�ֻ����һ������������ǵ�һ��������⣩��
��ô������������ = max{p[0],p[1],p[2],...,p[n-1]}�����ݵ�һ����㷨2�����ǿ���������[0,1,2...i]���������
ͬ����ԴӺ���ǰɨ������������[i,i+1,....n-1]�����������ݹ�ʽ���£�
dp[i-1] = max{dp[i], maxprices - prices[i-1]}  ,maxprices������[i,i+1,...,n-1]�ڵ���߼۸�
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
		int n = prices.size(), res = 0;
		int maxProfitHead[n];
		memset(maxProfitHead, 0, sizeof(maxProfitHead));
		
		int maxTmpProfit = 0;
		int minPrice = prices[0];
		for(int i = 1; i < n; i++){
			minPrice = min(minPrice, prices[i]);
			if(maxTmpProfit < prices[i] - minPrice)
				maxTmpProfit = prices[i] - minPrice;
			maxProfitHead[i] = maxTmpProfit;
		}
		
		int maxProfitTail = 0;
		int maxPrice = prices[n-1];
		res = maxProfitHead[n-1];
		for(int i = n-2; i >= 0; i--){
			maxPrice = max(maxPrice, prices[i+1]);
			if(maxProfitTail < maxPrice - prices[i+1])
				maxProfitTail = maxPrice - prices[i+1];
			if(res < maxProfitTail + maxProfitHead[i])
				res = maxProfitTail + maxProfitHead[i];
		}
		return res;
    }
};