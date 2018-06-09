//VE TAM GIAC A(300,20); B(100,220); C(500,220) va duong tron ngoai tiep
#include <graphics.h>
//#include <math.h>
int gd = VGA, gm = VGAHI;

int main(int argc, char const *argv[])
{
	initgraph(&gd, &gm, NULL);
	setcolor(GREEN);
	line(300,20,100,220);
	line(100,220,500,220);
	line(500,220,300,20);
	outtextxy(285,15,"A");
	outtextxy(95,220,"B");
	outtextxy(502,220,"C");
	setcolor(RED);
	circle(300,220,200);
	delay(500000);
	closegraph();
	return 0;
}