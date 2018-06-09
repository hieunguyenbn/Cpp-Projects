#include <bits/stdc++.h>
using namespace std;

int N, M, L, R;
long long a[100009];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	freopen("MULTI.INP", "r", stdin);
	freopen("MULTI.OUT", "w", stdout);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) cin >> a[i];
	for (int j = 1; j <= M; ++j) {
		cin >> L >> R;
	}
	for (int j = 1; j <= M; ++j) {
		if (a[L]*a[R] > 0) cout << "+";
		else if (a[L]*a[R] < 0) cout << "-";
		else cout << "0";
	}
	return 0;
}
