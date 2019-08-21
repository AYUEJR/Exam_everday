

#if 0
/*
C++转JAVA的变量命名改变——骆驼命名法

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
对字符串中的所有单词进行倒排。

说明：

1、每个单词是以26个大写或小写英文字母构成；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；
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
