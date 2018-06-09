/* 
graphics in Dev-C++ - nguyenvanquan7826 
*/

//#include <winbgim.h> 
//
//int main(int argc, char *argv[])
//{
//	// now, you can run project
//	initwindow(300, 300);			// init window graphics
//	setbkcolor(1);					// set background
//   	cleardevice();
//	setcolor(14);					// set text color
//	outtextxy(50,100,"NGUYEN SY HIEU");// print text in window graphics
//	
//	while(!kbhit()) delay(1);		// pause screen	
//	return 0;
//}
//#include <graphics.h>
//
//int main( )
//{
//    initwindow(400, 400, "HIEU NGUYEN");
//    setbkcolor(1);
//    	cleardevice();
//    setcolor(14);
//    outtextxy(170,180,"NGUYEN SY HIEU");
//    circle(200, 200, 100);
//    while (!kbhit( ))
//    {
//        delay(200);
//    }
//
//    return 0;
//}
#include <winbgim.h>
#include <stdio.h>
#include <string.h>
 
int main(){
    setbkcolor(1);
    int x, y;
    initwindow(800,500);
    setbkcolor(1);
    cleardevice();
    while (1){
        delay(0.0001);
 
        if (ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN, x, y);
            printf("left click : (%d,%d)n", x, y);
        }
 
        if (ismouseclick(WM_LBUTTONUP)){
            getmouseclick(WM_LBUTTONUP, x, y);
            printf("left up click : (%d,%d)n", x, y);
        }
 
        if (ismouseclick(WM_LBUTTONDBLCLK)){
            getmouseclick(WM_LBUTTONDBLCLK, x, y);
            printf("left double click : (%d,%d)n", x, y);
        }
 
        if (ismouseclick(WM_RBUTTONDOWN)){
            getmouseclick(WM_RBUTTONDOWN, x, y);
            printf("right click : (%d,%d)n", x, y);
        }
 
        if (ismouseclick(WM_RBUTTONUP)){
            getmouseclick(WM_RBUTTONUP, x, y);
            printf("right up click : (%d,%d)n", x, y);
        }
 
        if (ismouseclick(WM_RBUTTONDBLCLK)){
            getmouseclick(WM_RBUTTONDBLCLK, x, y);
            printf("right double click : (%d,%d)n", x, y);
        }
        if (ismouseclick(WM_MOUSEMOVE)){
            getmouseclick(WM_MOUSEMOVE, x, y);
            printf("move : (%d,%d)n", x, y);
        }
    }
  
    closegraph();
}
