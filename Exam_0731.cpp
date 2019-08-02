#if 0
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	 *  奇数位上都是奇数或者偶数位上都是偶数
	 *  输入：数组arr，长度大于2
	 *  len：arr的长度
	 *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	 */
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0, j = 1;
		while (i < len&&j < len) {
			while ((arr[i] & 1) == 0)i += 2;
			while ((arr[j] & 1) == 1)j += 2;
			if (i < len&&j < len)
				swap(&arr[i], &arr[j]);
		}
	}
	void swap(int *a, int *b)
	{
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}

};
#endif

//每次老猴子的一个桃子是要拿出来的
//4f(n-1)=5f(n)+1-->f(n)=(4/5)^(n-1){f(1)+1}-1
//-->f(1)= 5^(n-1)-1   f(n)=4^(n-1)-1
//-->最初=5^n-4   最后=4^n-4+n
#include<iostream>
#include<stdio.h>
using namespace std;
//数学库的pow函数返回double，大的double加小整数貌似会忽略小整数
//重新写个pow函数
long long int pow1(int a, int b) {
	if (b == 1)
		return a;
	else {
		if (b % 2 == 0)
			return pow1(a, b / 2)*pow1(a, b / 2);
		else
			return pow1(a, b / 2)*pow1(a, b / 2)*a;
	}
}
int main() {
	int n;
	cin >> n;
	while (n) {
		printf("%ld %ld\n", pow1(5, n) - 4, pow1(4, n) + n - 4);
		cin >> n;
	}
	return 0;
}
