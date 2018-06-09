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

      // nap chong toan tu <
      bool operator <(const KhoangCach& k)
      {
         if(met < k.met)
         {
            return true;
         }
         if(met == k.met && centimet < k.centimet)
         {
            return true;
         }
         return false;
      }
};
int main()
{
   KhoangCach K1(13, 15), K2(17, 46);
 
   if( K1 < K2 )
   {
      cout << "K1 la ngan hon K2 " << endl;
   }
   else
   {
      cout << "K2 la ngan hon K1 " << endl;
   }
   return 0;
}
