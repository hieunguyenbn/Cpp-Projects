#include <iostream>
using namespace std;
 
class inDuLieu 
{
   public:
      void hamIn(int i) {
        cout << "In so nguyen: " << i << endl;
      }

      void hamIn(double  f) {
        cout << "In so thuc: " << f << endl;
      }

      void hamIn(char* c) {
        cout << "In ky tu: " << c << endl;
      }
};

int main(void)
{
   inDuLieu idl;
 
   // Goi ham hamIn de in so nguyen
   idl.hamIn(12345);
   // Goi ham hamIn de in so thuc
   idl.hamIn(6677.02);
   // Goi ham hamIn de in ky tu
   idl.hamIn("Day la vi du ve nap chong ham?");
 
   return 0;
}
