/*

NowCoder生活在充满危险和阴谋的年代。为了生存，他首次发明了密码，用于军队的消息传递。
假设你是军团中的一名军官，需要把发送来的消息破译出来、并提供给你的将军。

消息加密的办法是：对消息原文中的每个字母，分别用该字母之后的第5个字母替换
（例如：消息原文中的每个字母A 都分别替换成字母F），其他字符不 变，
并且消息原文的所有字母都是大写的。密码中的字母与原文中的字母对应关系如下。
密码字母：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
原文字母：V W X Y Z A B C D E F G H I J K L M N O P Q R S T U


*/
#if 0

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string caeserPwd;       //凯撒密码字符串
	string abcde = "VWXYZ"; //置换ABCDE使用字符串
	string over;            //获取END字符串专用
	int len = 0;            //存储凯撒密码长度
	while (1)                //直到输入ENDOFINPUT结束循环
	{
		getline(cin, caeserPwd);       //获取一行密码，注意要使用getline()
		if ("START" == caeserPwd)      //如果是起始行标志则执行下列代码
		{
			getline(cin, caeserPwd);   //获取第二行密码，这一行就是密码体了。
			len = caeserPwd.length(); //计算出密码长度
			for (int i = 0; i < len; i++)
			{
				if (caeserPwd[i] >= 'A' && caeserPwd[i] <= 'E')   //如果是A-E之间的则置换为VWXYZ
					caeserPwd[i] = abcde[caeserPwd[i] - 'A'];
				else if (caeserPwd[i] > 'E' && caeserPwd[i] <= 'Z') //如果是E-Z之间的字母则直接置换为其前边第五个字母
					caeserPwd[i] = caeserPwd[i] - 5;
			}
			getline(cin, over);              //获取密码结束行字符串
			if ("END" == over)               //如果是END结束标志，则输出密码原文
				cout << caeserPwd << endl;
		}
		else if ("ENDOFINPUT" == caeserPwd) //如果是结束输入标志ENDOFINPUT则结束程序
		{
			break;
		}
	}
	return 0;
}

#endif 

#include<iostream>
using namespace std;
int main() {
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string s;
	while (getline(cin, s)) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				cout << str[(int(s[i]) - 65 - 5 + 26) % 26];
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}