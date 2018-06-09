#include <winbgim.h> 

int main(int argc, char *argv[])
{
	setbkcolor(3);
	// now, you can run project
	initwindow(640, 480);			// init window graphics
	char text[] = "BAN CO VUA CHUAN QUOC TE - NGUYEN SY HIEU";
	setlinestyle(SOLID_LINE,0,1);
	outtextxy(145,40,text);
	setbkcolor(14);

	for (int i = 135; i <= 450; i += 45)
		for (int j = 60; j <= 419; j += 45) {
			if ((i%2 == 0 && j%2 == 0) || (i%2 != 0 && j%2 != 0)) bar(i,j,i+45,j+45);
			else rectangle(i,j,i+45,j+45);
		}
		
	setcolor(4);
	setlinestyle(SOLID_LINE,0,1);
	rectangle(135,60,495,419);
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}
