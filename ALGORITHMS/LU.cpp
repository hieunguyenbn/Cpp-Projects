#include <bits/stdc++.h>
using namespace std;
#define max 4
/*Nhap ma tran he so*/
void NhapMaTran(float A[max][max], int m, int n){
   for(int i = 0; i<m; i++)
   for(int j = 0; j<n; j++) {
      cout<<"a["<<i<<"]["<<j<<"] = ";
      cin>>A[i][j];
   }
}

/*Xuat ma tran*/
void XuatMaTran(float A[max][max], int m, int n) {
   cout<<"\n";
   for(int i=0 ; i<m; i++){
      cout<<endl;
      for(int j=0 ; j<n; j++)
         cout<<A[i][j]<<"\t";
   }
}
/*Xuat nghiem*/
void XuatNghiem(float X[], int n){
   cout<<"\nNghiem cua he PTTT";
   for(int i=0; i<n; i++)
      cout<<"\nx"<<i+1<<"="<<X[i];
}
/*He duong cheo*/
char HeDuongCheo(float A[max][max], float X[max], float B[max], int n ) {
   for(int i = 0; i<n; i++) {
      if (A[i][i] != 0)
         X[i] = B[i]/A[i][i];
      else
         return 0;
   }
   return 1;
}
/*He tam giac duoi*/
char HeTamGiacDuoi (float A[max][max], float X[max], float B[max], int n ) {
   for(int i = 0; i<n; i++) {
      if (A[i][i]!=0) {
         if (i==0)
            X[i] = B[i]/A[i][i];
         else {
            X[i] = B[i];
            for(int j=0; j<i; j++)
               X[i]=X[i]-A[i][j]*X[j];
            X[i] = X[i]/A[i][i];
         }
      }
      else
         return 0;
   }
   return 1;
}
/*He tam giac tren*/
char HeTamGiacTren (float A[max][max], float X[max], float B[max], int n ) {
   for(int i = n-1; i>=0; i--) {
      if (A[i][i]!=0) {
         if (i==n-1)
            X[i] = B[i]/A[i][i];
         else {
            X[i] = B[i];
            for(int j=i+1; j<n; j++)
               X[i]=X[i]-A[i][j]*X[j];
            X[i] = X[i]/A[i][i];
         }
      }
      else
         return 0;
   }
   return 1;
}
/*Phan ra A = LU*/
void PhanRaLU(float A[max][max], float L[max][max], float U[max][max], int n) {
   for(int k =0; k<n; k++) {
      U[k][k] = A[k][k];
      L[k][k] = 1;
      for(int i=k+1; i<n; i++) {
         L[i][k] = A[i][k]/U[k][k];
         U[k][i] = A[k][i];
      }
      for(int i = k+1; i<n; i++)
      for(int j = k+1; j<n; j++)
         A[i][j] = A[i][j]-L[i][k]*U[k][j];
   }
}
/*Giai he phuong trinh tong quat LUX=B*/
void GiaiHePTTT(float A[max][max], float X[max], float B[max], int n) {
   float L[max][max],U[max][max], Y[max];
   PhanRaLU(A,L,U,n);
   HeTamGiacDuoi(L,Y,B,n);
   HeTamGiacTren(U,X,Y,n);
}
/*Chuong trinh chinh*/
int main(){
   int m,n;
   float A[4][4] ={{2,3,1,5},{6,13,5,19},{2,19,10,23},{4,10,11,31}};
   float B[4] = {1,1,1,1};
   float X[4];
   float L[max][max], U[max][max];
   
   GiaiHePTTT(A,X,B,4);
   XuatNghiem(X,4);
   return 0;
}
