#ifndef SALESMAN_H
#define SALESMAN_H

#include "STAFF.h"

class Salesman : public STAFF
{
	double basic, add, contract, percent, totalSalary;
	public:
		Salesman();
		void input();
		void salary();
		void output();
		~Salesman();
	protected:
};

#endif
