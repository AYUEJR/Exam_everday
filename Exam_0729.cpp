#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
//ʵ����쳲����������⣻f(n)=f(n-1)+f(n-2)
/*
f(n) = f(n-1)+f(n-2)+...+f(1)

	  f(n-1) = f(n-2)+ f(n-3)...+f(1)

��ʽ������õ�f(n) = 2*f(n-1)
*/
//1.�ݹ鷨
#if 0
class Solution {
public:
	int jumpFloor(int num) 
	{
		if (num <= 0)
		{
			return 0;
	 }
		else if (num == 1 || num == 2)
		{
			return num;
		}
		else
		{
			//int re =0;
			return jumpFloor(num - 1) + jumpFloor(num - 2);
		}
	}
};

int main()
{
	Solution a;
	a.jumpFloor(9);
	return 0;
}

#endif


/*
С���Ǻ�ϲ�����Լ�װ��������ģ������룩������Ҫ������ܳ������������̣����Ǿͽ���ȥ�ˡ�

���ڸ��������ǵ���������İ뾶�����ж�һ���ܷ�����ȥ��
�����ж������ݡ�

ÿ�����ݰ�����������n (1��n��2^128) ��r (1��r��2^128)���ֱ��������������İ뾶��

Բ����ʹ��3.14��
��Ӧÿһ�����ݣ��������װ������������Yes�������������No����
*/

#if 0
class Solution {
public:
	string chick(int n, int r)
	{
		if (100 * n < 2 * 314 * r)
			return "Yes";
		else
			return "No";
	}
};

#endif

