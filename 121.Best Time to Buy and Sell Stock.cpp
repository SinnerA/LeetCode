/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Tags: Array Dynamic Programming
*/

/*
算法1：动态规划，dp[i]表示[0...i)之间最大利润
dp[i+1] = max(dp[i], prices[i+1] - minPrice); minPrice表示[0...i)之间最低价格
最大利润 = dp[n-1]
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
		int n = prices.size();
		int dp[n];
		memset(dp, 0, sizeof(dp));
		
		int minPrice = prices[0];
		for(int i = 1; i < n; i++){
			minPrice = min(minPrice, prices[i]);
			dp[i] = max(dp[i-1], prices[i] - minPrice);
		}
		return dp[n-1];
    }
};

/*
算法2：按照股票差价构成新数组 prices[1]-prices[0], prices[2]-prices[1], prices[3]-prices[2], ..., prices[n-1]-prices[n-2]。
求新数组的最大子段和就是我们求得最大利润，假设最大子段和是从新数组第 i 到第 j 项，
那么子段和= prices[j]-prices[j-1]+prices[j-1]-prices[j-2]+...+prices[i]-prices[i-1] = prices[j]-prices[i-1], 
即prices[j]是最大价格，prices[i-1]是最小价格，且他们满足前后顺序关系。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
		int res = 0, n = prices.size();
		int maxSum = 0;
		
		for(int i = 1; i < n; i++){
			if(maxSum <= 0)
				maxSum = prices[i] - prices[i-1];
			else
				maxSum += prices[i] - prices[i-1];
			if(res < maxSum)
				res = maxSum;
		}
		return res;
    }
};