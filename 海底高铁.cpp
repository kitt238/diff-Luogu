#include<iostream>
#define INF 0x7fffffff
#define int long long		
#define MAXX 105000
using namespace std;

int n, m;
int city[MAXX];
int a[MAXX], b[MAXX], c[MAXX];
int t1, t2;//������pת��Ϊ����������������ʡ�ڴ�
int sum;

int money(int i) {
	return min(b[i] * city[i] + c[i], a[i] * city[i]);
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> t1;
		if (t1 && t2) {
			city[min(t1, t2)]++;
			city[max(t1, t2)]--;//�������
		}
		t2 = t1;
	}
	for (int i = 1; i <= n-1; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 1; i <= n-1; i++) {
		city[i] += city[i - 1];//�Ѳ��ת��Ϊ��i�����еķ��ʴ���
		sum += money(i);
	}
	cout << sum;
	return 0;
}
