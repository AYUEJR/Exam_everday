
#if 0
/*
���й��Ľ��ղ�ͬ�������Ľڼ���ͨ����ѡ��ĳ���µĵڼ������ڼ�������ʽ��
���ÿһ��ķż����ڶ�����ͬ������������£�
* 1��1�գ�Ԫ��
* 1�µĵ���������һ������·�¡��������
* 2�µĵ���������һ����ͳ��
* 5�µ����һ������һ��������ʿ������
* 7��4�գ���������
* 9�µĵ�һ������һ���Ͷ���
* 11�µĵ��ĸ������ģ��ж���
* 12��25�գ�ʥ����
���ڸ���һ����ݣ������æ���ɵ�����յ����ڡ�
*/
#include <iostream>
using namespace std;
int WeekToDay(int y, int m, int c, int w, bool B)
{
	//�����������µڼ������ڼ����Լ��������ǵ������������   
	int d, week, i;
	if (1 == m || m == 2)
	{
		m += 12;
		y--;
	}
	i = 0;
	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--))
	{
		//B������/����    
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;//��ķ����ɭ��ʽ
		if (week + 1 == w) ++i;
		if (i == c) break;
	}
	return d;
}
int main(void)
{
	int y;
	while (cin >> y)
	{
		cout << y << "-01-01" << endl;
		printf("%d-01-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		printf("%d-02-%02d\n", y, WeekToDay(y, 2, 3, 1, 1));
		printf("%d-05-%02d\n", y, WeekToDay(y, 5, 1, 1, 0));//����
		cout << y << "-07-04" << endl;
		printf("%d-09-%02d\n", y, WeekToDay(y, 9, 1, 1, 1));
		printf("%d-11-%02d\n", y, WeekToDay(y, 11, 4, 4, 1));
		cout << y << "-12-25" << endl << endl;
	}
	return 0;
}

#endif

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	int n, i, j;
	int a[100];
	while (scanf("%d", &n) != EOF)
	{
		int m = n;
		j = 0;
		for (i = 2; i <= n; i++)
		{
			while (n%i == 0)
			{
				a[j++] = i;
				n = n / i;
			}
			//if(n<=1)
			  //break;
		}
		printf("%d = %d", m, a[0]);
		for (i = 1; i < j; i++)
			printf(" * %d", a[i]);
		printf("\n");
	}
	return 0;
}
