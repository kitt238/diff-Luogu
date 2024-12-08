#include<iostream>
#include<queue>
#include<cmath>
#define INF 0x7fffffff
#define int long long
using namespace std;

int positive=0,negetive=0;
int a[100500], n;
int ans = 0,type=0;

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1)continue;
		int x = a[i] - a[i - 1];
		if (x > 0)positive += x;
		else if (x < 0)negetive += x;
	}
	int remain = abs(positive + negetive);
	ans += remain;
	if (positive && negetive) {
		ans += min(abs(positive), abs(negetive));
	}
	type = 1 + remain;
	cout << ans<<'\n' << type;
	return 0;
}
