#ifndef PHANSO_H
#define PHANSO_H

class PhanSo
{
	int mau;
	int tu;
	public:
		PhanSo();
		void nhap();
		PhanSo operator +( PhanSo & );
		void xuat();
		~PhanSo();
	protected:
};

#endif
