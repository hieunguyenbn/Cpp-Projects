// BIEU DIEN 5 GIA TRI NHAP TU BAN PHIM BANG BAR CHART
#include <iostream>
#include <graphics.h>
using namespace std;
int i, a[5], gd = VGA, gm = VGAHI;
int main() {
	cout << "Enter 5 values: ";
	for (i = 0; i < 5; i++) {
		cin >> a[i];
	}
	cout << "Your bar chart: " << endl;
	initgraph(&gd, &gm, NULL);
	setbkcolor(BLUE);
	setlinestyle(SOLID_LINE,0,3);
	setcolor(YELLOW);
	rectangle(0,30,639,450);
	setcolor(WHITE);
	outtextxy(275,10,"BAR CHART");
	setlinestyle(SOLID_LINE,0,2);
	 
	line(100,420,100,60);
	line(100,420,600,420);
	line(90,70,100,60);
	line(110,70,100,60);
	line(590,410,600,420);
	line(590,430,600,420);
	 
	outtextxy(98,45,"Y");
	outtextxy(610,415,"X");
	outtextxy(85,415,"O");
	setcolor(RED);
	bar(150,a[0],200,419);
	setcolor(GREEN);
	bar(225,a[1],275,419); 
	setcolor(BROWN);
	bar(300,a[2],350,419);
	setcolor(BLACK);
	bar(375,a[3],425,419);
	setcolor(YELLOW);
	bar(450,a[4],500,419);

	outtextxy(150,425,"a[0]");
	outtextxy(225,425,"a[1]");
	outtextxy(300,425,"a[2]");
	outtextxy(375,425,"a[3]");
	outtextxy(450,425,"a[4]");
	delay(500000);
	closegraph();
	return 0;
}