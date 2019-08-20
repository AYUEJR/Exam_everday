
#if 0
/*

��ͼ��һ���绰�ľŹ�����������һ�����ֶ�ӦһЩ��ĸ������ڹ�����ҵϲ���ѵ绰������Ƴ����Լ���˾�������Ӧ��
���繫˾��Help Desk������4357����Ϊ4��ӦH��3��ӦE��5��ӦL��7��ӦP�����4357����HELP��
ͬ��TUT-GLOP�ʹ���888-4567��310-GINO����310-4466��
NowCoder�ս������󣬲���ϰ��������������ʽ�����ڸ���һ���绰�����б�
�������ת����������ʽ�ĺ��룬��ȥ���ظ��Ĳ��֡�

*/


#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
	string s;
	int length;
	string NUM = "22233344455566677778889999";
	while (cin >> length)
	{
		set<string> data;
		int cnt;
		for (int i = 0; i < length; i++)
		{
			cnt = 0;
			string res;
			cin >> s;
			for (int j = 0; j < s.length(); j++)
			{
				if (s[j] >= 'A'&&s[j] <= 'Z')
				{
					res += NUM[s[j] - 'A'];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
				else if (s[j] >= '0'&&s[j] <= '9')
				{
					res += s[j];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
			}
			data.insert(res);
		}
		for (set<string>::iterator it = data.begin(); it != data.end(); it++)
			cout << *it << endl;
		cout << endl;
	}
	return 0;
}

#endif


/*
2010������������
�����⣺
������������ n �� m��������1��2��3.......n������ȡ������,
ʹ��͵��� m ,Ҫ���������еĿ�������г���.



������

����ʹ�õݹ�˼�룬 �ӵ�n������ʼ������ϣ�

1������n���������

2��������n���������

�������������������OK�ˡ�

*/


#include<iostream>
#include<vector>
#include<set>
#include<math.h>
using namespace std;

void Getmsets(int n, int m, vector<vector<int> >&allsets)
{
	if (n < 1 || m < 1) return;
	if (m > n*(n + 1) / 2) return;//n too small
	if (n > m)
		n = m;
	vector<int> _vecset;
	if (n == m)
	{
		_vecset.push_back(n);
		allsets.push_back(_vecset);
		Getmsets(n - 1, m, allsets);
	}
	else
	{
		vector<vector<int> > _vecvecsets;
		//����n�����
		Getmsets(n, m - n, _vecvecsets);
		vector<vector<int> >::iterator itvecvec;
		for (itvecvec = _vecvecsets.begin(); itvecvec != _vecvecsets.end(); ++itvecvec)
		{
			itvecvec->push_back(n);
			allsets.push_back(*itvecvec);
		}
		_vecvecsets.clear();
		//������n�����
		Getmsets(n - 1, m, _vecvecsets);
		for (itvecvec = _vecvecsets.begin(); itvecvec != _vecvecsets.end(); ++itvecvec)
		{
			allsets.push_back(*itvecvec);
		}
	}
}

int main()
{

	vector<vector<int> > vecvecres;
	Getmsets(10, 10, vecvecres);
	cout << "n = 10, m = 10, ���е����Ϊ��" << endl;
	vector<vector<int> >::iterator itvecvec;
	for (itvecvec = vecvecres.begin(); itvecvec != vecvecres.end(); ++itvecvec)
	{
		for (vector<int>::iterator itvec = itvecvec->begin(); itvec != itvecvec->end(); ++itvec)
		{
			cout << *itvec << ",";
		}
		cout << endl;
	}
	return 0;
}
