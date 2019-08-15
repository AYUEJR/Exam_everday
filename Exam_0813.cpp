
#if 0
/*
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。
你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）黑色瓷砖移动。
请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

输入包含多组数据。

每组数据第一行是两个整数 m 和 n（1≤m, n≤20）。紧接着 m 行，每行包括 n 个字符。每个字符表示一块瓷砖的颜色，规则如下：

1. “.”：黑色的瓷砖；
2. “#”：白色的瓷砖；
3. “@”：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。

对应每组数据，输出总共能够到达多少块黑色的瓷砖。


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
输出
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
现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，
A在(1,1),B在(n,m)。现在A想要拜访B，由于她只想去B的家，所以每次她只会走(i,j+1)或(i+1,j)这样的路线，
在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格),
问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，那么她不碰到蘑菇走到B的家的概率是多少？

输入
第一行N，M，K(1 ≤ N,M ≤ 20, k ≤ 100),N,M为草地大小，接下来K行，每行两个整数x，y，代表(x,y)处有一个蘑菇。
输出
输出一行，代表所求概率(保留到2位小数)
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
