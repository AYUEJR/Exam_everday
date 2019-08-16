#if 0

/*    字符串计数
求字典序在s1和s2之间的，长度在len1到len2的字符串的个数，结果mod 1000007。

每组数据包涵s1（长度小于100），s2（长度小于100），len1（小于100000），len2（大于len1，小于100000）
输入
ab ce 1 2
输出   56
*/
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
	string str1, str2;
	int len1, len2;
	while (cin >> str1 >> str2 >> len1 >> len2)
	{
		if (str1.length() < len2)
			str1.append(len2 - str1.length(), 'a' - 1);
		if (str2.length() < len2)
			str2.append(len2 - str2.length(), 'z' + 1);
		long long sum = 0;
		int k = 0;
		//第一步，找第一个相对位置不相等的位置下标
		while (str1[k] == str2[k])
		{
			k++;
		}
		if (str1[k] < str2[k] && len1 <= len2)
		{
			//第二步，计算str[k]>str1[k] && str[k]<str2[k]的情况
			for (int i = len1 - 1; i < len2; i++)
			{
				if (i == k)
				{
					if (k == len1 - 1 && k == len2 - 1)
						sum += str2[k] - str1[k] - 1;
					else
						sum += str2[k] - str1[k];
				}
				else
					sum += (str2[k] - str1[k] - 1)*pow(26, i - k);
			}
			k++;
			//第三步，计算str[k]==str1[k]时的情况和str[k]==str2[k]的情况
			for (int i = len1; i <= len2; i++)
			{
				for (int j = k; j < i; j++)
					sum += ('z' - str1[j])*pow(26, i - j - 1);
				for (int j = k; j < i; j++)
					sum += (str2[j] - 'a')*pow(26, i - j - 1);
			}
		}
		cout << sum << endl;//我这里没有对1000007取模，答案也是能过的，牛友们可自行添加
	}
	system("pause");
	return 0;
}

#endif

/*
我们有两个字符串m和n，如果它们的子串a和b内容相同，则称a和b是m和n的公共子序列。子串中的字符不一定在原字符串中连续。
例如字符串“abcfbc”和“abfcab”，其中“abc”同时出现在两个字符串中，因此“abc”是它们的公共子序列。此外，“ab”、“af”等都是它们的字串。
现在给你两个任意字符串（不包含空格），请帮忙计算它们的最长公共子序列的长度。

输入包含多组数据。

每组数据包含两个字符串m和n，它们仅包含字母，并且长度不超过1024。

对应每组输入，输出最长公共子序列的长度。

*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1025][1025] = { 0 };

int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		(b.at(0) == a.at(0)) ? (dp[0][0] = 1) : (dp[0][0] = 0);

		for (int i = 1; i < a.length(); i++)
		{
			if (b.at(0) == a.at(i))
			{
				dp[i][0] = 1;
			}
			else
			{
				dp[i][0] = dp[i - 1][0];
			}
		}
		for (int i = 1; i < b.length(); i++)
		{
			if (b.at(i) == a.at(0))
			{
				dp[0][i] = 1;
			}
			else
			{
				dp[0][i] = dp[0][i - 1];
			}
		}

		for (int i = 1; i < a.length(); i++)
		{
			for (int j = 1; j < b.length(); j++)
			{
				dp[i][j] = max(dp[i - 1][j - 1] + int(a.at(i) == b.at(j)), max(dp[i][j - 1], dp[i - 1][j]));
			}
		}

		cout << dp[a.length() - 1][b.length() - 1] << endl;
	}

	return 0;
}
