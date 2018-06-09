#include <iostream>
using namespace std;
 
class Box
{
   double chieudai;      // Chieu dai cua mot box
   double chieurong;     // Chieu rong cua mot box
   double chieucao;      // Chieu cao cua mot box
public:
 
   double tinhTheTich(void)
   {
      return chieudai * chieurong * chieucao;
   }
   void setChieuDai( double dai )
   {
       chieudai = dai;
   }
 
   void setChieuRong( double rong )
   {
       chieurong = rong;
   }
 
   void setChieuCao( double cao )
   {
       chieucao = cao;
   }
   // Nap chong toan tu + de cong hai doi tuong Box.
   Box operator+(const Box& b)
   {
      Box box;
      box.chieudai = this->chieudai + b.chieudai;
      box.chieurong = this->chieurong + b.chieurong;
      box.chieucao = this->chieucao + b.chieucao;
      return box;
   }
};
// ham main cua chuong trinh
int main( )
{
   Box Box1;                // Khai bao Box1 la cua kieu Box
   Box Box2;                // Khai bao Box2 la cua kieu Box
   Box Box3;                // Khai bao Box3 la cua kieu Box
   double thetich = 0.0;     // Luu giu the tich cua mot box tai day
 
   // thong tin chi tiet cua box 1 
   Box1.setChieuDai(3.0); 
   Box1.setChieuRong(4.0); 
   Box1.setChieuCao(5.0);
 
   // thong tin chi tiet cua box 2
   Box2.setChieuDai(6.0); 
   Box2.setChieuRong(7.0); 
   Box2.setChieuCao(8.0);
 
   // the tich cua box 1
   thetich = Box1.tinhTheTich();
   cout << "The tich cua Box1 : " << thetich <<endl;
 
   // the tich cua box 2
   thetich = Box2.tinhTheTich();
   cout << "The tich cua Box2 : " << thetich <<endl;
 
   // Cong hai doi tuong:
   Box3 = Box1 + Box2;
 
   // the tich cua box 3
   thetich = Box3.tinhTheTich();
   cout << "The tich cua Box3 : " << thetich <<endl;
 
   return 0;
}
