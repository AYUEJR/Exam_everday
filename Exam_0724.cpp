#include<iostream>
#include<vector>
using namespace std;

#if 0

int max_divisor(int m, int n)
{
	int left = 0;
	while (n != 0)
	{
		left = m % n;
		m = n;
		n = left;
	}
	return m;
}

int last_force()
{
	int n;//���޸���
	int a;//��ʼ����ֵ
	cin >> n >> a;

	vector<int> v(n);//�洢n�����޵�����ֵ

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (v[i] <= a)//����ֵ<��ǰ������ֱ������v[i]����
		{
			a += v[i];
		}
		else
		{
			a += max_divisor(v[i], a);
		}
	}
	return a;
}
int main()
{
	int a = 0;
	a=last_force();
	cout << a << endl;
	return 0;
}

#endif

//��һ���ַ����е�һ��ֻ����һ�ε��ַ���ţ������
/*
��ͨ˼·�����ȿ���һ��Ԫ�أ������ַ�������ÿ���ַ��ܹ����ַ����г��ֵĴ�������������һ��ʱ�临�Ӷ�O��N�����㷨��
ţ�������ǿ϶��ܲ����ģ��������ǿ����뵽��ʲô�������Դﵽ��¼�ַ����ִ���ʱ�临�Ӷ��з���Ҫ����أ�
��ϣ��
������һ���ַ�����ÿ���ַ���ȡֵ��Χ�����ܳ���256�����ǿ���ֱ�ӽ���ϣ����������ҳ�ʼ��Ϊȫ0��
Ȼ���Ӧ�ַ���ASCII������ַ����г��ֵĴ�����
����Ϳ��Ա�����ϣ����ȷ����һ���ַ����ַ�����ֻ����һ�εģ�
���������Ǹ���str[i]�������Ϳ��Ա�֤������ʱ����ǰ���ԭ�ַ������ַ����ֵ��Ⱥ�˳�����ģ�
һ������hashtable[str[i]]==1����ֱ�ӷ���
*/
#include<string>
#include<assert.h>
char FindFirst(string str) {
	assert(str.size() > 0);
	int hashtable[256] = { 0 };
	int i = 0;
	for (i = 0; i < str.size(); i++) {
		hashtable[str[i]]++;
	}
	for (i = 0; i < str.size(); i++) {
		if (hashtable[str[i]] == 1) {
			return str[i];
		}
	}
	return 0;
}
int main() {
	string str = "qabcdfabcde";
	cin >> str;
	char ret = FindFirst(str);
	cout << ret << endl;
	system("pause");
	return 0;
}