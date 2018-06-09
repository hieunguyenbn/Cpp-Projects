#include<stdio.h>
#include<string.h>
#define MAX 100
main(){
	char a[MAX];
	int l, i;
	int count;
	int m;
	printf("Nhap vao chuoi: ");
	fflush(stdin);
	gets(a);
	l=strlen(a);
	printf("\nChuoi ban cua nhap la: ");
	puts(a);
	printf("\nChuoi sau khi thay doi : ");
	for(i=0;i<l;i++)
	{
		m=(int)a[i];
		if(i%2==0)
		{
			if(m>=97 && m<=122)
				m-=32;
		}
		else
		{
			if(m>=65 && m<=90)
				m+=32;
		}
		a[i]=(char)m;		
	}
	puts(a);
}
