/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Tags: Array Greedy
*/

/*�㷨1���ҵ����м۸�ĵ������䣬ÿ���������ԶԵͼ�������߼�����*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
		int n = prices.size(), res = 0;
		int minPrice = 0, maxPrice = 0;
		
		for(int i = 0; i < n; i++){
			minPrice = 0;
			maxPrice = 0;
			//�ݼ�����
			while(i+1 < n && prices[i] > prices[i+1]) i++;
			minPrice = prices[i];
			
			//��������
			while(i+1 < n && prices[i] < prices[i+1]) i++;
			maxPrice = prices[i];
			
			res += maxPrice - minPrice;
		}
		return res;
    }
};

/*
�㷨2��ͬ��һ�⹹����Ʊ������飬�����������в��Ϊ����ֵ������������������ˡ�
��ʵ����㷨1��࣬��Ϊֻ�е��������ڵĲ��������������ͬһ�������������в��֮�� = �������۸� -  ������С�۸�
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