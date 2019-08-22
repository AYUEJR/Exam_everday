
#if 0
/*
输入描述:
输入有多组数据。
每组数据包含两个字符串A、B，代表A盒与B盒中的乒乓球，每个乒乓球用一个大写字母表示，即相同类型的乒乓球为相同的大写字母。
字符串长度不大于10000。
输出描述:
每一组输入对应一行输出：如果B盒中所有球的类型在A中都有，并且每种球的数量都不大于A，则输出“Yes”；否则输出“No”。
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

输入描述:
先输入字典中单词的个数n，再输入n个单词作为字典单词。
再输入一个单词，查找其在字典中兄弟单词的个数m
再输入数字k

输出描述:
根据输入，输出查找到的兄弟单词的个数m
然后输出查找到的兄弟单词的第k个单词。

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
		sort(vs.begin(), vs.end());  // 因为是字典，一定要排序！！
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