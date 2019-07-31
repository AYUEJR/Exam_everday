#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//实质是斐波那契数问题；f(n)=f(n-1)+f(n-2)
/*
f(n) = f(n-1)+f(n-2)+...+f(1)

	  f(n-1) = f(n-2)+ f(n-3)...+f(1)

两式相减，得到f(n) = 2*f(n-1)
*/
//1.递归法
#if 0
class Solution {
public:
	int jumpFloor(int num) 
	{
		if (num <= 0)
		{
			return 0;
	 }
		else if (num == 1 || num == 2)
		{
			return num;
		}
		else
		{
			//int re =0;
			return jumpFloor(num - 1) + jumpFloor(num - 2);
		}
	}
};

int main()
{
	Solution a;
	a.jumpFloor(9);
	return 0;
}

#endif


/*
小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。

现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。
输入有多组数据。

每组数据包含两个整数n (1≤n≤2^128) 和r (1≤r≤2^128)，分别代表喵的身长和碗的半径。

圆周率使用3.14。
对应每一组数据，如果喵能装进碗里就输出“Yes”；否则输出“No”。
*/

#if 0
class Solution {
public:
	string chick(int n, int r)
	{
		if (100 * n < 2 * 314 * r)
			return "Yes";
		else
			return "No";
	}
};

#endif

