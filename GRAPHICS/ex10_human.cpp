#include <graphics.h>
#include <string.h>
#include <iostream>
using namespace std;
int gd = DETECT, gm, x, y, i, j;
char c;
int main(int argc, char const *argv[])
{
	
	initgraph(&gd, &gm, NULL); // rong windows DEV C++ su dung lenh initwindow(chieu dai, chieu rong;
	x = getmaxx()/2;
	y = getmaxy()/2;
	setbkcolor(BLUE);
	line(0,y,2*x,y);
	setcolor(BLACK);
	line(0,y,10,y-20);
	line(20,y,10,y-20);
	line(10,y-20,10,y-40);
	line(10,y-40,20,y-18);
	line(10,y-40,0,y-18);
	circle(10,y-41,2);
	setcolor(YELLOW);
	line(2*x,y,2*x-10,y-20);
	line(2*x-10,y-20,2*x-20,y);
	line(2*x-10,y-20,2*x-10,y-40);
	line(2*x-10,y-40,2*x-20,y-18);
	line(2*x-10,y-40,2*x,y-18);
	circle(2*x-10,y-41,2);
	i = 0, j = 2*x;
	cout << "PRESS ANY KEY TO START";
	c = getchar();
	while (i <= getmaxx) {
			i+=2;
			j-=2;
			setcolor(BLACK);
			line(i+10,y-20,i,y);
			line(i+10,y-20,i+20,y);
			line(i+10,y-20,i+10,y-40);
			line(i+10,y-40,i+0,y-18);
			line(i+10,y-40,i+20,y-18);
			circle(i+10,y-41,2);
			setcolor(YELLOW);
			line(j-10,y-20,j,y);
			line(j-10,y-20,j-20,y);
			line(j-10,y-20,j-10,y-40);
			line(j-10,y-40,j-20,y-18);
			line(j-10,y-40,j,y-18);
			circle(j-10,y-41,2);
			delay(10);
			i+=2;
			j-=2;
			setcolor(BLACK);
			line(i+10,y-20,i,y);
			line(i+10,y-20,i+20,y);
			line(i+10,y-20,i+10,y-40);
			line(i+10,y-40,i+0,y-18);
			line(i+10,y-40,i+20,y-18);
			circle(i+10,y-41,2);
			setcolor(YELLOW);
			line(j-10,y-20,j,y);
			line(j-10,y-20,j-20,y);
			line(j-10,y-20,j-10,y-40);
			line(j-10,y-40,j-20,y-18);
			line(j-10,y-40,j,y-18);
			circle(j-10,y-41,2);
			delay(200);
		}
		cleardevice();
		if(i == getmaxx() || j == 0) break;
	}

	closegraph();
	return 0;
}