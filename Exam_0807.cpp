
#if 0
/*
NowCoderÿ��Ҫ�����ͻ�д�����ʼ�����������֪�����һ���ʼ��а�������ռ��ˣ��ռ�������֮�����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ���������Ҫ��˫���Ű�����
���ڸ���һ���ռ����������������������Ӧ���ռ����б�

��������:
��������������ݡ�

ÿ�����ݵĵ�һ����һ������n (1��n��128)����ʾ������n��������

������n�У�ÿһ�а���һ���ռ��˵��������������Ȳ�����16���ַ���

�������:
��Ӧÿһ�����룬���һ���ռ����б�
ʾ��1
����
3
Joe
Quan, William
Letendre,Bruce
2
Leon
Kewell
���
Joe, ��Quan, William��, ��Letendre,Bruce��
Leon, Kewell
��������vectro����������ַ���������string��find
�������ж��Ƿ��У��Ϳո�����н��������ʽ��һЩ�仯��
�������������Ŀ������¼���
1.�������Ŀ������ÿ������ʱ���żӿո�����Ƕ���
2.��ѭ�����ж�������cinʱҪ��cin.get()�����ѻ��з�ȡ��������������ѻ��з����뵽vector�ĳ�Ա���档
3.Ҫע��string��find�������Ҳ���ָ���ַ���ʱ�᷵��npos����һ���ܴ������������-1.

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

		for (int i = 0; i < m.size(); i++)//����ȡ��һ��
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
һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ���ӡ�

��������:
�������ݰ������飬ÿ��һ�У�Ϊ����n(1��n��90)��

�������:
��Ӧ�����n���м�ֻ����(����û��������������)��
ʾ��1
����
1
2
���
1
2
������ûʲô��˵�ģ�����һ��쳲��������У���һ��������������ص�ֵ��
����Ҫ�õݹ麯������ʱ̫���ˡ�
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


