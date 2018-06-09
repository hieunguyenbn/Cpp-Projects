#include <iostream>
#include <vector>
using namespace std;

// gia su co mot lop VietJack sau.
class VietJack {
   static int i, j;
public:
   // cac smart pointer de hien thi
   void f() const { cout << i++ << endl; }
   void g() const { cout << j++ << endl; }
   void h() const { cout << "--------" << endl; }
};

// phan dinh nghia cac thanh vien Static:
int VietJack::i = 4;
int VietJack::j = 15;

// Trien khai mot container cho lop tren
class VJContainer {
   vector<VietJack*> a;
public:
   void add(VietJack* vj)
   { 
      a.push_back(vj);  // goi phuong thuc chuan cua vector.
   }
   friend class SmartPointer;
};

// trien khai smart pointer de truy cap thanh vien cua lop VietJack.
class SmartPointer {
   VJContainer vc;
   int index;
public:
   SmartPointer(VJContainer& vjc)
   { 
       vc = vjc;
       index = 0;
   }
   // tra ve gia tri de chi phan cuoi cua danh sach:
   bool operator++() // phien ban toan tu ++ (tien to)
   { 
     if(index >= vc.a.size()) return false;
     if(vc.a[++index] == 0) return false;
     return true;
   }
   bool operator++(int) // phien ban toan tu ++ (hau to)
   { 
      return operator++();
   }
   // nap chong operator->
   VietJack* operator->() const 
   {
     if(!vc.a[index])
     {
        cout << "Gia tri 0!!";
        return (VietJack*)0;
     }
     return vc.a[index];
   }
};

int main() {
   const int sz = 5; // so vong lap la 5 (ban thiet lap gia tri khac de xem ket qua)
   VietJack o[sz];
   VJContainer vc;
   for(int i = 0; i < sz; i++)
   {
       vc.add(&o[i]);
   }
   SmartPointer sp(vc); // tao mot iterator
   do {
      sp->f(); // goi smart pointer
      sp->g();
      sp->h();
   } while(sp++);
   return 0;
}
