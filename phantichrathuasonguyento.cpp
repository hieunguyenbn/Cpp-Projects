#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int wherex() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.X;
}

int wherey() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}

int main(){
    int n;
    int i=2;
    cout << "nhap so n: ";cin >> n;
    cout << n << " = ";
    while (n>1){
        if (n%i==0){
            cout << i << '.';
            n=n/i;
        }
		else i=i+1;
    }

    gotoxy(wherex()-1, wherey());

    cout << ' ';
}
