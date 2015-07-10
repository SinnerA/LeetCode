/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Tags: Array Greedy
*/

/*算法1：找到所有价格的递增区间，每个区间内以对低价买入最高价卖出*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
		int n = prices.size(), res = 0;
		int minPrice = 0, maxPrice = 0;
		
		for(int i = 0; i < n; i++){
			minPrice = 0;
			maxPrice = 0;
			//递减区间
			while(i+1 < n && prices[i] > prices[i+1]) i++;
			minPrice = prices[i];
			
			//递增区间
			while(i+1 < n && prices[i] < prices[i+1]) i++;
			maxPrice = prices[i];
			
			res += maxPrice - minPrice;
		}
		return res;
    }
};

/*
算法2：同上一题构建股票差价数组，把数组中所有差价为正的值加起来就是最大利润了。
其实这和算法1差不多，因为只有递增区间内的差价是正数，并且同一递增区间内所有差价之和 = 区间最大价格 -  区间最小价格
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
		int res = 0, n = prices.size();
		
		for(int i = 0; i < n; i++){
			while(i+1 < n && prices[i] < prices[i+1]){
				res += prices[i+1] - prices[i];
				i++;
			}
		}
		return res;
    }
};