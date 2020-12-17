#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <chrono>
#include <string>
#include <fstream>
#include <cstdio>
#include <windows.h>
#include <string.h>
#include <algorithm>
#include <cctype>

using namespace std;
using namespace std::chrono;

// 1 
void taskONE()
{
    cout << "Int:" << " " << sizeof(int) << " " << "bit\n";
    cout << "Short int:" << " " << sizeof(short int) << " " << "bit\n";
    cout << "Long int:" << " " << sizeof(long int) << " " << "bit\n";
    cout << "Short float:" << " " << sizeof(float) << " " << "bit\n";
    cout << "Double:" << " " << sizeof(double) << " " << "bit\n";
    cout << "Long double:" << " " << sizeof(long double) << " " << "bit\n";
    cout << "Char:" << " " << sizeof(char) << " " << "bit\n";
    cout << "Bool:" << " " << sizeof(bool) << " " << "bit\n";
    cout << "\n";
}
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
void taskFOUR(double ch, unsigned int bit, int* mas)
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

// 2
void quicksort(int* mas, int  endmas, int begin)
{
    int mid; // середина
    int left = begin; // левая граница массива,0
    int right = endmas; // правая граница массива,n - 1
    mid = mas[(left + right) / 2];

    while (left < right)
    {
        while (mas[left] < mid) left++; // двигаем границу массива к концу,пока не найдется элемент больше опорного
        while (mas[right] > mid) right--; // двигаем границу массива к началу,пока не найдется элемент меньше опорного
        if (left <= right)
        {
            swap(mas[left], mas[right]); // обмен найдеными элементами
            left++; // для проверки следующих элементов
            right--;
        }

    }
    // продолжение сортировки элементов,если остались неотсортированные
    if (begin < right) quicksort(mas, right, begin);
    if (left < endmas) quicksort(mas, endmas, left);

}

// 3
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


