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
      friend ostream &operator<<( ostream &output, 
                                       const KhoangCach &K )
      { 
         output << "\nDo dai bang m la: " << K.met << "\nVa do dai bang cm la: " << K.centimet;
         return output;            
      }

      friend istream &operator>>( istream  &input, KhoangCach &K )
      { 
         input >> K.met >> K.centimet;
         return input;            
      }
};
int main()
{
   KhoangCach K1(23, 14), K2(14, 35), K3;

   cout << "Nhap gia tri cua doi tuong K3: " << endl;
   cin >> K3;
   cout << "Khoang cach dau tien: " << K1 << endl;
   cout << "\n==========================\n" << endl;
   cout << "Khoang cach thu hai: " << K2 << endl;
   cout << "\n==========================\n" << endl;
   cout << "Khoang cach thu ba: " << K3 << endl;


   return 0;
}
