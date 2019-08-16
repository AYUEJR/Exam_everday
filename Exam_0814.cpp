#if 0

/*    �ַ�������
���ֵ�����s1��s2֮��ģ�������len1��len2���ַ����ĸ��������mod 1000007��

ÿ�����ݰ���s1������С��100����s2������С��100����len1��С��100000����len2������len1��С��100000��
����
ab ce 1 2
���   56
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
		//��һ�����ҵ�һ�����λ�ò���ȵ�λ���±�
		while (str1[k] == str2[k])
		{
			k++;
		}
		if (str1[k] < str2[k] && len1 <= len2)
		{
			//�ڶ���������str[k]>str1[k] && str[k]<str2[k]�����
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
			//������������str[k]==str1[k]ʱ�������str[k]==str2[k]�����
			for (int i = len1; i <= len2; i++)
			{
				for (int j = k; j < i; j++)
					sum += ('z' - str1[j])*pow(26, i - j - 1);
				for (int j = k; j < i; j++)
					sum += (str2[j] - 'a')*pow(26, i - j - 1);
			}
		}
		cout << sum << endl;//������û�ж�1000007ȡģ����Ҳ���ܹ��ģ�ţ���ǿ��������
	}
	system("pause");
	return 0;
}

#endif

/*
�����������ַ���m��n��������ǵ��Ӵ�a��b������ͬ�����a��b��m��n�Ĺ��������С��Ӵ��е��ַ���һ����ԭ�ַ�����������
�����ַ�����abcfbc���͡�abfcab�������С�abc��ͬʱ�����������ַ����У���ˡ�abc�������ǵĹ��������С����⣬��ab������af���ȶ������ǵ��ִ���
���ڸ������������ַ������������ո񣩣����æ�������ǵ�����������еĳ��ȡ�

��������������ݡ�

ÿ�����ݰ��������ַ���m��n�����ǽ�������ĸ�����ҳ��Ȳ�����1024��

��Ӧÿ�����룬�������������еĳ��ȡ�

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
