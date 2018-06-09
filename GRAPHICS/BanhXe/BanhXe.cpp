//BANH XE
#include <winbgim.h> 
#include <cmath>
float t = 0.0;
float x, y;
void vebanhxe() {
  int x1, y1, x2, y2;
  circle(x, y,20);

  x1 = x - 20 * cos(t);
  y1 = y - 20 * sin(t);
  x2 = x + 20 * cos(t);
  y2 = y + 20 * sin(t);
  line(x1, y1, x2, y2);

}
int main(int argc, char *argv[])
{
	// now, you can run project
	initwindow(800,400);			// init window graphics
	setbkcolor(1);					// set background
   	cleardevice();
	setcolor(14);					// set text color
	outtextxy(50,100,"NGUYEN SY HIEU");// print text in window graphics
	line(0, 321, getmaxx(), 321);
  	x = 100;
  	y = 300;

  	while (!kbhit()) {
    	setcolor(14);
    	vebanhxe();
    	delay(10);
    	setcolor(1);
    	vebanhxe();
    	t += 0.05;
    	x += 1 ;
    	if (x > getmaxx() + 20)
    	x = 0; 
  	}
  	closegraph();
	//while(!kbhit()) delay(1);		// pause screen	
	return 0;
}
