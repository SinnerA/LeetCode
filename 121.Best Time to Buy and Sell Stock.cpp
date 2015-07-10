/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Tags: Array Dynamic Programming
*/

/*
�㷨1����̬�滮��dp[i]��ʾ[0...i)֮���������
dp[i+1] = max(dp[i], prices[i+1] - minPrice); minPrice��ʾ[0...i)֮����ͼ۸�
������� = dp[n-1]
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
�㷨2�����չ�Ʊ��۹��������� prices[1]-prices[0], prices[2]-prices[1], prices[3]-prices[2], ..., prices[n-1]-prices[n-2]��
�������������Ӷκ;����������������󣬼�������Ӷκ��Ǵ�������� i ���� j �
��ô�Ӷκ�= prices[j]-prices[j-1]+prices[j-1]-prices[j-2]+...+prices[i]-prices[i-1] = prices[j]-prices[i-1], 
��prices[j]�����۸�prices[i-1]����С�۸�����������ǰ��˳���ϵ��
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