/*

NowCoder�����ڳ���Σ�պ���ı�������Ϊ�����棬���״η��������룬���ھ��ӵ���Ϣ���ݡ�
�������Ǿ����е�һ�����٣���Ҫ�ѷ���������Ϣ������������ṩ����Ľ�����

��Ϣ���ܵİ취�ǣ�����Ϣԭ���е�ÿ����ĸ���ֱ��ø���ĸ֮��ĵ�5����ĸ�滻
�����磺��Ϣԭ���е�ÿ����ĸA ���ֱ��滻����ĸF���������ַ��� �䣬
������Ϣԭ�ĵ�������ĸ���Ǵ�д�ġ������е���ĸ��ԭ���е���ĸ��Ӧ��ϵ���¡�
������ĸ��A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
ԭ����ĸ��V W X Y Z A B C D E F G H I J K L M N O P Q R S T U


*/
#if 0

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string caeserPwd;       //���������ַ���
	string abcde = "VWXYZ"; //�û�ABCDEʹ���ַ���
	string over;            //��ȡEND�ַ���ר��
	int len = 0;            //�洢�������볤��
	while (1)                //ֱ������ENDOFINPUT����ѭ��
	{
		getline(cin, caeserPwd);       //��ȡһ�����룬ע��Ҫʹ��getline()
		if ("START" == caeserPwd)      //�������ʼ�б�־��ִ�����д���
		{
			getline(cin, caeserPwd);   //��ȡ�ڶ������룬��һ�о����������ˡ�
			len = caeserPwd.length(); //��������볤��
			for (int i = 0; i < len; i++)
			{
				if (caeserPwd[i] >= 'A' && caeserPwd[i] <= 'E')   //�����A-E֮������û�ΪVWXYZ
					caeserPwd[i] = abcde[caeserPwd[i] - 'A'];
				else if (caeserPwd[i] > 'E' && caeserPwd[i] <= 'Z') //�����E-Z֮�����ĸ��ֱ���û�Ϊ��ǰ�ߵ������ĸ
					caeserPwd[i] = caeserPwd[i] - 5;
			}
			getline(cin, over);              //��ȡ����������ַ���
			if ("END" == over)               //�����END������־�����������ԭ��
				cout << caeserPwd << endl;
		}
		else if ("ENDOFINPUT" == caeserPwd) //����ǽ��������־ENDOFINPUT���������
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