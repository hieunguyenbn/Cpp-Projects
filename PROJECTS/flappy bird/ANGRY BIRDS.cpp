/*HOANG TRIEU NGU
KTPMK16A
DH CNTT & TT*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <math.h>

#define SIZE 11

int x1 = 62, x2 = x1+12, x3 = x2+12, x4 = x3+12, x5 = x4+12;
bool b1 = false, b2 = false, b3 = false, b4 = false, b5 = false;
int size1, size2, size3, size4, size5;
int xmap, ymap;
int yChim = 18;
int DIEM = 0;
int vanToc = 29*2;
int giaToc;
int vanToc1 = 1;
bool onClick = false, kt = false;
bool ktThua = false;
bool ktTangDiem = false;

void startMenu();
void showLogo();
// Hàm thay ð?i kích c? c?a khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Hàm d?ch chuy?n con tr? ð?n t?a ð? x, y.
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// H�m x�a m�n h�nh.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}


void showMap()
{
	
	system("cls");
	resizeConsole(760,440);
	for (int i=0; i<=30; i++)
	{
		gotoxy(0, i); printf("%c", 178);
		gotoxy(90,i);printf("%c", 178);
	}
	for(int i=0; i<=20;i++)
	{
		gotoxy(65,i+10);printf("%c", 178);	
	}
	for (int i=0; i<=90; i++)
	{
		gotoxy(i, 0); printf("%c", 178);
		gotoxy(i, 10); printf("%c", 178);
		gotoxy(i, 30); printf("%c", 178);
		
	}
}


void inChar(int x, int y, int s, int color)
{
	textcolor(color);
	gotoxy(x, y);
	printf("%c", s);
	textcolor(7);
}
void veChim(int y)
{
	inChar(10, y, 254, 10);
	gotoxy(0,0);
}

void veOngNuocTren(int x, int size)
{
	textcolor(16);
	ktTangDiem = false;
	for(int j = 0; j < 3; j++)
	for(int  i= 11; i<= 11+size; i++)
	{
		if(i+j-1 == yChim && x == 10)
		{
			ktThua = true;
		}
		if(i+j-1 != yChim && x == 10)
		{
			ktTangDiem = true;
		}
		gotoxy(x+j, i);
		printf("%c", 32);
	}
	if(ktTangDiem)
	{
		DIEM++;
	}
}
void veOngNuocDuoi(int x, int size)
{
	
	textcolor(16);
	ktTangDiem = false;
	for(int j = 0; j < 3; j++)
	for(int  i = 29; i>=29-size; i--)
	{
		if(i+j-1 == yChim && x == 10)
		{
			ktThua = true;
		}
		if(i+j-1 != yChim && x == 10)
		{
			ktTangDiem == true;
		}
		gotoxy(x+j, i);
		printf("%c", 32);
	}
	if(ktTangDiem)
	{
		DIEM++;
	}
}

void veOngNuoc(int x, int tsize)
{
	int dsize = SIZE-tsize;
	veOngNuocTren(x, tsize);
	veOngNuocDuoi(x, dsize);
	textcolor(7);
}
void xoaOngNuoc(int x)
{
	gotoxy(x, 11);
	printf("%c", 31);
	gotoxy(x, 29);
	printf("%c", 30);
	for(int  y = 12; y < 29; y++)
	{
		gotoxy(x, y);
		printf(" ");
	}
	gotoxy(0, 0);
}

void thua()
{
	
	char esc = 0;
	
	textcolor(122);
	for(int i = 0; i < 4; i++)
	{
		system("color 14");
		Sleep(100);
		system("color 7");		
	}
	showLogo();
	textcolor(12);
	gotoxy(19, 18);
	printf("THUA CUOC, NHAN ESC DE VE MENU");
	gotoxy(0, 0);
	while(esc != 27)
	{
		esc = getch();
	}
	yChim = 18;
	x1 = 62, x2 = x1+12, x3 = x2+12, x4 = x3+12, x5 = x4+12;
	ktThua = false;
	DIEM = 0;
	onClick = false;
	textcolor(7);
	startMenu();
}
void loadGame()
{
	system("cls");
	gotoxy(30,13);  
	for(int i=0; i< 30; i++) printf("%c", 95);
	gotoxy(30,14);  
	for(int i=0; i< 29; i++) printf("%c", 95); printf("%c",177);
	gotoxy(30,14); 	
	for(int i=0; i< 30; i++)
	{
		printf("%c",177);
		Sleep(40);
	}
	XoaManHinh();
}

void veRangCua()
{
	//ve rang cua tren
	for(int i = 1; i < 65; i++)
	{
		gotoxy(i, 11);
		printf("%c", 31);
	}
	//ve rang cua duoi
	for(int i = 1; i < 65; i++)
	{
		gotoxy(i, 29);
		printf("%c", 30);
	}
}



void showOngNuoc()
{
		if(b1 == false)
		{
			size1 = rand()%10 +1;
			b1 = true;
		}
		if(b2 == false)
		{
			size2 = rand()%10 +1;
			b2 = true;
		}
		if(b3 == false)
		{
			size3 = rand()%10 +1;
			b3 = true;
		}
		if(b4 == false)
		{
			size4 = rand()%10 +1;
			b4 = true;	
		}
		if(b5 == false)
		{
			size5 = rand()%10 +1;
			b5 = true;
		}
		if(x1 < 61)
		{
			veOngNuoc(x1, size2);
			Sleep(10);
			xoaOngNuoc(x1+2);
		}
		
		if(x1 == 1)
		{
			b1 = false;
			Sleep(10);
			xoaOngNuoc(x1+2);
			Sleep(10);
			xoaOngNuoc(x1+1);
			Sleep(10);
			xoaOngNuoc(x1);
			x1 = 62;
		}
		x1--;
		
		if(x2 < 61)
		{
			veOngNuoc(x2, size2);
			Sleep(10);
			xoaOngNuoc(x2+2);
		}
		
		

		if(x2 == 1)
		{
			b2 = false;
			Sleep(10);
			xoaOngNuoc(x2+2);
			Sleep(10);
			xoaOngNuoc(x2+1);
			Sleep(10);
			xoaOngNuoc(x2);
			x2 = 62;
		}
		x2--;
		
		if(x3 < 61)
		{
			veOngNuoc(x3, size3);
			Sleep(10);
			xoaOngNuoc(x3+2);
		}
		

		if(x3 == 1)
		{
			b3 = false;
			Sleep(10);
			xoaOngNuoc(x3+2);
			Sleep(10);
			xoaOngNuoc(x3+1);
			Sleep(10);
			xoaOngNuoc(x3);
			x3 = 62;
		}
		x3--;
		
		if(x4 < 61)
		{
			veOngNuoc(x4, size4);
			Sleep(10);
			xoaOngNuoc(x4+2);
		}
		

		if(x4 == 1)
		{
			b4 = false;
			Sleep(10);
			xoaOngNuoc(x4+2);
			Sleep(10);
			xoaOngNuoc(x4+1);
			Sleep(10);
			xoaOngNuoc(x4);
			x4 = 62;
		}
		x4--;
		
		
		if(x5 < 61)
		{
			veOngNuoc(x5, size5);
			Sleep(10);
			xoaOngNuoc(x5+2);
		}
		

		if(x5 == 1)
		{
			b5 = false;
			Sleep(10);
			xoaOngNuoc(x5+2);
			Sleep(10);
			xoaOngNuoc(x5+1);
			Sleep(10);
			xoaOngNuoc(x5);
			x5 = 62;
		}
		x5--;
}
void chimDownNonClick()
{
	if(yChim < 29 && onClick == false)
	{
		if(vanToc1 % 5 == 0 && kt == true)
		{
		kt = false;
		gotoxy(10,yChim);
		printf(" ");
		yChim--;
		veChim(yChim);
		}
		if(vanToc1 % 5 != 0&& kt == false)
		{
		gotoxy(10,yChim);
		printf(" ");
		yChim++;
		veChim(yChim);
		kt = true;
		}
		vanToc1--;	
	}
}
void chimDownOnClick()
{
	if(yChim < 29 && onClick == true)
	{
		gotoxy(10,yChim);
		printf(" ");
		yChim++;
		veChim(yChim);
		vanToc--;
	}
}
void chimDown()
{
	chimDownOnClick();
	chimDownNonClick();
}
void chimUp()
{
	if(yChim > 12)
	{
		gotoxy(10,yChim);
		printf(" ");
		yChim-=4;
		veChim(yChim);
	}
}
void onKey()
{
	char space = 0;
	if(kbhit())
	{
		space = getch();
		if(space == 32)
		{
			onClick = true;
			chimUp();	
		}
		if(space == 'p')
		{
			system("pause");
		}
	}
}


bool sukienVaCham()
{
	
	
	bool kt = false;
	
	
	//kiem tra va cham rang cua
	if(yChim >= 29 || yChim <= 11)
	{
		kt =  true;		
	}
	return kt;
}



////////////////////////
void kiemtraThua()
{
	if(ktThua == true||sukienVaCham())
	{
		thua();
	}
}

void showLogo()
{
	int i = 3;
	FILE *logo = fopen("logo.txt", "rt");
	char text[255];
	while(fgets(text, 255, logo) != NULL)
	{
		textcolor(i+6);
		gotoxy(8, i);
		puts(text);
		Sleep(30);
		i++;
		gotoxy(0,0);
	}
}
void Score()
{
	int i = 25;
	FILE *score = fopen("score.txt", "rt");
	char text[255];
	while(fgets(text, 255, score) != NULL)
	{
		gotoxy(72, i);
		puts(text);
		Sleep(30);
		i++;
	}
}
void showScore()
{
	gotoxy(76, 18);
	printf("%d", DIEM);
	gotoxy(0,0);
}

void StartGame()
{
	loadGame();
	showMap();
	veRangCua();
	veChim(yChim);
	showLogo();
	Score();	
	gotoxy(1,1);	
	while(true)
	{
		showScore();	
		showOngNuoc();
		kiemtraThua();
		chimDown();
		onKey();
	}
}
void OptionMenu()
{
	char temp = 0;
	system("CLS");
	gotoxy(10,10);
	printf("OPTION MENU DANG BAO TRI, ESC DE TRO LAI");
	gotoxy(10, 12);
	while(temp != 27)
	{
		temp = getch();
	}
	startMenu();
}
void startMenu()
{
	int MenuTemp = 2;
	char c = '0';
	resizeConsole(760,440);
	system("cls");
	while(c != 13)
	{
		textcolor(10);
	    gotoxy(44,10);
    	printf("%c", 24);
    	gotoxy(44,11);
    	printf("W");

    	gotoxy(44,23);
    	printf("S");
    	gotoxy(44,24);
    	printf("%c", 25);
    	textcolor(7);
    	
		gotoxy(42, 15);
		printf("START");
		gotoxy(41, 17);
		printf("OPTIONS");
		gotoxy(42,19);
		printf("QUIT");
		
		while(c != char(13))
		{
			textcolor(10);
			gotoxy(37, 15 + MenuTemp);
			printf("->");
			gotoxy(50, 15+ MenuTemp);
			printf("<-");
			textcolor(7);
			gotoxy(0,0);
			c = getch();
			gotoxy(37, 15 + MenuTemp);
			printf("  ");
			gotoxy(50, 15+ MenuTemp);
			printf("  ");
			if (c=='s')
        	{
            	if (MenuTemp<4)
            	{
                	MenuTemp+=2;
            	}else{
            		MenuTemp-=4;
            	}
        	}
        	if (c=='w')
        	{
            	if (MenuTemp>0)
            	{
                	MenuTemp-=2;
            	}else{
            		MenuTemp+=4;
            	}
        	}
		}
		switch(MenuTemp)
		{
			case 4:{
				exit(0);
				break;
			}
			case 0:{
				StartGame();
				break;
			}
			case 2:{
				OptionMenu();
				break;
			}
			default:{
				system("cls");
				printf("Loi!\nNhan ESC de thoat");
				char cexit;
				while(cexit != 27)
				{
					cexit = getch();
				}
				exit(0);
			}

		}
	}
}
int main()
{
	startMenu();
	getch();
	return 0;
}
