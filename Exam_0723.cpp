
#if 0;
/*洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。
现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。
首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿着第n+1张到第2n张（下半堆）。
接着就开始洗牌的过程，先放下右手的最后一张牌，再放下左手的最后一张牌，
接着放下右手的倒数第二张牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。
接着把牌合并起来就可以了。 例如有6张牌，最开始牌的序列是1,2,3,4,5,6。首先分成两组，
左手拿着1,2,3；右手拿着4,5,6。在洗牌过程中按顺序放下了6,3,5,2,4,1。把
这六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，就变成了序列1,4,2,5,3,6。
现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。
*/
//第一行一个数T(T ≤ 100)，表示数据组数。对于每组数据，第一行两个数n,k(1 ≤ n,k ≤ 100)，
//接下来一行有2n个数a1, a2, ..., a2n(1 ≤ ai ≤ 1000000000)。表示原始牌组从上到下的序列。
//对于每组数据，输出一行，最终的序列。数字之间用空格隔开，不要在行末输出多余的空格。
//输入例子：
/*
3 3 1
1 2 3 4 5 6
3 2
1 2 3 4 5 6
2 2
1 1 1 1
*/
//输出：
/*
1 4 2 5 3 6
1 5 4 3 2 6
1 1 1 1
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> sort(vector<int>& res);
int main() {
	int time;
	int n, k;
	cin >> time;
	while (time) {
		cin >> n >> k;
		vector<int> res(2 * n);
		for (unsigned int i = 0; i < 2 * n; ++i) {
			cin >> res[i];
		}
		while (k) {
			res = sort(res);
			k--;
		}
		for (int i = 0; i < res.size(); i++) {
			if (i != res.size() - 1)
				cout << res[i] << " ";
			else
				cout << res[i];
		}
		cout << endl;
		time--;
	}
	return 0;
}
vector<int> sort(vector<int>& res) {
	int size = res.size();
	int i = size / 2;
	int j = 1;
	vector<int> r;
	while (i) {
		r.push_back(res[size - j]);
		r.push_back(res[(size / 2) - j]);
		j++;
		i--;
	}
	for (int i = 0; i < (r.size() / 2); i++) {
		swap(r[i], r[r.size() - i - 1]);
	}
	return r;
}
#endif

/*

MP3 Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，用户要通过上下键才能浏览所有的歌曲。
为了简化处理，假设每屏只能显示4首歌曲，光标初始的位置为第1首歌。

现在要实现通过上下键控制光标移动来浏览歌曲列表，控制逻辑如下：

歌曲总数<=4的时候，不需要翻页，只是挪动光标位置。

光标在第一首歌曲上时，按Up键光标挪到最后一首歌曲；光标在最后一首歌曲时，按Down键光标挪到第一首歌曲。


*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		cin >> s;
		int cur_head = 1, cur_pos = 0;
		if (n <= 4) {
			for (int i = 0; i < (int)s.size(); i++) {
				if (s[i] == 'U') {
					cur_pos = (cur_pos + n - 1) % n;
				}
				else {
					cur_pos = (cur_pos + 1) % n;
				}
			}
		}
		else {
			for (int i = 0; i < (int)s.size(); i++) {
				if (s[i] == 'U') {
					if (cur_head == 1 && cur_pos == 0) {
						cur_head = n - 3;
						cur_pos = 3;
					}
					else {
						if (cur_pos > 0) {
							cur_pos--;
						}
						else {
							cur_head--;
						}
					}
				}
				else {
					if (cur_head == n - 3 && cur_pos == 3) {
						cur_head = 1;
						cur_pos = 0;
					}
					else {
						if (cur_pos < 3) {
							cur_pos++;
						}
						else {
							cur_head++;
						}
					}
				}
			}
		}
		for (int i = 0; i < min(n, 4); i++) {
			if (i) {
				printf(" ");
			}
			printf("%d", cur_head + i);
		}
		printf("\n%d\n", cur_head + cur_pos);
	}
	return 0;
}
