#include <iostream>
#include <vector>
using namespace std;

int main () {
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(4);
	v.pop_back();
	for (int i = 0; i < 3; i++)
	cout << v[i] << endl;
//	for (vector<int>::iterator i = v.begin(); i < v.end(); ++i) {
//		i -> 
//	}
	return 0;
}
