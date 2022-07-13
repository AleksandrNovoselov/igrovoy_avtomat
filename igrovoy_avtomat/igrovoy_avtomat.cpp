#include <iostream>
#include <time.h>
#include <windows.h> 
#include <string>

using namespace std;

class Bandit
{
    int _money;
    int a, b, c;
    int* _bet;
public:

    Bandit() :_money{ 1000 }, a{ 0 }, b{ 0 }, c{ 0 }, _bet { new int} { }
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
  
    /*cout << "Нaжмите Enter для вращения\n";
    getchar();*/
    //if (_bet == 0) return;

    Raund();
    Priz();
}
void Bandit::Priz() {
    int priz;
    if (a == b && b == c)
    {
        priz = *_bet * 10;
        cout << "\nВы выиграли "<<priz<<" руб\n";
        _money += priz;
    }
    else if (a == b || b == c||a==c)
    {
        priz = *_bet * 3;
        cout << "\nВы выиграли " << priz << " руб\n";
        _money += priz;
    }
    else
    {
        priz = *_bet ;
        cout << "\nВы проиграли " << priz << " руб\n";
        _money -= priz;
    }
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "ru");
    
    Bandit igra;
    do
    {
        igra.game();
    } while (igra.getBalans()&&igra.getBet());

    cout << "\nДеньги: " << igra.getBalans() << " руб\n";
    cout << "\nДо встречи!!!\n";
}

