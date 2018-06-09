
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class sv {
    private:
    char *ten,*lop;
    public:
    sv(char *t=NULL,char *l=NULL)
        {
         ten=new char[strlen(t)+1];
         strcpy(ten,t);
         lop=new char[strlen(l)+1];
         strcpy(lop,l);
        }
    ~sv()
        {
         delete ten;
         delete lop;
        }
    void display()
        {
         cout<<"\n\n Ten: "<<ten;
         cout<<"\t Lop: "<<lop;
        }
};
class svtc:public sv {  
    private:
    int hocphi;
    public:
    svtc(char *t=NULL,char *l=NULL,int hp=0):sv(t,l)
        {
         hocphi=hp;
        }
    void display()
        {
         sv::display();
         cout<<"\t Hoc phi: "<<hocphi;
        }
};
class svcn:public svtc {
    private:
    int diemtb,hocbong;
    public:
    svcn(char *t=NULL,char *l=NULL,int hp=0,int dtb=0,int hb=0):svtc(t,l,hp)
        {
         diemtb=dtb;
         hocbong=hb;
        }
    void display()
        {
         svtc::display();
         cout<<"\t Diem TB: "<<diemtb;
         cout<<"\t Hoc bong: "<<hocbong;
        }
    int operator>(svcn &d)
        {
         if(diemtb>d.diemtb)return 1; return 0;
        }
};

int main() {
         int i,j; const n=3;
         char t[10],l[10];
         int hp,hb,dtb;
         svcn *a[n],*tg;
         for(i=0;i<n;i++)
            {
             cout<<"\n Nhap sv thu "<<i+1<<" ";
             cout<<"\n Nhap Ten: ";gets(t);
             cout<<"\n Nhap Lop: ";gets(l);
             cout<<"\n Nhap hoc Phi: ";cin>>hp;
             cout<<"\n Nhap Diem TB: ";cin>>dtb;
             cout<<"\n Nhap hoc Bong: ";cin>>hb;
             a[i]=new svcn(t,l,hp,dtb,hb);
            }
         cout<<"\n\n Thong tin sv truoc khi sap xep: ";
         for(i=0;i<n;i++)
         a[i]->display();
         for(i=0;i<n-1;i++)
         for(j=i+1;j<n;j++)
            if(*a[j]>*a[i])
                {
                 tg=a[i];
                 a[i]=a[j];
                 a[j]=tg;
                }
         cout<<"\n --------------------";
         cout<<"\n\n Thong tin sap xep giam dan theo Diem TB: ";
         for(i=0;i<n;i++)
         a[i]->display();
    return 0;
}