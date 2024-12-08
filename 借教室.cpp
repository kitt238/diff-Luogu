#include<iostream>
#include<cstring>
#define INF 0x7fffffff
#define int long long		
#define MAXX 1060000
using namespace std;

int n, m;
int r[MAXX],diff[MAXX], d[MAXX], s[MAXX], t[MAXX], a[MAXX];

bool judge(int mid) {
	memcpy(a, diff, sizeof(diff));
	for (int i = 1; i <= mid; i++) {
		a[s[i]] -= d[i];
		a[t[i] + 1] += d[i];
	}
	for (int i = 1; i <= n; i++) {
		r[i] = r[i - 1] + a[i];
		if (r[i] < 0)return 0;
	}
	return 1;
}

int binary(int L, int R) {
	while (L < R) {
		int mid = (L + R) / 2;
		if (judge(mid))L = mid+1;
		else R = mid;
	}
	return L;
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
		diff[i] = r[i] - r[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		cin >> d[i] >> s[i] >> t[i];
	}
	int ans = binary(1, m+1);
	if (ans == m+1) {
		cout << 0;
	}
	else {
		cout << -1 << endl<< ans;
	}
	return 0;
}