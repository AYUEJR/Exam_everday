/*
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference,

product and quotient.

Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2".

The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in

front of the numerator. The denominators are guaranteed to be non-zero numbers.


For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each

line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is

the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the

denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.

*/

#include <iostream>
#include <cmath>

using namespace std;

//分数的结构体
typedef struct fraction
{
	int isNegative;	//正负号
	long int i, numerator, denominator;	//整数部分、分子、分母
	//初始化分数
	fraction() :isNegative(1), i(0), numerator(0), denominator(1)
	{

	};
}fraction;

//重载 == 操作符
bool operator==(fraction& f, long int x)
{
	return f.numerator == 0 && f.i*f.isNegative == x;
}

//myabs_求绝对值
long int myabs(long int x)
{
	if (x < 0)
		return -x;
	return x;
}

//将分数转换为要求的形式
fraction simply(long int lhs, long  int rhs)
{
	fraction temp;

	if (0 == lhs * rhs)
		return temp;

	if (lhs*rhs < 0)
	{
		lhs = myabs(lhs);
		rhs = myabs(rhs);
		temp.isNegative = -1;
	}

	//化简为整数+分数形式
	temp.i = lhs / rhs;
	lhs %= rhs;

	//如果化简后，分子为0，如12/3化简后为4，则返回
	if (0 == lhs)
		return temp;

	temp.numerator = lhs;
	temp.denominator = rhs;

	//找出最大公约数
	long int t;
	while (rhs%lhs)
	{
		t = rhs;
		rhs = lhs;
		lhs = t % lhs;
	}
	//化为最简形式
	temp.numerator /= lhs;
	temp.denominator /= lhs;

	return temp;
}

void print(fraction& f)
{
	if (f == 0)
	{
		cout << "0";
		return;
	}
	if (f.isNegative == -1)
		cout << "(-";
	if (f.i)
	{
		cout << f.i;
		if (f.numerator)
			cout << " " << f.numerator << "/" << f.denominator;
	}
	else if (f.numerator)
	{
		cout << f.numerator << "/" << f.denominator;
	}
	if (f.isNegative == -1)
		cout << ")";
}

void printop(fraction& f1, fraction& f2, fraction& f3, char o)
{
	print(f1);
	cout << " " << o << " ";
	print(f2);
	cout << " = ";
	print(f3);
	cout << endl;
}

fraction op(long int n1, long int n2, long int n3, long int n4, char o)
{
	fraction temp;
	long int numerator, denominator;
	denominator = n2 * n4;
	switch (o)
	{
	case '+':
		numerator = n1 * n4 + n3 * n2;
		break;
	case '-':
		numerator = n1 * n4 - n3 * n2;
		break;
	case '*':
		numerator = n1 * n3;
		break;
	case '/':
		denominator = n2 * n3;
		numerator = n1 * n4;
		break;
	}
	temp = simply(numerator, denominator);
	return temp;
}

int main()
{
	long int a1, a2, a3, a4;
	fraction f1, f2, f3;
	char c1, c2;
	cin >> a1 >> c1 >> a2 >> a3 >> c2 >> a4;


	f1 = simply(a1, a2);
	f2 = simply(a3, a4);



	a1 = f1.isNegative*(f1.i*f1.denominator + f1.numerator);
	a2 = f1.denominator;

	a3 = f2.isNegative*(f2.i*f2.denominator + f2.numerator);
	a4 = f2.denominator;

	//进行+、-、*、/、运算
	f3 = op(a1, a2, a3, a4, '+');
	printop(f1, f2, f3, '+');
	f3 = op(a1, a2, a3, a4, '-');
	printop(f1, f2, f3, '-');
	f3 = op(a1, a2, a3, a4, '*');
	printop(f1, f2, f3, '*');
	f3 = op(a1, a2, a3, a4, '/');
	if (f2 == 0)
	{
		print(f1);
		cout << " / ";
		print(f2);
		cout << " = Inf" << endl;
	}
	else
		printop(f1, f2, f3, '/');


	return 0;
}
