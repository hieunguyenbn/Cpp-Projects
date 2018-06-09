#ifndef DEVELOPER_H
#define DEVELOPER_H
#include "STAFF.h"

class Developer : public STAFF
{
	double basicSalary, ratio, bonus, total;
	int day;
	public:
		Developer();
		void input();
		void salary();
		void output();
		~Developer();
};

#endif
