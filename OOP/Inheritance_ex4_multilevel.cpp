/*C++ program to demonstrate example of multiple inheritance.*/
#include <iostream>
using namespace std;
 
//Base Class - class A
class A
{
    private:
        int a;
    public:
        void get_a(int val_a){
            a=val_a;
        }
        void put_a(void){
            cout <<"value of a: " << a << endl;
        }
};
 
//Base Class - class B
class B
{
    private:
        int b;
    public:
        void get_b(int val_b){
            b=val_b;
        }
        void put_b(void){
            cout <<"value of b: " << b << endl;
        }
};
 
//Base Class - class C
class C
{
    private:
        int c;
    public:
        void get_c(int val_c){
            c=val_c;
        }
        void put_c(void){
            cout <<"value of c: " << c << endl;
        }
};
 
//multiple inheritance, Derived Class - class final
class final:public A,public B,public C
{
    public:
        void printValues(void)
        {
            //now, we can call member functions of class A,B,C
            put_a();
            put_b();
            put_c();
        }
};
 
int main()
{
    //create object of final (derived class)
    final objFinal;
     
    /*read values of a,b and c - which are the private members
      of class A,B and C respectively using public member functions
      get_a(), get_b() and get_c(), by calling with the object of 
      final class.*/
       
    objFinal.get_a(100);
    objFinal.get_b(200);
    objFinal.get_c(300);
     
    //print all values using final::printValues()
    objFinal.printValues();
     
    return 0;
}
