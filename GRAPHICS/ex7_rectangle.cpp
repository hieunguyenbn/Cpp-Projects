// HCN 
#include <graphics.h>

int gd = VGA, gm = VGAHI;

int main(int argc, char const *argv[])
{
	initgraph(&gd, &gm, NULL);
	setcolor(BLUE);
	rectangle(100,150,220,240);
	setcolor(RED);
	circle(160,195,75);
	delay(500000);
	closegraph();
	return 0;
}