#include <iostream>
using namespace std;
 
class KhoangCach
{
   private:
      int met;         
      int centimet;    
   public:
      // khai bao cac constructor
      KhoangCach(){
         met = 0;
         centimet = 0;
      }
      KhoangCach(int m, int c){
         met = m;
         centimet = c;
      }
      // phuong thuc de hien thi khoang cach
      void hienthiKC()
      {
         cout << "Khoang cach bang m la: " << met << endl;
         cout << "Khoang cach bang cm la: " << centimet << endl;
         cout << "\n\n================================\n\n" << endl;
      }
      // nap chong toan tu (-)
      KhoangCach operator- ()  
      {
         met = -met;
         centimet = -centimet;
         return KhoangCach(met, centimet);
      }
};
int main()
{
   KhoangCach K1(20, 6), K2(-6, 15);
 
   -K1;                     // ap dung su phu dinh
   K1.hienthiKC();    // hien thi K1

   -K2;                     // ap dung su phu dinh
   K2.hienthiKC();    // hien thi K2

   return 0;
}
