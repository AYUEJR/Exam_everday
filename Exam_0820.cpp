
#if 0
/*
��������:
�����ж������ݡ�
ÿ�����ݰ��������ַ���A��B������A����B���е�ƹ����ÿ��ƹ������һ����д��ĸ��ʾ������ͬ���͵�ƹ����Ϊ��ͬ�Ĵ�д��ĸ��
�ַ������Ȳ�����10000��
�������:
ÿһ�������Ӧһ����������B�����������������A�ж��У�����ÿ�����������������A���������Yes�������������No����
ABCDFYE CDE
ABCDGEAS CDECDE
Yes
No
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		map<char, int> AA, BB;
		for (int i = 0; i < A.size(); i++)
		{
			AA[A[i]]++;
		}
		for (int i = 0; i < B.size(); i++)
		{
			BB[B[i]]++;
		}
		for (int i = 'A'; i <= 'Z'; i++)
		{
			if (BB[i] > AA[i])
			{
				cout << "No" << endl;
				break;
			}
			if (i == 'Z')
			{
				cout << "Yes" << endl;
			}
		}

	}
}
#endif

/*

��������:
�������ֵ��е��ʵĸ���n��������n��������Ϊ�ֵ䵥�ʡ�
������һ�����ʣ����������ֵ����ֵܵ��ʵĸ���m
����������k

�������:
�������룬������ҵ����ֵܵ��ʵĸ���m
Ȼ��������ҵ����ֵܵ��ʵĵ�k�����ʡ�

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool isBrother(string str, string s) {
	if (str.size() == s.size()) {
		if (str == s)
			return false;
		sort(str.begin(), str.end());
		sort(s.begin(), s.end());
		if (str == s)
			return true;
	}
	return false;
}
int main() {
	int num;
	while (cin >> num) {
		string str;
		string word, s;
		int index;
		vector<string> vs;
		for (int i = 0; i < num; ++i) {
			cin >> str;
			vs.push_back(str);
		}
		sort(vs.begin(), vs.end());  // ��Ϊ���ֵ䣬һ��Ҫ���򣡣�
		cin >> word;
		cin >> index;
		int counts = 0;

		for (int i = 0; i < num; ++i) {
			if (isBrother(word, vs[i])) {
				counts++;
				if (counts == index)
					s = vs[i];
			}
		}
		if (!vs.empty())
			cout << counts << endl;
		if (counts >= index)
			cout << s << endl;

	}
	return 0;
}