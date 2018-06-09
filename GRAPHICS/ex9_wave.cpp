//DAI PHAT SONG
#include <graphics.h>
#include <string.h>

int j, gd = VGA, gm = VGAHI;
double x, y;

int main(int argc, char const *argv[])
{
	char c;
	char text[50] = "Press any key to stop";
	initgraph(&gd, &gm, NULL);
	setbkcolor(LIGHTBLUE);
	x = getmaxx()/2;
	y = getmaxy()/2;
	
	setlinestyle(SOLID_LINE,0,4);
	setcolor(BLACK);
    line(x,y,x-100,y+200);
    line(x,y,x+100,y+200);
    line(x-100,y+200,x+100,y+200);

	while (1) {
		for (j = 0; j < 50; j++) {
		for (int i = 0; i <= getmaxx()/2.75; i += 10) {
			setcolor(i/10);
			circle(x,y,i);
			delay(200);
        }
		cleardevice();
		setcolor(BLACK);
		setlinestyle(SOLID_LINE,0,4);
        line(x,y,x-100,y+200);
        line(x,y,x+100,y+200);
        line(x-100,y+200,x+100,y+200);    
		outtextxy(20,200,text);
		}
   		c = getchar();
   		if (c != '\0') break;
  	}
    
	return 0;
}