
#if 0
/*
年会抽奖

今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
待所有字条加入完毕，每人从箱中取一个字条； 如果抽到的字条上写的就是自己的名字，
那么“恭喜你，中奖了！”现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？

输入描述：输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。
输出描述：对应每一组数据，以“xx.xx%”的格式输出发生无人获奖的概率。
示例1:输入 2 输出 50.00%

D(n)=(n-1)[D(n-2)+D(n-1)]  特殊的D(1)=0,,D(2)=1
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	long long d[22] = { 0, 0, 1 };
	// 错排数量，预留第一项为 0 ，配合下文中输入的 n
	long long f[22] = { 0, 1, 2 };
	// 阶 乘
	for (int i = 3; i < 22; i++) {
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); // 错排的递推公式
		f[i] = i * f[i - 1]; // 阶乘的递推公式
	}

	int n;
	while (std::cin >> n) {
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// 用 100.0 来把结果处理成 double ，保留两位小数
	}

	system("pause");
	return 0;
}


#endif

/*
抄送列表

NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。
他认为这些抄送的邮件重要性比自己在收件人列表里的邮件低，因此他要过滤掉这些次要的邮件，
优先处理重要的邮件。现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。

输入描述：输入有多组数据，每组数据有两行。第一行抄送列表，姓名之间用一个逗号隔开。
如果姓名中包含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。第二行只包含一个姓名，
是待查找的用户的名字（姓名要完全匹配）。长度不超过16个字符。

输出描述：如果第二行的名字出现在收件人列表中，则输出“Ignore”，表示这封邮件不重要；
否则，输出“Important!”，表示这封邮件需要被优先处理。

输入
Joe,Kewell,Leon
Joe
“Letendre, Bruce”,Joe,“Quan, William”
William
输出
Ignore
Important!
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
int main() {
	std::string line;
	// 第一次的输入抓到 line 里
	while (std::getline(std::cin, line)) {
		std::vector<std::string> names;
		//names 里存放所有的数据
		size_t pos = 0;
		// 位置如果大于等于了长度，那么证明找完了，双引号的情况从这里跳出
		while (pos < line.length()) {
			// 找到双引号要处理双引号内部
			if (line[pos] == '\"') {
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1));
				// 截取出来放到 names 里
				pos = end + 2;
				// 跳掉后面的双引号和逗号
			}
			else {
				size_t end = line.find(",", pos + 1);
				// 找不到逗号证明这是最后一个字符串了，直接存了这个字符串后跳出ne.find(",", pos + 1);
				if (end == -1) {
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				}
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1; // 跳掉后面的逗号
			}
		}

		std::getline(std::cin, line);
		if (names.end() == std::find(names.begin(), names.end(), line))
			//std::find 函数是在两个迭代器中间查找，最后一个参数是要找的值。
			// 找到了返回对应迭代器，找不到就返回区间末尾的位置。本例中是 end() 。
		{
			printf("Important!\n"); // 没找到
		}
		else {
			printf("Ignore\n"); // 找到了
		}
	}
	return 0;
}
