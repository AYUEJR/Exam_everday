
#if 0
/*

上图是一个电话的九宫格，如你所见一个数字对应一些字母，因此在国外企业喜欢把电话号码设计成与自己公司名字相对应。
例如公司的Help Desk号码是4357，因为4对应H、3对应E、5对应L、7对应P，因此4357就是HELP。
同理，TUT-GLOP就代表888-4567、310-GINO代表310-4466。
NowCoder刚进入外企，并不习惯这样的命名方式，现在给你一串电话号码列表，
请你帮他转换成数字形式的号码，并去除重复的部分。

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
2010年中兴面试题
编程求解：
输入两个整数 n 和 m，从数列1，2，3.......n中随意取几个数,
使其和等于 m ,要求将其中所有的可能组合列出来.



分析：

可以使用递归思想， 从第n个数开始找其组合，

1）包括n的所有组合

2）不包括n的所有组合

把所有组合整合起来就OK了。

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
		//包括n的情况
		Getmsets(n, m - n, _vecvecsets);
		vector<vector<int> >::iterator itvecvec;
		for (itvecvec = _vecvecsets.begin(); itvecvec != _vecvecsets.end(); ++itvecvec)
		{
			itvecvec->push_back(n);
			allsets.push_back(*itvecvec);
		}
		_vecvecsets.clear();
		//不包括n的情况
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
	cout << "n = 10, m = 10, 所有的组合为：" << endl;
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
