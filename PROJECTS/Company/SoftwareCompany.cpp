#include <iostream>
#include "STAFF.h"
#include "Developer.h"
#include "Salesman.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Developer hieu;
	hieu.input();
	hieu.output();
	hieu.salary();
	Salesman vuong;
	vuong.input();
	vuong.output();
	vuong.salary();
	return 0;
}
