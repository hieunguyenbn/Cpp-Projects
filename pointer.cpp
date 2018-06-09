//dynamic allocation in cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void capphat(int *&p, int n);
int* capphat2(int n);
void capphat3(int **p, int n);

int main(void) {

	int n, *a = NULL, *b = NULL, *c = NULL;
	cout<<"Enter the size of array: ";
	cin>>n;
	capphat(a,n);
	if (a = NULL) cout<<"NO";
	else cout<<"OK!"<<endl;
	b = capphat2(n);
	if (b = NULL) cout<<"NO";
	else cout<<"OK!"<<endl;
	capphat3(&c,n);
	if (c = NULL) cout<<"NO";//nullptr
	else cout<<"OK!"<<endl;
	delete a;
	delete []b;
	delete []c;
	int x1 = 10, x2 = 20;
	int *const p1 = &x1;//constant pointer;
	//p1 = &x2;//error
	*p1 = 15;//ok
	cout<<x1<<endl;
	int y1 = 30, y2 = 40;
	cout<<&y1<<" "<<&y2<<endl;
	const int *p2 = &y1 ;//pointer to const;
	cout<<p2<<endl;
	p2 = &y2;//ok
	//*p2 = 35;.//error
	cout<<p2<<endl;
	int z1 = 50;
	const int *const p3 = &z1;
	cout<<*p3<<endl;
	return 0;
}
void capphat(int *&p, int n) {
	p = (int *)malloc(n*sizeof(int));	
}
int* capphat2(int n) {
	int *p = new int[n];
}
void capphat3(int **p, int n) {
	*p = new int[n];
}
