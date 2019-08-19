
#if 0
/*
macs号称神的编辑器，它自带了一个计算器。与其他计算器不同，它是基于后缀表达式的，
即运算符在操作数的后面。例如“2 3 +”等价于中缀表达式的“2 + 3”。
请你实现一个后缀表达式的计算器。

*/

#include<iostream>
#include<string>
using namespace std;

void extNumber(string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			cout << str[i];
	}
	cout << endl;
}

int main()
{
	string str;
	while (getline(cin, str))
		extNumber(str);
	return 0;
}
#endif 


/*

NowCoder最喜欢游乐场的迷宫游戏，他和小伙伴们比赛谁先走出迷宫。
现在把迷宫的地图给你，你能帮他算出最快走出迷宫需要多少步吗？

输入包含多组数据。

每组数据包含一个10*10，由“#”和“.”组成的迷宫。其中“#”代表墙；“.”代表通路。

入口在第一行第二列；出口在最后一行第九列。

从任意一个“.”点都能一步走到上下左右四个方向的“.”点。

应每组数据，输出从入口到出口最短需要几步。

链接：https://www.nowcoder.com/questionTerminal/6276dbbda7094978b0e9ebb183ba37b9
来源：牛客网

#.########
#........#
#........#
#........#
#........#
#........#
#........#
#........#
#........#
########.#
#.########
#........#
########.#
#........#
#.########
#........#
########.#
#........#
#.######.#
########.#
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct pos { int x, y, level; };

int bfs(vector<vector<char> > & map)
{
	const int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
	queue<pos> que;
	int m = map.size(), n = map[0].size();
	vector<vector<bool> > visit(m, vector<bool>(n, false));

	pos start{ 0,1,0 }, end{ 9,8,0 };
	que.push(start);
	visit[start.x][start.y] = true;
	while (!que.empty())
	{
		pos cur = que.front(), next;
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.level = cur.level + 1;
			if (next.x == end.x && next.y == end.y) return next.level;
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
				!visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
			}
		}
	}

	return 0;
}

int main()
{
	vector<vector<char> > map(10, vector<char>(10));
	while (cin >> map[0][0])
	{
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < 10; ++j)
			{
				if (i == 0 && j == 0) continue;
				cin >> map[i][j];
			}

		cout << bfs(map) << endl;
	}

	return 0;
}