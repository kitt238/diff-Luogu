#include<iostream>
#define INF 0x7fffffff
#define int long long		
#define NUM_MAX 5005000
using namespace std;

int a[NUM_MAX], diff[NUM_MAX];
int n, p;
int mina = INF;

signed main() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		diff[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= p; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		diff[x] += z;
		diff[y + 1] -= z;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + diff[i];
		mina = min(mina, a[i]);
	}
	cout << mina;
	return 0;
}