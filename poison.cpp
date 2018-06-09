#include <bits/stdc++.h>
#define st first;
#define nd second;
using namespace std;

stack<pii> st;
int n, a[10005], x;
solution {
	st.push(make_pair(a[1],0));
	for (int i=2; i <= n; i++) {
		pii p = st.top();//ben canh a[i]
		if (a[i] > a[i-1]) { //chet
			st.push(make_pair(a[i],1));
		}
		else { //khong lon hon
			if (p.nd==0) st.push(make_pair(a[i],0)); //ben trai ko chet=>>
			else {//ben trai co chet
				int m = p.nd; // so ngay chet cua ben trai  6 8 7
				st.pop(); // loai ra vi so ngay chet cua 7 luon lon hon 8
				while(1) {
					p=st.top();
					if (p.nd==0)
					if (a[i] > p.st)
						st.push(make_pair(a[i],m+1));
						break;
					else {
						if (p.nd == 0) {
							st.push(make_pair(a[i],0));
							break;
						}
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	freopen("POISON.INP","r",stdin);
	freopen("POISON.INP","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	solution();
}
