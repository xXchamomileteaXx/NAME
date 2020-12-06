#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


void gotoxy(int x, int y)
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void koordp1(int* k1)
{
    *k1 += 3;
}
void koordp2(int* k2)
{
    *k2 += 2;
}
void koordm1(int* k1)
{
    *k1 -= 3;
}
void koordm2(int* k2)
{
    *k2 -= 2;
}
void check1(int n, int i)
{

    if (i % 3 == 0 && i != 0 && n == 6)
        cout << "\n";
    if (i % 4 == 0 && i != 0 && n == 8)
        cout << "\n";
    if (i % 5 == 0 && i != 0 && n == 10)
        cout << "\n";

};
void check2(int n, int j)
{
    if (j % 3 == 0 && n == 6 && j != 0)
        cout << " ";
    if (j % 4 == 0 && n == 8 && j != 0)
        cout << " ";
    if (j % 5 == 0 && n == 10 && j != 0)
        cout << " ";
}



int main()
{
    
    int const n = 10;// работает для т = 6,8,10
    int a[n][n],buf[n][n];
    int  task;
    int* pa = a[0],*pbuf = buf[0];

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
            buf[i][j] = a[i][j];
        }
    }



    do {

    cout << "Enter number: ";
    cout << "\n\nChoose task\n\n";
    cout << "(1)Fill in a quadratic integer matrix of order n\n";
    cout << "(2)Rearranging blocks of matrix\n";
    cout << "(3)Sort elements\n";
    cout << "(4)Reduces, increases, multiplies, or divides all elements of the matrix\n"; 
    cout << "(0)Exit\n\n";
    cout << "You entered:";
    cin >> task;
    cout << "\n\n";
    switch (task)
    {
    case 1:
        if (task == 1)
        {
            system("cls");
            
            int k1 = 6, k2 = 2;
            int stp = 0;
            int l = 0;
            //спираль
            for (int j = 0; j < n / 2; j++)
            {

                for (int i = 0, *ptr = a[0]; i < n - l; i++, ptr++)
                {
                    koordp1(&k1);
                    gotoxy(k1, k2);
                    Sleep(100);
                    cout << *(ptr + stp) << " ";
                }
                stp += n - l;
                l++;
                for (int i = 0, *ptr = a[0]; i < n - l; i++, ptr++)
                {
                    koordp2(&k2);
                    gotoxy(k1, k2);
                    Sleep(100);
                    cout << *(ptr + stp) << " ";

                }
                stp += n - l;
                for (int i = 0, *ptr = a[0]; i < n - l; i++, ptr++)
                {
                    koordm1(&k1);
                    gotoxy(k1, k2);
                    Sleep(100);
                    cout << *(ptr + stp) << " ";

                }
                stp += n - l;
                l++;
                for (int i = 0, *ptr = a[0]; i < n - l; i++, ptr++)
                {
                    koordm2(&k2);
                    gotoxy(k1, k2);
                    Sleep(100);
                    cout << *(ptr + stp) << " ";

                }
                stp += n - l;

            }

            cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
            system("pause");
            system("cls");
           
            //змейка
            int k_1 = 6, k_2 = 1;
            int st_p = 0;
            for (int j = 0; j < n / 2; j++)
            {

                for (int i = 0, *ptr = a[0]; i < n; i++, ptr++)
                {
                    koordp2(&k_2);
                    gotoxy(k_1, k_2);
                    Sleep(100);
                    cout << *(ptr + st_p) << " ";
                }
                st_p += n;
                k_1 += 3;
                for (int i = 0, *ptr = a[0]; i < n; i++, ptr++)
                {
                    gotoxy(k_1, k_2);
                    koordm2(&k_2);
                    Sleep(100);
                    cout << *(ptr + st_p) << " ";
                }
                st_p += n;
                k_1 += 3;
            }
        }

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        system("pause");
        system("cls");
        break;

    case 2:
        if (task == 2)
        {
            system("cls");
            int  ar[n][n], b1[n / 2][n / 2], b2[n / 2][n / 2], b3[n / 2][n / 2], b4[n / 2][n / 2];
            int* pb1 = b1[0], * pb2 = b2[0], * pb3 = b3[0], * pb4 = b4[0], * pa = a[0], * par = ar[0];

            cout << "Initial matrix:\n\n";
            for (int i = 0; i < n; i++)
            {
                check1(n, i);
                for (int j = 0; j < n; j++)
                {
                    check2(n, j);
                    *(par + i * n + j) = *(pa + i * n + j);
                    cout << *(pa + i * n + j) << " ";
                }

                cout << "\n";
            }

            cout << "\n";

            int c = n / 2;
            for (int i = 0; i < c; i++)
            {
                for (int j = 0; j < n / 2; j++)
                {
                    *(pb1 + i * c + j) = *(pa + i * n + j);
                    *(pb2 + i * c + j) = *(pa + i * n + j + c);
                    *(pb3 + i * c + j) = *(pa + (i + c) * n + j + c);
                    *(pb4 + i * c + j) = *(pa + (i + c) * n + j);
                }
            }


            for (int i = 0; i < c; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    *(pa + i * n + j) = *(pb4 + i * c + j);
                    *(pa + i * n + j + c) = *(pb1 + i * c + j);
                    *(pa + (i + c) * n + j + c) = *(pb2 + i * c + j);
                    *(pa + (i + c) * n + j) = *(pb3 + i * c + j);
                }
            }


            cout << "Scheme a:\n\n";
            for (int i = 0; i < n; i++)
            {
                check1(n, i);
                for (int j = 0; j < n; j++)
                {
                    check2(n, j);
                    cout << *(pa + i * n + j) << " ";
                }
                cout << "\n";
            }

            system("pause");
            system("cls");

            cout << "Initial matrix:\n\n";
            for (int i = 0; i < n; i++)
            {
                check1(n, i);
                for (int j = 0; j < n; j++)
                {
                    check2(n, j);
                    *(pa + i * n + j) = *(par + i * n + j);
                    cout << *(pa + i * n + j) << " ";
                }

                cout << "\n";
            }

            cout << "\n";


            for (int i = 0; i < c; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    *(pa + i * n + j) = *(pb3 + i * c + j);
                    *(pa + (i + c) * n + j + c) = *(pb1 + i * c + j);
                    *(pa + i * n + j + c) = *(pb4 + i * c + j);
                    *(pa + (i + c) * n + j) = *(pb2 + i * c + j);
                }

            }

            cout << "Scheme b:\n\n";
            for (int i = 0; i < n; i++)
            {
                check1(n, i);
                for (int j = 0; j < n; j++)
                {
                    check2(n, j);
                    cout << *(pa + i * n + j) << " ";
                }
                cout << "\n";
            }

            system("pause");
            system("cls");

            cout << "Initial matrix:\n\n";
            for (int i = 0; i < n; i++)
            {
                check1(n, i);
                for (int j = 0; j < n; j++)
                {
                    check2(n, j);
                    *(pa + i * n + j) = *(par + i * n + j);
                    cout << *(pa + i * n + j) << " ";
                }

                cout << "\n";
            }

            cout << "\n";

            for (int i = 0; i < c; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    *(pa + i * n + j) = *(pb4 + i * c + j);
                    *(pa + (i + c) * n + j + c) = *(pb2 + i * c + j);
                    *(pa + i * n + j + c) = *(pb3 + i * c + j);
                    *(pa + (i + c) * n + j) = *(pb1 + i * c + j);
                }

            }

            cout << "Scheme c:\n\n";
            for (int i = 0; i < n; i++)
            {
                check1(n, i);
                for (int j = 0; j < n; j++)
                {
                    check2(n, j);
                    cout << *(pa + i * n + j) << " ";
                }
                cout << "\n";
            }

            system("pause");
            system("cls");

            cout << "Initial matrix:\n\n";
            for (int i = 0; i < n; i++)
            {
                check1(n, i);
                for (int j = 0; j < n; j++)
                {
                    check2(n, j);
                    *(pa + i * n + j) = *(par + i * n + j);
                    cout << *(pa + i * n + j) << " ";
                }

                cout << "\n";
            }

            cout << "\n";

            for (int i = 0; i < c; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    *(pa + i * n + j) = *(pb2 + i * c + j);
                    *(pa + (i + c) * n + j + c) = *(pb4 + i * c + j);
                    *(pa + i * n + j + c) = *(pb1 + i * c + j);
                    *(pa + (i + c) * n + j) = *(pb3 + i * c + j);
                }

            }

            cout << "Scheme d:\n\n";
            for (int i = 0; i < n; i++)
            {
                check1(n, i);
                for (int j = 0; j < n; j++)
                {
                    check2(n, j);
                    cout << *(pa + i * n + j) << " ";
                }
                cout << "\n";
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                *(pa + i * n + j) = *(pbuf + i * n + j);
            }
        }
        cout << "\n";
        system("pause");
        system("cls");
        break;


    case 3:
        if (task == 3)
        {
            system("cls");
            cout << "Unsorted array:\n\n";
            for (int i = 0; i < n * n; i++)
            {
                cout << *(pa + i) << " ";
                if (i != 0 && (i + 1) % n == 0)
                    cout << "\n";
            }
            cout << endl;
            for (int i = 0; i < n * n - 1; i++)
                for (int j = i + 1; j < n * n; j++)
                    if (*(pa + i) > *(pa + j))
                    {
                        int swap = *(pa + i);
                        *(pa + i) = *(pa + j);
                        *(pa + j) = swap;
                    }
            cout << "Sorted array:\n\n";
            for (int i = 0; i < n * n; i++)
            {
                cout << *(pa + i) << " ";
                if (i != 0 && (i + 1) % n == 0)
                    cout << "\n";
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    *(pa + i * n + j) = *(pbuf + i * n + j);
                }
            }

        }
        cout << "\n";
        system("pause");
        system("cls");
        break;


    case 4:
        if (task == 4)
        {
            system("cls");
          
       
            cout << "Initial matrix:\n\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << *(pa + i * n + j) << " ";
                }

                cout << "\n";
            }

            cout << "\n";


            int ch, task_;

            do {
                cout << "\n\nChooce task\n\n";
                cout << "(1)Divide elements\n";
                cout << "(2)Multiply elements\n";
                cout << "(3)Reduce elements\n";
                cout << "(4)Increase elements\n";
                cout << "(0)Exit\n\n";
                
                cout << "\nYou entered:";
                cin >> task_;
                cout << "\n\n";

               switch (task_)
                {
                case 1:
                    cout << "Enter number: ";
                    cin >> ch;
                    cout << "\n";
                    if (ch != 0)
                    {
                        for (int i = 0; i < n; i++)
                        {
                            for (int j = 0; j < n; j++)
                            {
                                *(pa + i * n + j) /= ch;
                                cout << *(pa + i * n + j) << " \t ";
                            }
                            cout << endl;
                        }
                    }
                    else cout << "You can't divide by zero";

                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            *(pa + i * n + j) = *(pbuf + i * n + j);
                        }
                    }

                    cout << "\n";
                    system("pause");
                    system("cls");
                    break;

                case 2:
                    cout << "Enter number: ";
                    cin >> ch;
                    cout << "\n";
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            *(pa + i * n + j) += ch;
                            cout << *(pa + i * n + j) << " \t ";
                        }
                        cout << "\n\n";
                    }

                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            *(pa + i * n + j) = *(pbuf + i * n + j);
                        }
                    }

                    cout << "\n";
                    system("pause");
                    system("cls");
                    break;

                case 3:
                    cout << "Enter number: ";
                    cin >> ch;
                    cout << "\n";
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            *(pa + i * n + j) -= ch;
                            cout << *(pa + i * n + j) << " \t ";
                        }
                        cout << endl;
                    }

                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            *(pa + i * n + j) = *(pbuf + i * n + j);
                        }
                    }

                    cout << "\n";
                    system("pause");
                    system("cls");
                    break;

                case 4:
                    cout << "Enter number: ";
                    cin >> ch;
                    cout << "\n";
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            *(pa + i * n + j) *= ch;
                            cout << *(pa + i * n + j) << " \t ";

                        }
                        cout << endl;
                    }

                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            *(pa + i * n + j) = *(pbuf + i * n + j);
                        }
                    }

                    cout << "\n";
                    system("pause");
                    system("cls");
                    break;
                }
                 
            } while (task_ != 0);
            system("pause");
            system("cls");

            break;
        }
   
    }
    } while (task != 0);
    return 0;
}


