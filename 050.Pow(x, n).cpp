/*
Implement pow(x, n).

Tags: Math Binary Search

��򵥣��ݹ�
*/

/*
��Ҫ����x^2n = (x^n)*(x^n),  x^2n+1 = (x^n)*(x^n)*x

ע��n�Ǹ���������ȡ��ʱ�����ܻ����

��ʵ0^0��������������δ����ģ���Ϊ0^0 = 0^1 / 0^1 = 0 / 0, 0��Ϊ������δ����ģ����Բο�ά���ٿơ�
���ǿ⺯��pow(0.0,0) = 1����������Ҳ��ô����

���x������󣨼�x = numeric_limits<double>::infinity()�������n>0,������������n == 0����1��
���n<0,���ظ�����-numeric_limits<double>::infinity()����1/0.0 ����������д��󣬽���������
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return 1.0; 
		if(x == -1) return n%2 ? -1.0 : 1.0;
		if(x == 0) return 0.0;
		
		long long nn = n; //ʹ��long long��Ϊ�˷�ֹINT_MINȡ��ʱ���
		if(nn < 0) nn = -nn;
		
		double res = 1.0;
		while(nn != 0){
			if(nn & 1)
				res *= x;//nΪ����
			nn >>= 1;
			x *= x;
		}
		return n > 0 ? res : 1/res;
    }
};