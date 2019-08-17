#if 0
/*
NowCoder每天要给很多人发邮件。有一天他发现发错了邮件，把发给A的邮件发给了B，把发给B的邮件发给了A。于是他就思考，要给n个人发邮件，在每个人仅收到1封邮件的情况下，有多少种情况是所有人都收到了错误的邮件？
即没有人收到属于自己的邮件。
输入
输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。
输出
对应每一组数据，输出一个正整数，表示无人收到自己邮件的种数。

*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()//典型的错排问题；
{
	int n, i;
	long long a[25] = { 0,0,1 };
	for (i = 3; i <= 20; i++)
	{
		a[i] = (i - 1)*(a[i - 1] + a[i - 2]);
	}
	while (~scanf("%d", &n))
	{
		printf("%lld\n", a[n]);
	}
	return 0;
}

#endif

/*
广场上站着一支队伍，她们是来自全国各地的扭秧歌代表队，现在有她们的身高数据，请你帮忙找出身高依次递增的子序列。 
例如队伍的身高数据是（1、7、3、5、9、4、8），
其中依次递增的子序列有（1、7），（1、3、5、9），（1、3、4、8）等，其中最长的长度为4。
输入
入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000）。
紧接着第二行包含n个正整数m（1≤n≤10000），代表队伍中每位队员的身高。
输出
对应每一组数据，输出最长递增子序列的长度。
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		vector<int> height(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> height[i];
		}

		vector<int> f(n, 1);
		int result = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (height[i] > height[j]) {
					f[i] = max(f[i], f[j] + 1);
				}
			}
			result = max(result, f[i]);
		}

		cout << result << endl;
	}
}
