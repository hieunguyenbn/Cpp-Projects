// VE DO THI HAM SO y = 100*sin(x/4.8) x = [0,60]; d = 0.1
// OXY = GREEN, Sin = White
//HE DIEU HANH LINUX
#include <graphics.h>
#include <math.h>
//#define RADS 0.017453293

int gd = VGA, gm = VGAHI;
double x, y, ym;
char text[2] = "0";
int main(int argc, char const *argv[])
{
	initgraph(&gd, &gm, NULL); // voi WINDOWS: THAY NULL = duong dan toi thu muc chua graphics.h
	setcolor(GREEN);
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	outtextxy(getmaxx()/2,getmaxy()/2,text);
	ym = getmaxy()/2;
	for (x = 0; x <= getmaxx(); x += 0.1) {
		y = 100 * sin(x/4.8);
		putpixel(x,y + ym ,WHITE);
	}
	delay(500000);
	closegraph();
	return 0;
}