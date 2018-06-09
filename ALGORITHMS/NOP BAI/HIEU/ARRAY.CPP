#include <bits/stdc++.h>
using namespace std;

unsigned long long n, arr[10000009], k, a, b; //, maxA = 1;
unsigned int m, j;
int main(int argc, char const *argv[]) {
	
	freopen("ARRAY.INP", "r", stdin);
	freopen("ARRAY.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;

	for (j = 1; j <= m; j++) {
		cin >> a >> b >> k;
		while (a <= b) {
			arr[a] += k;
			if(arr[maxA] < arr[a]) maxA = a;
			a++;
		}
	}
	
	cout << arr[n] << endl;
	return 0;
}
