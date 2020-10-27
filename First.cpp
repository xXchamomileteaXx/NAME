#include <iostream>
using namespace std;

void taskONE();
void taskTWO(int num, unsigned int bit);
void taskTHREE(int num, unsigned int bit);
void taskFOUR(double ch, unsigned int bit, int mas[]);


int main()
{
    union
    {
        int num;
        float num2;
    };

    union
    {
        double ch;
        int mas[2];
    };

    int task;
    int bit;

    do
    {
        cout << " " << endl;

        cout << "Enter number of task\n " << endl;
        cout << "(1)Display how much memory your computer is allocated for different data types " << endl;
        cout << "(2)Display a binary representation in memory of the integer type " << endl;
        cout << "(3)Display a binary representation in memory of the float type" << endl;
        cout << "(4)Display a binary representation in memory of the double type" << endl;
        cout << "(0)exit" << endl;
        cout << "\n";

        cin >> task;
        cout << " ";

        system("cls");

        switch (task)
        {
        case 1:
            taskONE();
            break;

        case 2:

            cout << "Enter integer number:" << " ";
            cout << " ";

            cin >> num;

            cout << "\n";
            cout << "Enter the number of bit:" << " ";

            cin >> bit;

            cout << "\n";
            cout << "rezult: ";

            taskTWO(num, bit);
            break;

        case 3:

            cout << "Enter float number:" << " ";
            cout << " ";

            cin >> num2;

            cout << "\n";
            cout << "Enter the number of bit:" << " ";

            cin >> bit;

            cout << "\n";
            cout << "rezult: ";

            taskTHREE(num, bit);
            break;

        case 4:

            cout << "Enter double number:" << " ";
            cout << " ";

            cin >> ch;

            cout << "\n";
            cout << "Enter the number of bit:" << " ";

            cin >> bit;

            cout << "\n";
            cout << "rezult: ";

            taskFOUR(ch, bit, mas);

        case 0:
            break;
        }

    } while (task != 0);

    return 0;
}
void taskONE()
{
    cout << "Int:" << " " << sizeof(int) << " " << "bit" << endl;

    cout << "Short int:" << " " << sizeof(short int) << " " << "bit" << endl;

    cout << "Long int:" << " " << sizeof(long int) << " " << "bit" << endl;

    cout << "Short float:" << " " << sizeof(float) << " " << "bit" << endl;

    cout << "Double:" << " " << sizeof(double) << " " << "bit" << endl;

    cout << "Long double:" << " " << sizeof(long double) << " " << "bit" << endl;

    cout << "Char:" << " " << sizeof(char) << " " << "bit" << endl;

    cout << "Bool:" << " " << sizeof(bool) << " " << "bit" << endl;
    cout << "\n";
};

void taskTWO(int num, unsigned int bit)
{
    unsigned int mask = 1 << bit - 1;
    for (int i = 1; i <= bit; i++)
    {
        cout << (num & mask ? '1' : '0');
        num <<= 1;

        if (i % bit - 1 == 0)
        {
            cout << (' ');
        }
    }
    cout << "\n";
}

void taskTHREE(int num, unsigned int bit)
{
    int k = 1, s = 1;
    unsigned int mask = 1 << bit - 1;
    for (int i = 1; i <= bit; i++)
    {

        cout << (num & mask ? '1' : '0');
        num <<= 1;
        if (k == 1)
        {
            if (i % 9 == 0)
            {
                cout << (' ');
                ++k;
            }
        }

        if (s == 1)
        {
            if (i % 1 == 0)
            {
                cout << (' ');
                ++s;
            }
        }

    }
    cout << "\n";
}

void taskFOUR(double ch, unsigned int bit, int mas[])
{

    for (int i = 1; i >= 0; i--)
    {
        for (int j = 31; j >= 0; j--)
        {
            cout << ((mas[i] >> j) & 1);

            if ((i == 1) && (j == 31))
            {
                cout << " ";
            }

            if ((i == 1) && (j == 20))
            {
                cout << " ";
            }

        }
    }
    cout << "\n";
}