// 4
void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void prob(string& str)
{
    for (int j = 0; j < str.length(); j++)
    {
        if (str[j] == ' ')
        {
            while (str[j + 1] == ' ')
                str.erase(j + 1, 1);
        }
    }
    if (str[0] == ' ')
        str.erase(0, 1);

    if (str[str.length() - 2] == ' ')
        str.erase(str.length() - 2, 1);

}
void edit(string& str)
{
    string strbuf;
    char zn[9] = { ',' , ':' , ';' , '!' , '?' , '-' , '"' };
    strbuf = str;

    cout << "Not edited text: " << strbuf << "\n\n";

    // убирает повторяющиеся пробелы
    for (int j = 0; j < str.length(); j++)
    {
        if (str[j] == ' ')
        {
            while (str[j + 1] == ' ')
                str.erase(j + 1, 1);
        }
    }
    if (str[0] == ' ')
        str.erase(0, 1);

    if (str[str.length() - 2] == ' ')
        str.erase(str.length() - 2, 1);

    // удаляет знаки припинания кроме точек
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (str[i] == zn[j])
            {
                while (str[i + 1] == zn[j])
                    str.erase(i + 1, 1);
            }
        }

    }

    // убирает повторяющиеся точки, кроме <...>
    for (int j = 0; j < str.length(); j++)
    {
        if (str[j] == '.' && str[j + 1] == '.' && str[j + 2] == '.')
        {
            j += 2;
        }
        else
            if (str[j] == '.')
            {
                while (str[j + 1] == '.')
                    str.erase(j + 1, 1);
            }
    }

    // понижение регистра
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }

    cout << "Edited text: " << str;
}
void again(string str)
{
    int pos_3 = 0, chek_ = 0;
    string strfw = str, sf;
    cout << "String: " << str << "\n\n";
    for (int i = 0; i < strfw.length(); i++)
    {

        if (strfw[i] == ' ')
        {
            sf = strfw.substr(0, i);
            strfw.erase(0, ++i);
            i = 0;

            for (int k = 0; k < sf.length(); k++)
            {
                if (sf[k] == sf[0])
                    pos_3++;
            }
            if (pos_3 > 1)
            {
                cout << "\nfound word: ";
                SetColor(14, 0);
                cout << sf << endl;
                chek_++;
                SetColor(7, 0);
            }
            pos_3 = 0;
        }

        if (strfw[i] == '.')
        {
            if (i == strfw.length() - 1)
            {
                sf = strfw.substr(0, i);
                strfw.erase(0, ++i);
                i = 0;

                for (int k = 0; k < sf.length(); k++)
                {
                    if (sf[k] == sf[0])
                        pos_3++;
                }
                if (pos_3 > 1)
                {
                    cout << "\nfound word: ";
                    SetColor(14, 0);
                    cout << sf << endl;
                    chek_++;
                    SetColor(7, 0);
                }
                pos_3 = 0;

            }
        }
    }

    if (chek_ == 0)
        cout << "Rezult: words is not found";
}
void delet(string str)
{

    string serch, str_3;
    int pos_4 = 0;

    cout << "Enter a set of letters and / or numbers: ";
    cin.ignore();
    getline(cin, serch);
    str_3 = str;
    pos_4 = str_3.find(serch);
    while (pos_4 != string::npos)
    {
        str_3.erase(pos_4, serch.length() + 1);
        pos_4 = str_3.find(serch, pos_4 + 1);
    }
    cout << "\nString: " << str;
    cout << "\n\nString after removal: " << str_3 << endl;
}
void serL(string str, string strsbp)
{
    string strp;
    int k = 0; int sl = 0;

    strp = str;

    for (int i = 0; i < strp.length(); i++)
    {
        int j = 0;
        k++;

        while ((j < strsbp.length()) && (strsbp[j] == strp[i + j]))
        {

            j = j + 1;

        }
        if (j == strsbp.length())
        {
            for (int l = sl; l < i; l++)
            {
                cout << strp[l];
                sl++;
            }

            SetColor(14, 0);
            for (int l = sl; l < i + j; l++)
            {
                cout << strp[l];
                sl++;
            }
            SetColor(7, 0);

        }
        else
        {
            for (int l = sl; l < i; l++)
            {
                cout << strp[l];
                sl++;
            }
        }

    }

}
void serKMP(string str, string strsbp)
{
    string strbuf;
    strbuf = str;
    int l = 0, i, j, strlen, strsbplen, chek = 0;
    while (l != -1)
    {

        strlen = str.length();
        strsbplen = strsbp.length();
        int d[550];
        // Вычисление префикс-функции
        i = 0;
        j = -1;
        d[0] = -1;
        while (i < strsbplen - 1)
        {
            while ((j >= 0) && (strsbp[j] != strsbp[i]))
                j = d[j];
            ++i;
            ++j;
            d[i] = (strsbp[i] == strsbp[j]) ? d[j] : j;
        }
        // Поиск строки
        for (i = 0, j = 0; (i <= strlen - 1) && (j <= strsbplen - 1); ++i, ++j)
            while ((j >= 0) && (strsbp[j] != str[i]))
                j = d[j];

        l = (j == strsbplen) ? i - j : -1;

        for (i = 0; i < l; i++)
            cout << str[i];
        SetColor(14, 0);
        for (i = l; i < l + strsbp.length(); i++)
        {
            chek++;
            cout << str[i];
        }
        SetColor(7, 0);
        if (l != -1)
            str.erase(0, l + strsbp.length());
    }
    for (int i = 0; i < str.length() - 1; i++)
        cout << str[i];
}



