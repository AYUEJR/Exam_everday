#if 0
#include<iostream>
#include<vector>
using namespace std;


	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
class Solution {
public:
	int getFirstUnFormedNum(vector<int> arr, int len) {
		int sum = 0, min = arr[0];
		for (int i = 0; i < len; ++i)
		{
			sum += arr[i];
			if (arr[i] < min)
				min = arr[i];
		}
		vector<int> dp(sum + 1, 0);
		for (int i = 0; i < len; ++i)
		{
			for (int j = sum; j >= arr[i]; --j)
			{
				if (dp[j - arr[i]] + arr[i] > dp[j])
				{
					dp[j] = dp[j - arr[i]] + arr[i];
				}
			}
		}

		for (int i = min; i <= sum; ++i)
		{
			if (i != dp[i])
				return i;
		}
		return sum + 1;
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		Solution s;
		cout << s.getFirstUnFormedNum(a, n) << endl;
	}
	return 0;
} 

#endif

/*
居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。
nowcoder这就去买猪肉，结果找来的零钱中有假币！！！可惜nowcoder一不小心把它混进了一堆真币里面去了。
只知道假币的重量比真币的质量要轻，给你一个天平（天平两端能容纳无限个硬币），
请用最快的时间把那个可恶的假币找出来。

*/
#include<stdio.h>
int phony(int x)
{
	if (x == 1) return 0;
	else if (x <= 3) return 1;
	else return phony((x + 2) / 3) + 1;
}
int main()
{
	int x;
	while (scanf("%d", &x) != EOF)
	{
		if (x != 0) printf("%d\n", phony(x));
		else break;
	}
	return 0;
}
