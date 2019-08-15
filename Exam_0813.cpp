
#if 0
/*
��һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש��
��վ������һ���ɫ�Ĵ�ש�ϣ�ֻ�������ڵģ����������ĸ����򣩺�ɫ��ש�ƶ���
��дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��

��������������ݡ�

ÿ�����ݵ�һ������������ m �� n��1��m, n��20���������� m �У�ÿ�а��� n ���ַ���ÿ���ַ���ʾһ���ש����ɫ���������£�

1. ��.������ɫ�Ĵ�ש��
2. ��#������ɫ�Ĵ�ש��
3. ��@������ɫ�Ĵ�ש��������վ������ש�ϡ����ַ���ÿ�����ݼ�����Ψһ����һ�Ρ�

��Ӧÿ�����ݣ�����ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��


9 6
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
���
45
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int W, H, i, j;
char a[30][30];
int f(int x, int y)
{
	if (x < 0 || y < 0 || x >= H || y >= W)
		return 0;
	if (a[x][y] == '#')
		return 0;
	else {
		a[x][y] = '#';
		return 1 + f(x + 1, y) + f(x - 1, y) + f(x, y + 1) + f(x, y - 1);
	}
}
int main()
{
	while (scanf("%d%d", &H, &W) != EOF)
	{
		for (i = 0; i < H; i++)
			scanf("%s", a[i]);
		for (i = 0; i < H; i++)
			for (j = 0; j < W; j++)
				if (a[i][j] == '@')
					printf("%d\n", f(i, j));
	}
	return 0;
}

#endif

/*
��������������A��B��ס��һƬ����Ģ������n��m��������ɵĲݵأ�
A��(1,1),B��(n,m)������A��Ҫ�ݷ�B��������ֻ��ȥB�ļң�����ÿ����ֻ����(i,j+1)��(i+1,j)������·�ߣ�
�ڲݵ�����k��Ģ�����ڸ�����(���Ģ��������ͬһ����),
�ʣ�A���ÿһ�����ѡ��Ļ�(�����ڱ߽��ϣ���ֻ��һ��ѡ��)����ô��������Ģ���ߵ�B�ļҵĸ����Ƕ��٣�

����
��һ��N��M��K(1 �� N,M �� 20, k �� 100),N,MΪ�ݵش�С��������K�У�ÿ����������x��y������(x,y)����һ��Ģ����
���
���һ�У������������(������2λС��)
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, M, K;
	while (cin >> N >> M >> K) {
		vector<vector<int>> mat(N + 1, vector<int>(M + 1, 0));
		vector<vector<double>> dp(N + 1, vector<double>(M + 1, 0));
		int x, y;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			mat[x][y] = 1;
		}
		//dp[i][j]=dp[i-1][j]+dp[i][j-1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (mat[i][j] == 1) {
					dp[i][j] = 0;
					continue;
				}
				if (i == 1 && j == 1) {
					dp[i][j] = 1;
					continue;
				}
				if (i == N && j == M) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
					continue;
				}
				if (i == N) {
					dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1];
					continue;
				}
				if (j == M) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1] * 0.5;
					continue;
				}
				if (i == 1) {
					dp[i][j] = dp[i][j - 1] * 0.5;
					continue;
				}
				if (j == 1) {
					dp[i][j] = dp[i - 1][j] * 0.5;
					continue;
				}
				dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1] * 0.5;
			}
		}
		printf("%.2f\n", dp[N][M]);
	}
	return 0;
}
