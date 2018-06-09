#include "Salesman.h"
#include "STAFF.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
Salesman::Salesman()
{
	cout << "START SALESMAN" << endl;
	basic = 5000000;
}
void Salesman::input() {
	STAFF::input();
	cout << "Enter total contract value: ";
	cin >> contract;
}
void Salesman::salary() {
	if (contract > 100000000) percent = 0.1;
		else percent = 0.5;
		add = contract*percent;
		totalSalary = basic+add;
	cout << "Total salary = " << setprecision(7) << totalSalary;
	cout << fixed << endl;
}
void Salesman::output() {
	STAFF::output();
	cout << "\nBASIC SALARY: " << basic << "\n";
}
Salesman::~Salesman()
{
	cout << "End showing info of salesman" << endl;
}
