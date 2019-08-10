
#if 0
/*
NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间会用一个逗号和空格隔开；如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
现在给你一组收件人姓名，请你帮他生成相应的收件人列表。

输入描述:
输入包含多组数据。

每组数据的第一行是一个整数n (1≤n≤128)，表示后面有n个姓名。

紧接着n行，每一行包含一个收件人的姓名。姓名长度不超过16个字符。

输出描述:
对应每一组输入，输出一行收件人列表。
示例1
输入
3
Joe
Quan, William
Letendre,Bruce
2
Leon
Kewell
输出
Joe, “Quan, William”, “Letendre,Bruce”
Leon, Kewell
分析：用vectro储存输入的字符串，再用string的find
函数来判断是否有，和空格，如果有将输出的形式做一些变化。
我遇到的这道题的坑有以下几个
1.看清楚题目，对于每个名字时逗号加空格而不是逗号
2.当循环的判断条件是cin时要用cin.get()函数把换行符取出来，否则程序会把换行符输入到vector的成员里面。
3.要注意string的find函数当找不到指定字符串时会返回npos，是一个很大的正数而不是-1.

*/
#include <iostream>
#include <string>
#include <vector>
int main()
{
	int num;
	while (std::cin >> num)
	{
		std::cin.get();
		std::vector<std::string> m;

		for (int i = 0; i < num; i++)
		{
			std::string str;
			std::getline(std::cin, str);
			m.push_back(str);
		}

		for (int i = 0; i < m.size(); i++)//不读取第一个
		{
			std::string str;
			str = m[i];
			if (str.find(" ") == std::string::npos && str.find(",") == std::string::npos)
			{
				std::cout << m[i];
				if (i != m.size() - 1)
					std::cout << ',' << ' ';

			}
			else
			{
				std::cout << '\"' << m[i] << '\"';

				if (i != m.size() - 1)
					std::cout << ',' << ' ';

			}

		}
		std::cout << std::endl;
	}


}

#endif

/*
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。

输入描述:
测试数据包括多组，每组一行，为整数n(1≤n≤90)。

输出描述:
对应输出第n天有几只兔子(假设没有兔子死亡现象)。
示例1
输入
1
2
输出
1
2
分析：没什么可说的，又是一个斐波那契数列，用一个数组来保存相关的值。
，不要用递归函数，耗时太久了。
*/

#include <iostream>
#include <string>
#include <vector>
int main()
{
	long long rabbit[90];
	rabbit[0] = 1;
	rabbit[1] = 2;
	for (int i = 2; i < 90; i++)
		rabbit[i] = rabbit[i - 1] + rabbit[i - 2];
	int num;
	while (std::cin >> num)
	{
		std::cout << rabbit[num - 1] << std::endl;
		std::cin.get();
	}
}


