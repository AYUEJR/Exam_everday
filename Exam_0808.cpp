
#if 0
/*
���齱

���깫˾���Ľ�Ʒ�ر���������񽱵Ĺ��ȴ�����⣺
���ȣ�������Ա����һ��д���Լ����ֵ���������齱���У�
����������������ϣ�ÿ�˴�����ȡһ�������� ����鵽��������д�ľ����Լ������֣�
��ô����ϲ�㣬�н��ˣ������ڸ�����μ�������������������ж��ٸ��ʻ�������˻񽱣�

������������������������ݣ�ÿ�����ݰ���һ��������n��2��n��20����
�����������Ӧÿһ�����ݣ��ԡ�xx.xx%���ĸ�ʽ����������˻񽱵ĸ��ʡ�
ʾ��1:���� 2 ��� 50.00%

D(n)=(n-1)[D(n-2)+D(n-1)]  �����D(1)=0,,D(2)=1
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	long long d[22] = { 0, 0, 1 };
	// ����������Ԥ����һ��Ϊ 0 ���������������� n
	long long f[22] = { 0, 1, 2 };
	// �� ��
	for (int i = 3; i < 22; i++) {
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); // ���ŵĵ��ƹ�ʽ
		f[i] = i * f[i - 1]; // �׳˵ĵ��ƹ�ʽ
	}

	int n;
	while (std::cin >> n) {
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// �� 100.0 ���ѽ������� double ��������λС��
	}

	system("pause");
	return 0;
}


#endif

/*
�����б�

NowCoderÿ��Ҫ��������ʼ����������������ռ����б��У���ʱ��ֻ�Ǳ����͡�
����Ϊ��Щ���͵��ʼ���Ҫ�Ա��Լ����ռ����б�����ʼ��ͣ������Ҫ���˵���Щ��Ҫ���ʼ���
���ȴ�����Ҫ���ʼ������ڸ���һ�������б������ж�Ŀ���û��Ƿ��ڳ����б��С�

���������������ж������ݣ�ÿ�����������С���һ�г����б�����֮����һ�����Ÿ�����
��������а����ո�򶺺ţ�������������˫������ܳ��Ȳ�����512���ַ����ڶ���ֻ����һ��������
�Ǵ����ҵ��û������֣�����Ҫ��ȫƥ�䣩�����Ȳ�����16���ַ���

�������������ڶ��е����ֳ������ռ����б��У��������Ignore������ʾ����ʼ�����Ҫ��
���������Important!������ʾ����ʼ���Ҫ�����ȴ���

����
Joe,Kewell,Leon
Joe
��Letendre, Bruce��,Joe,��Quan, William��
William
���
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
	// ��һ�ε�����ץ�� line ��
	while (std::getline(std::cin, line)) {
		std::vector<std::string> names;
		//names �������е�����
		size_t pos = 0;
		// λ��������ڵ����˳��ȣ���ô֤�������ˣ�˫���ŵ��������������
		while (pos < line.length()) {
			// �ҵ�˫����Ҫ����˫�����ڲ�
			if (line[pos] == '\"') {
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1));
				// ��ȡ�����ŵ� names ��
				pos = end + 2;
				// ���������˫���źͶ���
			}
			else {
				size_t end = line.find(",", pos + 1);
				// �Ҳ�������֤���������һ���ַ����ˣ�ֱ�Ӵ�������ַ���������ne.find(",", pos + 1);
				if (end == -1) {
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				}
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1; // ��������Ķ���
			}
		}

		std::getline(std::cin, line);
		if (names.end() == std::find(names.begin(), names.end(), line))
			//std::find �������������������м���ң����һ��������Ҫ�ҵ�ֵ��
			// �ҵ��˷��ض�Ӧ���������Ҳ����ͷ�������ĩβ��λ�á��������� end() ��
		{
			printf("Important!\n"); // û�ҵ�
		}
		else {
			printf("Ignore\n"); // �ҵ���
		}
	}
	return 0;
}
