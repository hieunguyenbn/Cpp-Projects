//Tam giac noi tiep duong tron, duong tron noi tiep ellipse
#include <graphics.h>
#include <winbgim.h>
int x, y, r;
int main(int argc, char const *argv[])
{
	initwindow(800,500);
	x = getmaxx()/2;
	y = getmaxy()/2;
	setcolor(YELLOW);
	circle(x,y,100);
	setcolor(RED);
	ellipse(x,y,0,360,150,100);
	line(x,y-100,x-100,y);
	line(x-100,y,x+100,y);
	line(x+100,y,x,y-100);
	delay(500000);	
	closegraph();
	return 0;
}
