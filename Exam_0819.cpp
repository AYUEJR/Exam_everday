

#if 0
/*
C++תJAVA�ı��������ı䡪������������

*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		//s[0] = s[0] - 32;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '_')
			{
				s.erase(s.begin() + i);
				s[i] = s[i] - 32;
			}
		}
		cout << s << endl;
	}
	return 0;
}
#endif 


/*
���ַ����е����е��ʽ��е��š�

˵����

1��ÿ����������26����д��СдӢ����ĸ���ɣ�

2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������

3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������

4��ÿ�������20����ĸ��
*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string>svec;
		svec.clear();
		string temp = "";
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
				temp += str[i];
			else
			{
				if (temp.size() > 0)
				{
					svec.push_back(temp);
					temp = "";
				}
			}
		}
		if (temp.size() > 0)
			svec.push_back(temp);
		for (int i = svec.size() - 1; i > 0; --i)
			cout << svec[i] << ' ';
		cout << svec[0] << endl;
	}
	return 0;
}
