#include <bits/stdc++.h>
using namespace std;
int n, x;
int main() {
	ios_base::sync_with_stdio(0);
	freopen("MARBLES.INP", "r", stdin);
	freopen("MARBLES.OUT", "w", stdout);
	stack<int> s;
	stack<int> st;
	st.push(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (t==1) {
			cin >> x;
			s.push(x);
			st.push(max(x,st.top()));
		}
		else if(t==2) {
			st.pop();
			s.pop();
		}
		else cout << st.top() <<endl;
	}
	return 0;
}
