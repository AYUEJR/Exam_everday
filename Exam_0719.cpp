#include<iostream>
using namespace std;
#if 0
class A
{
public:
	void print()
	{
		cout << "A:print()";
	}
};
class B : private A
{
public:
	void print()
	{
		cout << "B:print()";
	}
};
class C : public B
{
public:
	void print() {
		A:: print();
	}
};
int main()
{
	C b;
	b.print();
}
#endif
 int getTotalCount(int month)
{
	if (month < 0)
		printf("month<0,data error\n");
	else if (month == 1 || month == 2)
		return 1;
	else {
		return getTotalCount(month - 1) + getTotalCount(month - 2);
	}
	return 0;
}
int main()
{
	int n = 0;
	int sum = 0;
	cin >> n;
	sum = getTotalCount(n);
	cout << sum << endl;
	return 0;
}








