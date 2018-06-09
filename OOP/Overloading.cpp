// C++ program for function overloading
#include <bits/stdc++.h>
using namespace std;

class Geeks {
    public:
    	void func(i);
     	void func(double x);
     	void func(int x, int y);
};
template <typename T>
void Geeks::func(int x) {
    cout << "value of x is " << x << endl;
}
      // function with same name but 1 double parameter
void Geeks::func(double x) {
    cout << "value of x is " << x << endl;
} 
// function with same name and 2 int parameters
void Geeks::func(int x, int y) {
    cout << "value of x and y is " << x << ", " << y << endl;
}

int main() {
    
    Geeks obj1;

    obj1.func(7);
    obj1.func(9.132);
    obj1.func(85,64);
    return 0;
} 
