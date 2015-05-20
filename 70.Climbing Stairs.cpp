/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Tags: Dynamic Programming
*/

/*斐波那契数列问题：dp[i] = dp[i-2] + dp[i-1]*/
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
”编程之美2.9-斐波那契数列“ 中提到了一种logn的算法（实际上利用了幂运算的logn算法），
在n比较大时，会高效很多。首先给出本题代码，然后直接截图书上的描述。如果n较大，就需要编写大整数类了
*/