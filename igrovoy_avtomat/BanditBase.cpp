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
	cout << "������: " << _money << " ���\n"
		<< "���� ������ (��� ������ ����� 0): ";

	cin >> *_bet;

	if (*_bet > _money)
	{
		cout << "������������ �������!\n";
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
		cout << "\n�� �������� " << priz << " ���\n";
		_money += priz;
	}
	else if (a == b || b == c || a == c)
	{
		priz = *_bet * 3;
		cout << "\n�� �������� " << priz << " ���\n";
		_money += priz;
	}
	else
	{
		priz = *_bet;
		cout << "\n�� ��������� " << priz << " ���\n";
		_money -= priz;
	}
}