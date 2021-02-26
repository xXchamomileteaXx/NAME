#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

struct Advertising
{
    int watch;
    double pr;
    double money;
};

int main()
{
    Advertising adv_web;
    int n = 0, check = 0;
    cin >> adv_web.watch >> adv_web.pr >> adv_web.money;
    double income = adv_web.watch * (adv_web.pr / 100) * adv_web.money;
    double dub = income * 10;


    if (adv_web.pr < 0 || adv_web.pr > 100 || adv_web.watch < 0 || adv_web.money <= 0 || adv_web.watch > 20)
    {
        cout << "Invalid input";
        check = 1;
    }

    if (income == 0)
    {
        cout << "0.0";
        check = 1;
    }

    if (income > 0 && income < 1)
    {
        while (dub < 1)
        {
            n++;
            dub *= 10;
        }

        if ((int)dub < 5) n++;
        cout << fixed << setprecision(n) << income;
        check = 1;
    }

    if (check == 0)
    {
        cout << round(income * 100.0) / 100.0;
        check = 1;
    }

    return 0;
}