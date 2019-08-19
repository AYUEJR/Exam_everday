
#if 0
/*
macs�ų���ı༭�������Դ���һ������������������������ͬ�����ǻ��ں�׺���ʽ�ģ�
��������ڲ������ĺ��档���硰2 3 +���ȼ�����׺���ʽ�ġ�2 + 3����
����ʵ��һ����׺���ʽ�ļ�������

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

NowCoder��ϲ�����ֳ����Թ���Ϸ������С����Ǳ���˭���߳��Թ���
���ڰ��Թ��ĵ�ͼ���㣬���ܰ����������߳��Թ���Ҫ���ٲ���

��������������ݡ�

ÿ�����ݰ���һ��10*10���ɡ�#���͡�.����ɵ��Թ������С�#������ǽ����.������ͨ·��

����ڵ�һ�еڶ��У����������һ�еھ��С�

������һ����.���㶼��һ���ߵ����������ĸ�����ġ�.���㡣

Ӧÿ�����ݣ��������ڵ����������Ҫ������

���ӣ�https://www.nowcoder.com/questionTerminal/6276dbbda7094978b0e9ebb183ba37b9
��Դ��ţ����

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