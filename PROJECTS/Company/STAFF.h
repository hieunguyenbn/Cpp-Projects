#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <string>
using namespace std;
class STAFF
{
	private:
	string name, address, date, position;
	public:
		STAFF();
		void input();
		virtual void salary() = 0; //pure virtual
		void output();
		virtual ~STAFF();
};

#endif
