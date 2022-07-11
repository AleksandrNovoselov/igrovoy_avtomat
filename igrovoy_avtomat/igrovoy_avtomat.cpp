#include <iostream>
#include <time.h>
#include <windows.h> 
#include <string>

using namespace std;

class Bandit
{
    int _money;
    int a , b , c ;
public:
    Bandit() :_money{ 1000 }, a{ 0 },b{ 0 }, c{ 0 } {}

    void Raund();
    void Print();
    void Priz();
    int getBalans() {
        if (_money < 0)
            return 0;
        return _money;
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
void Bandit::Print()
{
    cout << "Деньги: " << _money << " руб\n";
    cout << "Нaжмите Enter для вращения\n";
        //<< "(для выхода нажми 0)\n";
    getchar();
    //if (n == 0) return;

    Raund();
    Priz();
}
void Bandit::Priz() {
    if (a == b && b == c)
    {
        cout << "\nВы выиграли 100 руб\n";
        _money += 100;
    }
    else if (a == b || b == c)
    {
        cout << "\nВы выиграли 30 руб\n";
        _money += 30;
    }
    else
    {
        cout << "\nВы проиграли 10 руб\n";
        _money -= 10;
    }
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "ru");
    
    Bandit igra;
    do
    {
       igra.Print();
    } while (igra.getBalans());

    cout << "\nДеньги: " << igra.getBalans() << " руб\n";
    cout << "\nДо встречи!!!\n";
}

