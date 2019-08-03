#if 0
#include<iostream>
#include<vector>
using namespace std;


	/**
	 *	���������е���С������ɺ�
	 *	���룺��������arr
	 *	���أ����������е���С������ɺ�
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
��Ȼ�мٱң� �����������ˣ�����ũ��Ĺ���ȴ�����ǰ���ûǮ��ô�����Ⱑ��
nowcoder���ȥ�����⣬�����������Ǯ���мٱң�������ϧnowcoderһ��С�İ��������һ���������ȥ�ˡ�
ֻ֪���ٱҵ���������ҵ�����Ҫ�ᣬ����һ����ƽ����ƽ�������������޸�Ӳ�ң���
��������ʱ����Ǹ��ɶ�ļٱ��ҳ�����

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
