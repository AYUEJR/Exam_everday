
#if 0
//不使用+号，计算两整数的加法
#include<iostream>
using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		if (num2 == 0)
			return num1;
		int sum = num1 ^ num2;
		int carry = (num1&num2) << 1;
		return Add(sum, carry);
	}
};

#endif

#include <iostream>
#include <cmath>
using namespace std;
bool IsTriangle(double a, double b, double c);


int main()
{
	double a, b, c; //定义三个边长的值 


	cout << "请输入三条边的边长:" << endl;
	cin >> a >> b >> c;
	if (IsTriangle(a, b, c))
		cout << "能构成三角形\n";
	else
		cout << "不能构成三角形\n";


}


/*
判断三条边是否能构成三角形 
*/
bool IsTriangle(double a, double b, double c)
{
	bool result;

	//对输入的边长值进行判断，边长如果小于等于0，则不能构成三角形. 
	if (a <= 0 || b <= 0 || c <= 0)
	{
		cout << "三角形的边长不能小于等于0.\n";
		cout << a << "," << b << "," << c;
		result = false;
		return result;
	}

	if ((a + b) > c && (a + c > b) && (b + c) > a)
	{
		result = true;
		cout << "能构成三角形\n";
		if (a == b && b == c)
		{
			cout << "是等边三角形\n";
		}

		else if (a == b || a == c || b == c)
		{
			cout << "是等腰三角形\n";
		}
		else

			cout << "是一般三角形\n";
	}
	else
	{
	result = false;
	cout << "不能构成三角形\n";
	}

	return result;

}
