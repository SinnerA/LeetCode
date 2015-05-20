/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Tags: Dynamic Programming
*/

/*쳲������������⣺dp[i] = dp[i-2] + dp[i-1]*/
class Solution {
public:
    int climbStairs(int n) {
        int stepOne = 0, stepTwo = 1, stepN;
		for(int i = 1; i <= n; i++){
			stepN = stepOne + stepTwo;
			stepOne = stepTwo;
			stepTwo = stepN;
		}
		return stepN;
    }
};

/*
�����֮��2.9-쳲��������С� ���ᵽ��һ��logn���㷨��ʵ�����������������logn�㷨����
��n�Ƚϴ�ʱ�����Ч�ܶࡣ���ȸ���������룬Ȼ��ֱ�ӽ�ͼ���ϵ����������n�ϴ󣬾���Ҫ��д����������
*/