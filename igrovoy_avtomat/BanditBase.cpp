#include "BanditBase.h"
#include <time.h>
#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

void Bandit::Raund() {
	for (int i = 0; i < 3; i++)
	{
		system("cls");

		a = rand() % 9 + 1;
		cout << a;
		Sleep(200);

		b = rand() % 9 + 1;
		cout << b;
		Sleep(200);

		c = rand() % 9 + 1;
		cout << c;
		Sleep(200);
	}
}

void Bandit::game()
{
	cout << "Деньги: " << _money << " руб\n"
		<< "Ваша ставка (для выхода нажми 0): ";

	cin >> *_bet;

	if (*_bet > _money)
	{
		cout << "Недостаточно средств!\n";
		return;
	}

	Raund();
	Priz();
}
void Bandit::Priz() {
	int priz;
	if (a == b && b == c)
	{
		priz = *_bet * 10;
		cout << "\nВы выиграли " << priz << " руб\n";
		_money += priz;
	}
	else if (a == b || b == c || a == c)
	{
		priz = *_bet * 3;
		cout << "\nВы выиграли " << priz << " руб\n";
		_money += priz;
	}
	else
	{
		priz = *_bet;
		cout << "\nВы проиграли " << priz << " руб\n";
		_money -= priz;
	}
}