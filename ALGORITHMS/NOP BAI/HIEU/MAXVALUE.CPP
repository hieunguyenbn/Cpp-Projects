#include <bits/stdc++.h>
using namespace std;
int j, T, N, a[100009];
long long S; 
long long tong(int x[], int n);
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	freopen("MAXVALUE.INP", "r", stdin);
	freopen("MAXVALUE.OUT", "w", stdout);
	cin >> T;
	j = 1;
	while (j <= T) {
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> a[i];
		}
		cout << tong(a,N);
		j++;
	}

	return 0;
}
long long tong(int x[], int n) {
	
	if (n == 2) return abs(x[2]-x[1]);
	return abs(x[n] - x[n-1]) + tong(x,n-1);
}
