#include "STAFF.h"
#include <iostream>
#include <string>
using namespace std;
STAFF::STAFF()
{
	cout << "SOFTWARE COMPANY" << endl;
}
void STAFF::input() {
	fflush(stdin);
	cout << "Enter name: ";
	getline(cin,name);
	fflush(stdin);
	cout << "Enter address: ";
	getline(cin,address);
	fflush(stdin);
	cout << "Enter date of birth: ";
	getline(cin,date);
	fflush(stdin);
	cout << "Enter position: ";
	getline(cin,position);
}
void STAFF::output() {
	cout << "Thong Tin Nhan Vien: " << "\n";
	cout << name << "\n";
	cout << address << "\n";
	cout << date << "\n";
	cout << position << endl;
}
STAFF::~STAFF()
{
	cout << "FINISH" << endl;
}
