#include <iostream>
#include "BanditBase.h"

using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");

	Bandit igra;
	do
	{
		igra.game();
	} while (igra.getBalans() && igra.getBet());

	cout << "\nДеньги: " << igra.getBalans() << " руб\n";
	cout << "\nДо встречи!!!\n";
}