
/*
�Ǽ�ս����չ��100��֮��NowCoder���������������˵����룡���ǵ�������һ��������\
ͨ��һ�ű������Ϣӳ�������4λ���롣��Ĺ����ǣ�n��Ӧ��ֵ�Ǿ���X��n�η������Ͻǣ�
������������4λ����0��䣬�������4λ����ֻ������4λ��

������һ��쳲��������У�����1 2 3 5 8 ���������������ε������ǾͿ����õݹ���������
*/


//�ݹ鷨
#if 0
#include <iostream>
#include <vector>
using namespace std;

int FeiBoNa(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	return FeiBoNa(n - 1) + FeiBoNa(n - 2);
}


int main() {
	int n;
	vector<int>a;
	while (cin >> n) {
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			printf("%04d", FeiBoNa(a[i]) % 10000);
		}
	}
	return 0;
}
#endif

//ѭ����
#if 0
#include <iostream>
#include <vector>
std::vector<int> a = { 1,1 };
void data_init() {
	int i;
	for (i = 2; i < 10005; i++) {
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
}

int main()
{
	int n, t;
	data_init();
	while (std::cin >> n) {
		while (n--) {
			std::cin >> t;
			printf("%04d", a[t]);
		}
		printf("\n");
	}
	return 0;
}

#endif


//������
#if 0
#include <iostream>
using namespace std;

int datacal(int num) {
	int first = 1;
	int second = 2;
	int third = 0;
	while (--num) {
		third = first + second;
		first = second;
		second = third;
	}
	return first;
}

int main() {
	int n, t;
	while (std::cin >> n) {
		while (n--) {
			std::cin >> t;
			printf("%04d", datacal(t) % 10000);
		}
		printf("\n");
	}
	return 0;
}
#endif

/*
��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ�������õ�������һλ������ô�������������������������λ�����߰�������λ�����֣���ô�ٰ���Щ���ּ���������˽�����ȥ��ֱ���õ���һλ��Ϊֹ�����磬����24 ��˵����2 ��4 ��ӵõ�6������6 ��һλ�������6 ��24 ���������ٱ���39����3 ��9 �������õ�12������12 ����һλ������˻��ð�1 ��2 �����������õ�3������һ��һλ�������3 ��39 �����������ڸ���һ�����������������������������������������������ݡ�ÿ���������ݰ���һ��������n��1��n��10E1000����
�����������Ӧÿһ�����ݣ��������������������
���룺24 39
�����6 3
*/

#include <iostream>
using namespace std;

int numRoot(int num) {
	int nroot = 0;
	while (num > 0) {
		nroot += num % 10;
		num /= 10;
	}
	//������������ر�����д��Ϊif,һ��Ҫ��while��
	//��Ϊ����ǵݹ飬return ���ص�ʱ�򲢲�һ�����˳���ֻ�Ƿ��ص�
	//��һ�㺯���ĵ��õ�ĩβ
	while (nroot > 9) {
		nroot = numRoot(nroot);
	}
	return nroot;
}

int main() {
	std::string origin;
	while (std::cin >> origin) {
		int sum = 0;
		//�Ƚ�ÿһλ������ӵõ��ܺͣ���ֹ���ֹ���
		//���������󣬻��˷Ѵ�����ʱ��ȥ����ÿһλ������
		//������������һ���򵥵��Ż�
		for (int i = 0; i < origin.length(); i++) {
			sum += origin[i] - '0';
		}
		//���ܺ�������
		std::cout << numRoot(sum) << std::endl;
	}
	return 0;
}
