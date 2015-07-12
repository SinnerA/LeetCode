/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Tags: Array Dynamic Programming
*/

/*
这一题约束最多只能买卖两次股票，并且手上最多也只能持有一支股票。
因为不能连续买入两次股票，所以买卖两次肯定分布在前后两个不同的区间。
设p(i) = 区间[0,1,2...i]的最大利润 + 区间[i,i+1,....n-1]的最大利润（式子中两个区间内分别只能有一次买卖，这就是第一道题的问题），
那么本题的最大利润 = max{p[0],p[1],p[2],...,p[n-1]}。根据第一题的算法2，我们可以求区间[0,1,2...i]的最大利润；
同理可以从后往前扫描数组求区间[i,i+1,....n-1]的最大利润，其递归式如下：
dp[i-1] = max{dp[i], maxprices - prices[i-1]}  ,maxprices是区间[i,i+1,...,n-1]内的最高价格。
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