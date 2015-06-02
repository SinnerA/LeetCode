/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

Tags: Math Binary Search
*/

/*
��ֱ�ۣ���������ȥ������֪��������Ϊ0�����ǻᳬʱ����dividend = -2147483648��divisor = -1
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        int count = 0;
		bool isPositive = true;
		if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
			isPositive = false;
		if(dividend < 0) dividend *= -1;
		if(divisor < 0) divisor *= -1;
		while(true){
			dividend = dividend - divisor;
			if(dividend > 0) count++;
			else break;
		}
		if(dividend == 0) count++;
		return isPositive ? count : count*(-1);
    }
};

/*
�㷨1����������ķ�����ÿ�μ�һ�������ٶ�̫����������Ŀ����ʹ�ó˷�����˲��ܼ�ȥk*������
���ǿ��ԶԳ�����������λ����������ÿ���൱�ڼ�ȥ2^k�����������ȷ��k�أ�ֻҪʹ(2^k)*���� <= ��ǰ������ < (2^(k+1))*������
*/

/*
ע�⣺������ڲ������ݵĴ洢����һ�µģ��������Լ�����ĸ�����ǹ涨�ı�ʾ��ʽ��ͬ���ѡ�int��������λ����unsigned int���Է���λ��
unsigned int��Χ��0 ~ 4294967295 (4 Bytes).ʹ��long longʱ��Ҫע���﷽ʽ����1д��1ll����ʱ����ʱ��int�Զ�ת����long long��
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
		long long res = 0;
		long long divd = dividend, divs = divisor;
		if(dividend < 0) divd = divd*(-1);
		if(divisor < 0) divs = divs*(-1);
			
		while(divd >= divs){
			long long ldivs = divs;//��ֹ��λ���
			int i = 1;
			for(; ldivs <= divd; i++)
				ldivs <<= 1;
			res += (1ll << (i-2));
			divd -= (divs << (i-2));
		}
		bool isPositive = !(dividend > 0 ^ divisor > 0);
		if(isPositive && res > INT_MAX) return INT_MAX;
		return isPositive ? res : res*(-1);
	}
};

















