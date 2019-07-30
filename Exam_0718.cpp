
/*
星际战争开展了100年之后，NowCoder终于破译了外星人的密码！他们的密码是一串整数，\
通过一张表里的信息映射成最终4位密码。表的规则是：n对应的值是矩阵X的n次方的左上角，
如果这个数不足4位则用0填充，如果大于4位的则只输出最后4位。

本质是一个斐波那契数列，按照1 2 3 5 8 …这样的数列依次递增，那就可以用递归解决此问题
*/


//递归法
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

//循环法
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


//迭代法
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
数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，因此3 是39 的数根。现在给你一个正整数，输出它的数根。输入描述：输入包含多组数据。每组数据数据包含一个正整数n（1≤n≤10E1000）。
输出描述：对应每一组数据，输出该正整数的数根。
输入：24 39
输出：6 3
*/

#include <iostream>
using namespace std;

int numRoot(int num) {
	int nroot = 0;
	while (num > 0) {
		nroot += num % 10;
		num /= 10;
	}
	//下面这个条件特别容易写错为if,一定要是while，
	//因为这个是递归，return 返回的时候并不一定会退出，只是返回到
	//上一层函数的调用的末尾
	while (nroot > 9) {
		nroot = numRoot(nroot);
	}
	return nroot;
}

int main() {
	std::string origin;
	while (std::cin >> origin) {
		int sum = 0;
		//先将每一位进行相加得到总和，防止数字过大
		//如果数组过大，会浪费大量的时间去计算每一位的数字
		//所以在这里做一个简单的优化
		for (int i = 0; i < origin.length(); i++) {
			sum += origin[i] - '0';
		}
		//对总和求树根
		std::cout << numRoot(sum) << std::endl;
	}
	return 0;
}
