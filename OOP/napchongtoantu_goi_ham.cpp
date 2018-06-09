#include <iostream>
using namespace std;
 
class KhoangCach
{
   private:
      int met;             
      int centimet;           
   public:
      // phan khai bao cac constructor can thiet
      KhoangCach(){
         met = 0;
         centimet = 0;
      }
      KhoangCach(int m, int c){
         met = m;
         centimet = c;
      }
      // nap chong toan tu goi ham ()
      KhoangCach operator()(int x, int y, int z)
      {
         KhoangCach K;
         // bay gio, dat phep tinh bat ky
         K.met = x + y + 5;
         K.centimet = y - z + 20 ;
         return K;
      }
      // Phuong thuc de hien thi khoang cach
      void hienthiKC()
      {
         cout << "\nDo dai bang m la: " << met <<  "\nVa do dai bang cm la: " <<  centimet << endl;
      }
      
};
int main()
{
   KhoangCach K1(24, 36), K2;

   cout << "Khoang cach dau tien la: "; 
   K1.hienthiKC();

   K2 = K1(15, 15, 15); // trieu hoi toan tu ()
   cout << "\n--------------------------\n"; 
   cout << "Khoang cach thu hai la: "; 
   K2.hienthiKC();

   return 0;
}
