#if 0


/*
NowCoder��������������壬���ڸ���һ����֣������æ�ж�������û���������飨�������Ҳ�㣩��
�����ж������ݣ�ÿ������Ϊһ��20x20�����̡�
���к����á�*����ʾ�������á�+����ʾ���հ�λ���á�.����ʾ��
��������ϴ����������飨����������ɫ�����ӣ������롰Yes�������������No����
*/

//�ذ˸���������

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define N 20

int count(string table[], char ch, int x, int y)
{
	int maxc = 0;
	int dir[4][2][2] = { {{ -1,0 },{ 1,0 }},{{ 0,-1 },{ 0,1 }},{{ -1,-1 },{ 1,1 }},{{ -1,1 },{ 1,-1 }} };
	for (int i = 0; i < 4; ++i) // ���ַ���
	{
		int c = 0;
		for (int j = 0; j < 2; ++j)  // ����С����
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
macs�ų���ı༭�������Դ���һ������������������������ͬ�����ǻ��ں�׺���ʽ�ģ�
��������ڲ������ĺ��档���硰2 3 +���ȼ�����׺���ʽ�ġ�2 + 3����
����ʵ��һ����׺���ʽ�ļ�������
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
			string ch;//����string��������char��ԭ���ǣ�charֻ�ܴ�10���µ��ַ�����������ַ�
			//����10���ͻ���ִ���
			cin >> ch;
			if (ch[0] == '+' || ch[0] == '-' || ch[0] == '*' || ch[0] == '/')
			{
				int right = st.top();//ջ�ṹ���Ե����ϣ�����ȡֵʱ����Ҫ��ȡ�Ҳ�����
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