
#include <graphics.h> 

int main(int argc, char *argv[])
{
	initwindow(640,480);	// init window graphics
	setbkcolor(1);	// set background;
	rectangle(100,100,600,200);
	rectangle(100,100,600,200);
	rectangle(200,200,400,400);
	delay(4000);
	rectangle(100,100,600,200);
	delay(1000);
	cleardevice();
	rectangle(200,200,400,400);
	delay(1000);
	cleardevice();
	delay(2000);
	rectangle(200,200,400,400);
	rectangle(100,100,600,200);
	//setlinestyle(10,4,4);
	//line(50,50,80,80);
	//floodfill(200,200,4);
	system("pause");
	closegraph();
	return 0;
}
