#include<iostream>
using namespace std;
#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	bool operator==(const Date& d2)
	{
		return _year == d2._year
		&&_month == d2._month
			&&_day == d2._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

void test()
{
   Date d1(2018,9,26);
   Date d2(2018,9,27);
   cout << (d1 == d2) << endl;
}
int main()
{
	test();
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2(2018, 10, 1);
	//d1调用编译器生成器operator=完成拷贝，d2和d1的值也是一样的
	d1 = d2;
	return 0;
}
#endif

#if 0
/*某商店规定：三个空汽水瓶可以换一瓶汽水。
小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”
答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，
喝完以后4个空瓶子，用3个*/
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int n, sum = 0;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)break;
		else if (n == 1)printf("%d\n", sum);
		else if (n == 2)printf("%d\n", sum + 1);
		else
		{
			while (n > 2)
			{
				sum += n / 3;
				n = n / 3 + n % 3;
			}
			if (n == 2)
				sum += 1;
			printf("%d\n", sum);
			sum = 0;
		}
	}
	return 0;
}
#endif

//查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
#include <string>
string maxCommonSubstr(string s3, string s4)
{
	string s1 = (s3.length() <= s4.length()) ? s3 : s4;
	string s2 = (s3.length() <= s4.length()) ? s4 : s3;
	int m = s1.length();
	int n = s2.length();
	string **dp = new string*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		dp[i] = new string[n + 1];
	}
	for (int i = 0; i < m + 1; i++)
		dp[i][0] = "";
	for (int i = 0; i < n + 1; i++)
		dp[0][i] = "";
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				int len = 0;
				int a = i - 1;
				int b = j - 1;
				while (a >= 0 && b >= 0 && s1[a] == s2[b])
				{
					len++;
					a--;
					b--;
				}
				if (len > dp[i - 1][j - 1].length() && len > dp[i - 1][j].length() && len > dp[i][j - 1].length())
				{
					dp[i][j] = s1.substr(a + 1, len);
				}
				else {
					if (dp[i][j - 1].length() > dp[i - 1][j].length())
					{
						dp[i][j] = (dp[i][j - 1].length() >= dp[i - 1][j - 1].length()) ? dp[i][j - 1] : dp[i - 1][j - 1];
					}
					else {
						dp[i][j] = (dp[i - 1][j].length() >= dp[i - 1][j - 1].length()) ? dp[i - 1][j] : dp[i - 1][j - 1];
					}
				}
			}
			else {
				if (dp[i][j - 1].length() > dp[i - 1][j].length())
				{
					dp[i][j] = (dp[i][j - 1].length() >= dp[i - 1][j - 1].length()) ? dp[i][j - 1] : dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = (dp[i - 1][j].length() >= dp[i - 1][j - 1].length()) ? dp[i - 1][j] : dp[i - 1][j - 1];
				}
			}
		}
	}

	string maxstr = dp[m][n];

	for (int i = 0; i < m + 1; i++)
	{
		delete[] dp[i];
		dp[i] = 0;
	}
	delete[] dp;
	dp = 0;
	return maxstr;
}
void test1()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << maxCommonSubstr(s1, s2) << endl;
	}
}

int main()
{
	test1();
	return 0;
}
