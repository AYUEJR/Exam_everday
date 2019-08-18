#if 0


/*
NowCoder最近爱上了五子棋，现在给你一个棋局，请你帮忙判断其中有没有五子连珠（超过五颗也算）。
输入有多组数据，每组数据为一张20x20的棋盘。
其中黑子用“*”表示，白子用“+”表示，空白位置用“.”表示。
如果棋盘上存在五子连珠（无论哪种颜色的棋子），输入“Yes”，否则输出“No”。
*/

//沿八个方向搜索

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define N 20

int count(string table[], char ch, int x, int y)
{
	int maxc = 0;
	int dir[4][2][2] = { {{ -1,0 },{ 1,0 }},{{ 0,-1 },{ 0,1 }},{{ -1,-1 },{ 1,1 }},{{ -1,1 },{ 1,-1 }} };
	for (int i = 0; i < 4; ++i) // 四种方向
	{
		int c = 0;
		for (int j = 0; j < 2; ++j)  // 两个小方向
		{
			int nx = x, ny = y;
			while (nx >= 0 && nx < N && ny >= 0 && ny < N && table[nx][ny] == ch)
			{
				nx += dir[i][j][0];
				ny += dir[i][j][1];
				++c;
			}
		}
		maxc = (maxc > c ? maxc : c);
	}
	return maxc - 1;
}

bool solve(string table[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (table[i][j] == '*' || table[i][j] == '+')
				if (count(table, table[i][j], i, j) >= 5)
					return true;
		}
	}
	return false;
}

int main()
{
	string table[N];
	while (cin >> table[0])
	{
		for (int i = 1; i < N; ++i) cin >> table[i];
		cout << (solve(table) ? "Yes" : "No") << endl;
	}
	return 0;
}

#endif
/*
macs号称神的编辑器，它自带了一个计算器。与其他计算器不同，它是基于后缀表达式的，
即运算符在操作数的后面。例如“2 3 +”等价于中缀表达式的“2 + 3”。
请你实现一个后缀表达式的计算器。
*/


#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		stack<int> st;
		for (size_t i = 0; i < n; i++)
		{
			int sum = 0;
			string ch;//运用string而不是用char的原因是，char只能存10以下的字符，当输入的字符
			//大于10，就会出现错误
			cin >> ch;
			if (ch[0] == '+' || ch[0] == '-' || ch[0] == '*' || ch[0] == '/')
			{
				int right = st.top();//栈结构，自底向上，所以取值时，需要先取右操作数
				st.pop();
				int left = st.top();
				st.pop();
				if (ch[0] == '+')
					sum = left + right;
				if (ch[0] == '-')
					sum = left - right;
				if (ch[0] == '*')
					sum = left * right;
				if (ch[0] == '/')
				{
					if (right != 0)
						sum = left / right;
					else
						return 0;
				}
				st.push(sum);
			}
			else
				st.push(atoi(ch.c_str()));
		}
		cout << (int)st.top() << endl;
	}
	return 0;
}