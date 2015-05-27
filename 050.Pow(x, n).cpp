/*
Implement pow(x, n).

Tags: Math Binary Search

最简单：递归
*/

/*
主要利用x^2n = (x^n)*(x^n),  x^2n+1 = (x^n)*(x^n)*x

注意n是负数，对其取反时，可能会溢出

其实0^0（都是整数）是未定义的，因为0^0 = 0^1 / 0^1 = 0 / 0, 0作为除数是未定义的，可以参考维基百科。
但是库函数pow(0.0,0) = 1，下面我们也这么处理。

如果x是无穷大（即x = numeric_limits<double>::infinity()），如果n>0,返回无穷大，如果n == 0返回1，
如果n<0,返回负无穷-numeric_limits<double>::infinity()。（1/0.0 不会出现运行错误，结果是正无穷）
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return 1.0; 
		if(x == -1) return n%2 ? -1.0 : 1.0;
		if(x == 0) return 0.0;
		
		long long nn = n; //使用long long，为了防止INT_MIN取反时溢出
		if(nn < 0) nn = -nn;
		
		double res = 1.0;
		while(nn != 0){
			if(nn & 1)
				res *= x;//n为奇数
			nn >>= 1;
			x *= x;
		}
		return n > 0 ? res : 1/res;
    }
};