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
	int n;//怪兽个数
	int a;//初始能力值
	cin >> n >> a;

	vector<int> v(n);//存储n个怪兽的武力值

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (v[i] <= a)//武力值<当前能力，直接增加v[i]武力
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

//找一个字符串中第一个只出现一次的字符（牛客网）
/*
普通思路就是先看第一个元素，遍历字符串看看每个字符总共在字符串中出现的次数，但是这是一个时间复杂度O（N）的算法，
牛客上面是肯定跑不过的，所以我们可以想到用什么东西可以达到记录字符出现次数时间复杂度有符合要求的呢？
哈希表
这里是一个字符串，每个字符的取值范围不可能超过256，我们可以直接将哈希表定义出来并且初始化为全0，
然后对应字符的ASCII存放在字符串中出现的次数，
后面就可以遍历哈希表来确定哪一个字符是字符串中只出现一次的，
由于我们是根据str[i]来遍历就可以保证遍历的时候就是按照原字符串中字符出现的先后顺序来的，
一旦遇到hashtable[str[i]]==1，就直接返回
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