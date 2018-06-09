// bieu dien 5 gia tri nhap tu ban phim bang bieu do hinh quat
#include <iostream>
#include <graphics.h>
using namespace std;

int i, a[6], gd = VGA, gm = VGAHI;

int main() {
	
	cout << "Enter 5 values: ";
	for (i = 0; i < 5; i++){
		cin >> a[i];
	}
	int x, y;
	initgraph(&gd, &gm, NULL); // Thay NULL = duong dan neu chay tren WINDOWS
	
	x = getmaxx() / 2;//finding centre x-ordinate of screen
    y = getmaxy() / 2;//finding centre y-ordinate of screen
	pieslice(x,y,0,a[0],200);
	setcolor(BLUE);
	pieslice(x,y,a[0],a[1],200);
	setcolor(RED);
	pieslice(x,y,a[1],a[2],200);
	setcolor(GREEN);
	pieslice(x,y,a[2],a[3],200);
	setcolor(YELLOW);
	pieslice(x,y,a[3],a[4],200);
	delay(1000000);
	closegraph();
	return 0;
}