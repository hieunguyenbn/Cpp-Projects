#include <iostream>
using namespace std;

enum ItemTypes
{
	LAPTOP,
	DESKTOP,
	MOBILE,
	NETWORK
};

void showAllLaptop() {

}

void showAllDesktop() {

}

void showAllMobile() {

}

void showAllNetworkItem() {

}

void showProducts(ItemTypes type)	{

	switch (type)
	{
	case LAPTOP:
		showAllLaptop();
		break;

	case DESKTOP:
		showAllDesktop();
		break;

	case MOBILE:
		showAllMobile();
		break;

	case NETWORK:
		showAllNetworkItem();
		break;

	default:
		break;
	}
}

int main()	{

	ItemTypes type = LAPTOP;
	showProducts(type);

	return 0;
}