int main()
{
    int  task;
    do {

        cout << "Choose task\n\n";
        cout << "(1) Work one\n\n";
        cout << "(2) Work two\n\n";
        cout << "(3) Work three\n\n";
        cout << "(4) Work four\n\n";
        cout << "(0) Exit";
        cout << "\n\nYou entered: ";
        cin >> task;
        cout << "\n\n";

        switch (task)
        {
        case 1:
            if (task == 1) // work 1 
            {
                system("cls");
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

                int task_lab1, bit;

                do
                {
                    cout << "Enter number of task\n\n";
                    cout << "(1) Display how much memory your computer is allocated for different data types\n\n";
                    cout << "(2) Display a binary representation in memory of the integer type\n\n";
                    cout << "(3) Display a binary representation in memory of the float type\n\n";
                    cout << "(4) Display a binary representation in memory of the double type\n\n";
                    cout << "(0) Exit\n\n";
                    cout << "You entered:  ";

                    cin >> task_lab1;
                    system("cls");

                    switch (task_lab1)
                    {
                    case 1:
                        taskONE();
                        cout << "\n"; system("pause"); system("cls");
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
                        cout << "\n"; system("pause"); system("cls");
                        break;

                    case 3:

                        cout << "Enter float number:" << "  ";
                        cin >> num2;
                        cout << "\nEnter the number of bit:" << " ";
                        cin >> bit;
                        cout << "\nRezult: ";

                        taskTHREE(num, bit);
                        cout << "\n"; system("pause"); system("cls");
                        break;

                    case 4:

                        cout << "Enter double number:" << "  ";
                        cin >> ch;
                        cout << "\nEnter the number of bit:" << " ";
                        cin >> bit;
                        cout << "\nRezult: ";

                        taskFOUR(ch, bit, mas);
                        cout << "\n"; system("pause"); system("cls");
                    case 0:
                        break;
                    }

                } while (task_lab1 != 0);
            }
            break;

        case 2:
            if (task == 2) // work 2
            {
                system("cls");
                int const n = 100;
                int endmas = n - 1, begin = 0, mas[n], max, min, maxsort, minsort, i, j;
                int buff = 0, count = 0, counting_elements = 0, counting_elements2 = 0;
                int average, a, ind, b, ind2, temp, swap1, swap2, number, left, right, check, mid, find = 0;;
                int task_lab2;

                // заполнение массива для заданий
                for (i = 0; i < n; i++)
                {
                    mas[i] = rand() % 199 - 99;
                }


                // поиск максимума в неотсортированном массиве
                auto startmax = steady_clock::now();

                max = -100;
                for (i = 0; i < 100; i++)
                {

                    if (mas[i] > max)
                        max = mas[i];

                }

                auto endmax = steady_clock::now();
                auto elepsed_max = duration_cast<nanoseconds>(endmax - startmax);

                //поиск минимума в неотсортированном массиве 
                auto startmin = steady_clock::now();

                min = 100;
                for (i = 0; i < 100; i++)
                {
                    if (mas[i] < min)
                        min = mas[i];
                }


                auto endmin = steady_clock::now();
                auto elepsed_min = duration_cast<nanoseconds>(endmin - startmin);

                // сортировка Quick sort   
                auto startsort = steady_clock::now();

                quicksort(mas, endmas, begin);

                auto endsort = steady_clock::now();
                auto elepsed_sort = duration_cast<nanoseconds>(endsort - startsort);

                // поиск максимума в отсортированном массиве
                auto startmaxsort = steady_clock::now();


                maxsort = mas[n - 1];


                auto endmaxsort = steady_clock::now();
                auto elepsed_maxsort = duration_cast<nanoseconds>(endmaxsort - startmaxsort);

                // поиск минимума в отсортированном массиве
                auto startminsort = steady_clock::now();


                minsort = mas[0];


                auto endminsort = steady_clock::now();
                auto elepsed_minsort = duration_cast<nanoseconds>(endminsort - startminsort);


                do
                {
                    system("cls");
                    cout << "Enter number of task\n\n";
                    cout << "(1) Sort the array\n\n";
                    cout << "(2) Find the maximum and minimum elements of the array,calculate the time\n\n";
                    cout << "(3) Output the average,output indexes and their number\n\n";
                    cout << "(4) Output the number of elements that are less than the number a\n\n";
                    cout << "(5) Output the number of elements that are more than the number b\n\n";
                    cout << "(6) Output information about whether the number entered by the user is in the sorted array using binary search,calculate the time\n\n";
                    cout << "(7) Swaps array elements whose indexes are entered by the user,calculate the time\n\n";
                    cout << "(0) Exit\n\n";
                    cout << "\n";

                    cout << "You entered: ";
                    cin >> task_lab2;
                    cout << "\n"; system("cls");

                    switch (task_lab2)
                    {

                    case 1:

                        cout << "Sorted array: \n";

                        for (i = 0; i < n; i++)
                            cout << mas[i] << ' ';

                        cout << "\n\nElapsed time in nanoseconds: " << elepsed_sort.count() << "\n";
                        cout << "\n"; system("pause"); system("cls");
                        break;

                    case 2:

                        cout << "Max: " << max << " \n";
                        cout << "Elapsed time in nanoseconds: " << elepsed_max.count() << "\n";
                        cout << "Min: " << min << " \n";
                        cout << "Elapsed time in nanoseconds: " << elepsed_min.count() << "\n";
                        cout << "\n";
                        cout << "Sortmax:" << maxsort << " \n";
                        cout << "Elapsed time in nanoseconds: " << elepsed_maxsort.count() << "\n";
                        cout << "Sortmin: " << minsort << " \n";
                        cout << "Elapsed time in nanoseconds: " << elepsed_minsort.count() << "\n";
                        cout << "\n"; system("pause"); system("cls");
                        break;

                    case 3:

                        // подсчет среднего значения
                        average = min + max;
                        average = average / 2;
                        cout << "Average: " << average << "\n";
                        cout << "\n";

                        //вывод индексов и их количества
                        for (i = 0; i < n; i++)
                        {
                            if (mas[i] == average)
                            {
                                cout << "Index: " << i << "\n";
                                count++;
                            }

                        }
                        cout << "Quantity of elements: " << count;
                        count = 0;
                        cout << "\n\n"; system("pause"); system("cls");
                        break;

                    case 4:

                        //Вывод количества элементов в отсортированном массиве, которые меньше числа a          
                        cout << "Enter number: ";
                        cin >> a;
                        cout << "\n";

                        for (i = 0; i < n; i++)
                        {
                            if (mas[i] < a) // если число в массиве меньше,то
                            {
                                ind = i;  // в ind записывается индес числа,чтобы понять откуда считать
                            }
                        }

                        if (a != min)
                        {
                            for (i = ind; i >= 0; i--)
                            {
                                cout << mas[i] << " ";
                                counting_elements++; // счетчик для количества элементов массива
                            }
                            cout << "\n\nQuantity elements: " << counting_elements << "\n";
                        }
                        else cout << "\nYou entered the smallest element";

                        counting_elements = 0;
                        cout << "\n"; system("pause"); system("cls");
                        break;

                    case 5:

                        //Вывод количества элементов в отсортированном массиве, которые больше числа b         
                        cout << "Enter number: ";
                        cin >> b;
                        cout << "\n";

                        for (int i = 0; i < n; i++)
                        {
                            if (mas[i] > b)
                            {
                                ind2 = i;
                                break;
                            }
                        }

                        if (b != max)
                        {
                            for (int i = ind2; i < n; i++)
                            {
                                cout << mas[i] << " ";
                                counting_elements2++;
                            }
                            cout << "\n\nQuantity elements:" << counting_elements2 << "\n";;
                        }
                        else cout << "You entered the largest element";
                        counting_elements2 = 0;
                        cout << "\n"; system("pause"); system("cls");
                        break;

                    case 6:
                        if (task_lab2 == 6)
                        {
                            // бинарный поиск
                            cout << "Enter number: ";
                            cin >> number;// число,которое нужно найти
                            left = 0; // левая граница
                            right = n - 1; // правая граница
                            check = 0;
                            cout << "\n";

                            auto startbin = steady_clock::now();
                            while ((left <= right) && (check != 1))
                            {
                                mid = (left + right) / 2; // срединный индекс 

                                if (mas[mid] == number)  //проверка серединного элемента
                                {
                                    check++;
                                    break;
                                }

                                if (mas[mid] > number) right = mid - 1; // какую часть нужно отбросить
                                else left = mid + 1;
                            }
                            auto endbin = steady_clock::now();

                            if (check == 1)
                                cout << "Number " << number << " " << "with index: " << mid;
                            else cout << "No entered number";

                            auto elepsed_bin = duration_cast<nanoseconds>(endbin - startbin);
                            cout << "\n";
                            cout << "Elapsed time in nanoseconds (binary search): " << elepsed_bin.count() << "\n\n";

                            // перебор массива   
                            find = 0;
                            auto startenumeration = steady_clock::now();
                            for (i = 0; i < 100; i++)
                            {
                                if (mas[i] == number)
                                {
                                    cout << "Number " << number << " " << "with index: " << i;
                                    find++;
                                    break;
                                }

                            }
                            auto endenumeration = steady_clock::now();
                            if (find == 0)
                                cout << "No entered number";

                            cout << "\n";
                            auto elepsed_enumeration = duration_cast<nanoseconds>(endenumeration - startenumeration);
                            cout << "Elapsed time in nanoseconds(simpl search): " << elepsed_enumeration.count() << "\n";
                        }
                        cout << "\n"; system("pause"); system("cls");
                        break;

                    case 7:
                        if (task_lab2 == 7)
                        {
                            cout << "Enter first index of the array:";
                            cin >> swap1;
                            cout << "\nEnter second index of the array:";
                            cin >> swap2;

                            // обмен значениями через буферную переменную 
                            auto startsw = steady_clock::now();

                            temp = mas[swap1];
                            mas[swap1] = mas[swap2];
                            mas[swap2] = temp;

                            auto endsw = steady_clock::now();

                            cout << "\nResult:" << "\n";
                            for (int i = 0; i < n; i++)
                            {
                                cout << mas[i] << " ";
                            }
                            auto elepsed_sw = duration_cast<nanoseconds>(endsw - startsw);

                            cout << "\n\nElapsed time in nanoseconds: " << elepsed_sw.count() << "\n";
                            swap(mas[swap1], mas[swap2]); // для того чтобы пункт можно было выбирать несколько раз
                        }
                        cout << "\n"; system("pause"); system("cls");
                        break;
                    }

                } while (task_lab2 != 0);

            }

            break;

        case 3:
            if (task == 3) // work 3
            {
                system("cls");
                int const n = 10;
                int a[n][n], buf[n][n];
                int  task_lab3;
                int* pa = a[0], * pbuf = buf[0];

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
                    cout << "(1) Fill in a quadratic integer matrix of order n\n\n";
                    cout << "(2) Rearranging blocks of matrix\n\n";
                    cout << "(3) Sort elements\n\n";
                    cout << "(4) Reduces, increases, multiplies, or divides all elements of the matrix\n\n";
                    cout << "(0) Exit\n\n";
                    cout << "You entered: ";
                    cin >> task_lab3;
                    cout << "\n\n";system("cls");
                    switch (task_lab3)
                    {
                    case 1:
                        if (task_lab3 == 1)
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

                            cout << "\n\n\n\n\n\n\n\n\n\n\n";
                            cout << "\n"; system("pause"); system("cls");

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
                        cout << "\n"; system("pause"); system("cls");
                        break;

                    case 2:
                        if (task_lab3 == 2)
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

                            cout << "\n"; system("pause"); system("cls");


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

                            cout << "\n"; system("pause"); system("cls");

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

                            cout << "\n"; system("pause"); system("cls");

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
                        cout << "\n"; system("pause"); system("cls");
                        break;


                    case 3:
                        if (task_lab3 == 3)
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
                        cout << "\n"; system("pause"); system("cls");
                        break;


                    case 4:
                        if (task_lab3 == 4)
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

                                cout << "\nYou entered: ";
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
                                    cout << "\n"; system("pause"); system("cls");
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
                                    cout << "\n"; system("pause"); system("cls");

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

                                    cout << "\n"; system("pause"); system("cls");
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

                                    cout << "\n"; system("pause"); system("cls");
                                    break;
                                }

                            } while (task_ != 0);
                            cout << "\n"; system("pause"); system("cls");
                        }

                    }
                } while (task_lab3 != 0);
            }

            break;
        case 4:
            if (task == 4) // work 4
            {
                system("cls");
                string str, strch, strb, strbuf, strbuf_, strsbp;
                string file; ifstream fin;
                int task_lab4, task_1, stch = 0, stch2 = 0;

                cout << "Select 1 to enter through file,2 from the keyboard\n\n" << "You entered: ";
                cin >> task_1;

                if (task_1 == 1)
                {
                begin_1:
                    cout << "\nEnter a file name: ";
                    cin.ignore();
                    getline(cin, file);
                    fin.open(file);

                    if (!fin.is_open())
                    {
                        cout << "\nFile opening error";
                    }
                    else
                    {
                        while (!fin.eof())
                        {
                            str = "";
                            getline(fin, str);
                            cout << "\nstring: " << str << endl;
                        }
                    }
                    fin.close();

                    strbuf = str;
                    prob(str);

                    for (int i = 0; i < str.length(); i++)
                    {
                        if (str[i] != ' ')
                            stch++;
                        if (stch > 10)
                        {
                            stch = 0;
                            cout << "\nWord has more than ten letters,enter again\n\n";
                            system("pause"); system("cls");
                            goto begin_1;
                        }

                        if (str[i] == ' ')
                            stch = 0;
                    }
                    for (int i = 0; i < str.length(); i++)
                    {
                        if (str[i] == ' ')
                            stch2++;
                        if (stch2 > 51)
                        {
                            stch2 = 0;
                            cout << "\nYou entered more than fifty words,enter again\n\n";
                            system("pause"); system("cls");
                            goto begin_1;
                        }
                    }
                    if (str[str.length() - 1] != '.')
                    {
                        cout << "\nThere is no dot at the end of the sentence,enter again\n\n";
                        system("pause"); system("cls");
                        goto begin_1;
                    }
                }
                else
                    if (task_1 == 2)
                    {

                    begin_2:
                        cout << "\nEnter string: ";
                        cin.ignore();
                        getline(cin, str);
                        strbuf = str;
                        prob(str);

                        for (int i = 0; i < str.length(); i++)
                        {
                            if (str[i] != ' ')
                                stch++;
                            if (stch > 10)
                            {
                                stch = 0;
                                cout << "\nWord has more than ten letters,enter again\n\n";
                                system("pause"); system("cls");
                                goto begin_2;
                            }

                            if (str[i] == ' ')
                                stch = 0;
                        }

                        for (int i = 0; i < str.length(); i++)
                        {
                            if (str[i] == ' ')
                                stch2++;
                            if (stch2 > 51)
                            {
                                stch2 = 0;
                                cout << "\nYou entered more than fifty words,enter again\n\n";
                                system("pause"); system("cls");
                                goto begin_2;
                            }
                        }

                        if (str[str.length() - 1] != '.')
                        {
                            cout << "\nThere is no dot at the end of the sentence,enter again\n\n";
                            system("pause"); system("cls");
                            goto begin_2;
                        }
                    }

                system("cls");

                do
                {
                    cout << "Enter number of task\n\n";
                    cout << "(1) Print the edited text\n\n";
                    cout << "(2) Print words in which the first letter of the word occurs in this word again\n\n";
                    cout << "(3) Print the same sequence by removing the specified set of letters and / or numbers from all words\n\n";
                    cout << "(4) Find the substring that was entered by the user in the existing string\n\n";
                    cout << "(0) Exit";
                    cout << "\n\nYou entered: ";

                    cin >> task_lab4;
                    cout << " ";

                    system("cls");

                    switch (task_lab4)
                    {

                    case 1:

                        edit(str);

                        cout << "\n\n";
                        system("pause"); system("cls");
                        break;
                    case 2:

                        again(str);

                        cout << "\n\n";
                        system("pause"); system("cls");
                        break;
                    case 3:

                        delet(str);

                        cout << "\n\n";
                        system("pause"); system("cls");
                        break;
                    case 4:

                        strbuf_ = str;
                        cout << "\nEnter string you want find(found word will be yellow): ";
                        cin.ignore();
                        getline(cin, strsbp);

                        cout << "\nLinear search: ";
                        serL(str, strsbp); cout << ".";

                        cout << "\n\nKNM search: ";
                        serKMP(strbuf_, strsbp); cout << ".";

                        cout << "\n\n";
                        system("pause"); system("cls");
                        break;
                    }

                } while (task_lab4 != 0);
            }
            break;
        }
    } while (task != 0);

    return 0;
}
