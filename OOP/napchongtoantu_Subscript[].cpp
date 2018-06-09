#include <iostream>
using namespace std;
const int KICHCO = 15;

class ViDuMang
{
   private:
      int mang[KICHCO];
   public:
      ViDuMang() 
      {
         register int i;
         for(i = 0; i < KICHCO; i++)
         {
           mang[i] = i;
         }
      }
      int &operator[](int i)
      {
          if( i > KICHCO )
          {
              cout << "\n======================\n" <<endl;
              cout << "Chi muc vuot gioi han!!" <<endl; 
              // Tra ve phan tu dau tien.
              return mang[0];
          }
          return mang[i];
      }
};
int main()
{
   ViDuMang V;

   cout << "Gia tri cua V[3] la: " << V[3] <<endl;
   cout << "Gia tri cua V[6] la: " << V[6]<<endl;
   cout << "Gia tri cua V[16] la: " << V[16]<<endl;

   return 0;
}
