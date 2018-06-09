#include "Developer.h"
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
Developer::Developer()
{
	cout << "This is a developer!" << endl;
	basicSalary = 15000000;
}
void Developer::input() {
	STAFF::input();
	cout << "Enter salary ratio: ";
	cin >> ratio;
	cout << "Enter number of working day: ";
	cin >> day;
}
void Developer::salary() {
		if (day >= 24) bonus = 500000;
		else bonus = 300000;
		total = ratio*basicSalary+bonus;
		cout << "TOTAL SALARY: " <<  setprecision(8) << total << "\n";
		cout << fixed;
}
void Developer::output() {
	STAFF::output();
	cout << "BASIC SALARY: " <<  setprecision(4) << basicSalary << "\n";
	cout << fixed;
}
Developer::~Developer()
{
	cout << "Completing information of developer!" << endl;
}
