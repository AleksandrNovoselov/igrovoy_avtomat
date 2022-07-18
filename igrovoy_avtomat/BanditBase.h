#pragma once
class Bandit
{
	int _money;
	int a, b, c;
	int* _bet;
public:

	Bandit() :_money{ 1000 }, a{ 0 }, b{ 0 }, c{ 0 }, _bet{ new int } { }
	~Bandit() {
		delete _bet;
	}

	void Raund();
	void game();
	void Priz();

	int getBalans() {
		if (_money < 0)
			return 0;

		return _money;
	}
	int getBet() {
		return *_bet;
	}
};
