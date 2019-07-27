
#if 0;
/*ϴ����������ʮ�ֳ�����������Ҫдһ������ģ��ϴ�ƵĹ��̡�
������Ҫϴ2n���ƣ����ϵ��������ǵ�1�ţ���2�ţ���3��һֱ����2n�š�
���ȣ����ǰ���2n���Ʒֳ����ѣ��������ŵ�1�ŵ���n�ţ��ϰ�ѣ����������ŵ�n+1�ŵ���2n�ţ��°�ѣ���
���žͿ�ʼϴ�ƵĹ��̣��ȷ������ֵ����һ���ƣ��ٷ������ֵ����һ���ƣ�
���ŷ������ֵĵ����ڶ����ƣ��ٷ������ֵĵ����ڶ����ƣ�ֱ�����������ֵĵ�һ���ơ�
���Ű��ƺϲ������Ϳ����ˡ� ������6���ƣ��ʼ�Ƶ�������1,2,3,4,5,6�����ȷֳ����飬
��������1,2,3����������4,5,6����ϴ�ƹ����а�˳�������6,3,5,2,4,1����
���������ٴκϳ�һ����֮�����ǰ��մ������µ�˳�������ƣ��ͱ��������1,4,2,5,3,6��
���ڸ���һ��ԭʼ���飬������⸱��ϴ��k��֮��������µ����С�
*/
//��һ��һ����T(T �� 100)����ʾ��������������ÿ�����ݣ���һ��������n,k(1 �� n,k �� 100)��
//������һ����2n����a1, a2, ..., a2n(1 �� ai �� 1000000000)����ʾԭʼ������ϵ��µ����С�
//����ÿ�����ݣ����һ�У����յ����С�����֮���ÿո��������Ҫ����ĩ�������Ŀո�
//�������ӣ�
/*
3 3 1
1 2 3 4 5 6
3 2
1 2 3 4 5 6
2 2
1 1 1 1
*/
//�����
/*
1 4 2 5 3 6
1 5 4 3 2 6
1 1 1 1
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> sort(vector<int>& res);
int main() {
	int time;
	int n, k;
	cin >> time;
	while (time) {
		cin >> n >> k;
		vector<int> res(2 * n);
		for (unsigned int i = 0; i < 2 * n; ++i) {
			cin >> res[i];
		}
		while (k) {
			res = sort(res);
			k--;
		}
		for (int i = 0; i < res.size(); i++) {
			if (i != res.size() - 1)
				cout << res[i] << " ";
			else
				cout << res[i];
		}
		cout << endl;
		time--;
	}
	return 0;
}
vector<int> sort(vector<int>& res) {
	int size = res.size();
	int i = size / 2;
	int j = 1;
	vector<int> r;
	while (i) {
		r.push_back(res[size - j]);
		r.push_back(res[(size / 2) - j]);
		j++;
		i--;
	}
	for (int i = 0; i < (r.size() / 2); i++) {
		swap(r[i], r[r.size() - i - 1]);
	}
	return r;
}
#endif

/*

MP3 Player��Ϊ��Ļ��С����ʾ�����б��ʱ��ÿ��ֻ����ʾ���׸������û�Ҫͨ�����¼�����������еĸ�����
Ϊ�˼򻯴�������ÿ��ֻ����ʾ4�׸���������ʼ��λ��Ϊ��1�׸衣

����Ҫʵ��ͨ�����¼����ƹ���ƶ�����������б������߼����£�

��������<=4��ʱ�򣬲���Ҫ��ҳ��ֻ��Ų�����λ�á�

����ڵ�һ�׸�����ʱ����Up�����Ų�����һ�׸�������������һ�׸���ʱ����Down�����Ų����һ�׸�����


*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		cin >> s;
		int cur_head = 1, cur_pos = 0;
		if (n <= 4) {
			for (int i = 0; i < (int)s.size(); i++) {
				if (s[i] == 'U') {
					cur_pos = (cur_pos + n - 1) % n;
				}
				else {
					cur_pos = (cur_pos + 1) % n;
				}
			}
		}
		else {
			for (int i = 0; i < (int)s.size(); i++) {
				if (s[i] == 'U') {
					if (cur_head == 1 && cur_pos == 0) {
						cur_head = n - 3;
						cur_pos = 3;
					}
					else {
						if (cur_pos > 0) {
							cur_pos--;
						}
						else {
							cur_head--;
						}
					}
				}
				else {
					if (cur_head == n - 3 && cur_pos == 3) {
						cur_head = 1;
						cur_pos = 0;
					}
					else {
						if (cur_pos < 3) {
							cur_pos++;
						}
						else {
							cur_head++;
						}
					}
				}
			}
		}
		for (int i = 0; i < min(n, 4); i++) {
			if (i) {
				printf(" ");
			}
			printf("%d", cur_head + i);
		}
		printf("\n%d\n", cur_head + cur_pos);
	}
	return 0;
}
