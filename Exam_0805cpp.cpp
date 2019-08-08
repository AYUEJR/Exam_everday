

#if 0
/*
V\NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
现在给你一段时间区间，请你帮他计算总收益有多少。

输入描述:
输入包含多组数据。
每组数据包含两个日期from和to (2000-01-01 ≤ from ≤ to ≤ 2999-12-31)。
日期用三个正整数表示，用空格隔开：year month day。

输出描述:
对应每一组数据，输出在给定的日期范围（包含开始和结束日期）内能赚多少钱。

解题思路
分为三种情况处理

同年同月则直接利用天计算其中利润，若计算的日期包括闰年的2月，则多加1.
同年不同月时，先计算整月的利润，再将天的利润单独计算。
不同年时，先算整年的利润，再算整月的利润，再将天单独计算。
*/
#include <iostream>
using namespace std;

bool IsSu(int n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

bool IsRun(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int Money(int y1, int m1, int d1, int y2, int m2, int d2)
{
	int sum = 0;
	int s1[] = { 0, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };
	int s2[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (y1 == y2 && m1 == m2)
	{
		int n = 0;
		if (IsSu(m1))
			n += d2 - d1 + 1;
		else
			n += 2 * (d2 - d1 + 1);
		sum = n;
	}
	else if (y1 == y2 && m1 != m2)
	{
		int n = 0;
		if (!IsRun(y1))
		{
			for (int i = m1 + 1; i < m2; i++)
				n += s1[i];
			if (IsSu(m1) && IsSu(m2))
				n += s2[m1] - d1 + 1 + s2[m2] - d2 + 1;
			else if (!IsSu(m1) && !IsSu(m2))
				n += 2 * (s2[m1] - d1 + 1 + s2[m2] - d2 + 1);
			else if (!IsSu(m1) && IsSu(m2))
				n += 2 * (s2[m1] - d1 + 1) + s2[m2] - d2 + 1;
			else
				n += s2[m1] - d1 + 1 + 2 * (s2[m2] - d2 + 1);
		}
		else
		{
			if (m1 < 2 && 2 < m2)
				n += 1;
		}
		sum = n;
	}
	else
	{
		int n = 0;
		for (int i = y1 + 1; i < y2; i++)
		{
			if (!IsRun(i))
				n += 579;
			else
				n += 580;
		}
		for (int i = m1 + 1; i <= 12; i++)
		{
			if (IsRun(y1) && i == 2)
				n += 1;
			n += s1[i];
		}
		if (IsSu(m1))
			n += s2[m1] - d1 + 1;
		else
			n += 2 * (s2[m1] - d1 + 1);
		for (int i = 1; i < m2; i++)
		{
			if (IsRun(y2) && i == 2)
				n += 1;
			n += s1[i];
		}
		if (IsSu(m2))
			n += d2;
		else
			n += 2 * d2;
		sum = n;
	}
	return sum;
}

int main()
{
	int y1 = 0; int y2 = 0;
	int m1 = 0; int m2 = 0;
	int d1 = 0; int d2 = 0;
	while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2)
	{
		int sum = 0;
		sum = Money(y1, m1, d1, y2, m2, d2);
		cout << sum << endl;
	}
	system("pause");
	return 0;
}


#endif


/*
NowCoder号称自己已经记住了1-100000之间所有的斐波那契数。

为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。
当然，斐波那契数会很大。因此，如果第n个斐波那契数不到6位，
则说出该数；否则只说出最后6位。
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	long a[100001] = { 1,2 };
	for (int i = 2; i < 100001; i++)
		a[i] = (a[i - 1] % 1000000 + a[i - 2] % 1000000) % 1000000;//求余除100000的意思是让数列中的值保留原来的6位尾数
	while (cin >> n) //循环输入n
	{
		//加上判断，此时的数列值就是100000的分界处
		if (n < 25)
			cout << a[n - 1] << endl; //直接输出
		else
			printf("%06ld\n", a[n - 1]);//输出后六位
	}
	return 0;
}
