#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

#if 0
//const成员函数代码验证
class Date
{
public:
	void Display()
	{
		cout << "Display()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl;
	}
	void Display()const
	{
		cout << "Display()const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d1;
	d1.Display();

	const Date d2;
	d2.Display();
}
int main()
{
	test();
}

#endif

//字符串反转C/C++
#if 0
#include<iostream>
#include<string>

using namespace std;
int main()
{
	string mystr;
	getline(cin, mystr);

	string::reverse_iterator rbegin, rend;
	rbegin = mystr.rbegin();
	rend = mystr.rend();
	while (rbegin != rend)
	{
		cout << *rbegin;
		rbegin++;
	}
	system("pause");
	return 0;
}
#endif

#if 0
void Reverse(char *s) 
{
	int n=0;
		while (*s != '/0')
		{
			n++;
		}
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main()
{
	char s[10];
	 s[10]=getchar();
     Reverse(s);

	cout << s << endl;

	return 0;
}
#endif


//计算两个字符串的最大公共字串的长度，字符不区分大小写(要求计算连续最长字串的长度)
#include<cstring>

//按题目要求是连续的相等子序列
//动态规划
int main()
{
	string A;

	while (cin >> A)
	{
		string B;
		cin >> B;
		int l1 = A.size();
		int l2 = B.size();
		//生成二维数组
		int** dp = new int*[l1];
		for (int i = 0; i < l1; i++)
		{
			dp[i] = new int[l2];
		}
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				dp[i][j] = 0;
			}
		}
		int n = 0;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				if (A[i] != B[j])
					dp[i][j] = 0;
				else if (i == 0 || j == 0)//对于第一行和第一列
				{
					dp[i][j] = 1;
					if (n < 1)
						n = dp[i][j];
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (dp[i][j] > n)
						n = dp[i][j];
				}
			}
		}
		cout << n << endl;
	}
	return 0;
}

