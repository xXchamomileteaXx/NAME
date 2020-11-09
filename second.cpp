#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


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
    if (begin < right) quicksort(mas, right, begin); // продолжение сортировки элементов слева от опорного
    if (left < endmas) quicksort(mas, endmas, left); // продолжение сортировки элементов справа от опорного

}


int main()
{
    int const n = 100;
    int endmas = n - 1, begin = 0;
    int i, j;
    int mas[n];
    int max, min, maxsort, minsort;
    int buff = 0;
    int count = 0, counting_elements = 0, counting_elements2 = 0;
    int average;
    int a, ind, b, ind2;
    int number, left, right, check, mid, find = 0;
    int temp, swap1, swap2;
    int task;


    // заполнение массива для заданий
    cout << endl << "Not sorted array: " << "\n";

    for (i = 0; i < n; i++)
    {
        mas[i] = rand() % 199 - 99;
        cout << mas[i] << " ";
    }

    cout << "\n";
    cout << "\n";

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
    maxsort = -100;
    for (int i = 99; i > 0; i--) // проверка значений с 99 индекса в обратном направлении
    {
        if (mas[i] > maxsort)
            maxsort = mas[i];
    }
    auto endmaxsort = steady_clock::now();
    auto elepsed_maxsort = duration_cast<nanoseconds>(endmaxsort - startmaxsort);

    // поиск минимума в отсортированном массиве
    auto startminsort = steady_clock::now();

    minsort = 100;
    for (i = 0; i < 100; i++)
    {
        if (mas[i] < minsort)
            minsort = mas[i];
    }

    auto endminsort = steady_clock::now();
    auto elepsed_minsort = duration_cast<nanoseconds>(endminsort - startminsort);


    do
    {

        cout << "\n\n";
        cout << "Enter number of task\n " << endl;
        cout << "(2) Sort the array" << endl;
        cout << "(3) Find the maximum and minimum elements of the array,calculate the time" << endl;
        cout << "(4) Output the average,output indexes and their number" << endl;
        cout << "(5) Output the number of elements that are less than the number a" << endl;
        cout << "(6) Output the number of elements that are more than the number b" << endl;
        cout << "(7) Output information about whether the number entered by the user is in the sorted array using binary search,calculate the time" << endl;
        cout << "(8) Swaps array elements whose indexes are entered by the user,calculate the time" << endl;
        cout << "(0)exit" << endl;
        cout << "\n";

        cout << "You entered: ";


        cin >> task;


        switch (task)
        {

        case 2:

            cout << "\n" << "Sorted array: " << "\n";

            for (i = 0; i < n; i++)
                cout << mas[i] << ' ';
            cout << "\n\n";
            cout << "Elapsed time in nanoseconds: " << elepsed_sort.count() << "\n";
            break;

        case 3:

            cout << "\n";
            cout << "Max: " << max << " \n";
            cout << "Elapsed time in nanoseconds: " << elepsed_max.count() << "\n";
            cout << "Min: " << min << " \n";
            cout << "Elapsed time in nanoseconds: " << elepsed_min.count() << "\n";
            cout << "\n";
            cout << "Sortmax:" << maxsort << " \n";
            cout << "Elapsed time in nanoseconds: " << elepsed_maxsort.count() << "\n";
            cout << "Sortmin: " << minsort << " \n";
            cout << "Elapsed time in nanoseconds: " << elepsed_minsort.count() << "\n";

            break;

        case 4:

            // подсчет среднего значения
            average = min + max;
            average = average / 2;
            cout << "\n";
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
            break;

        case 5:

            //Вывод количества элементов в отсортированном массиве, которые меньше числа a          
            cout << "\n";
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
                cout << "\nQuantity elements: " << counting_elements << "\n";
            }
            else cout << "you entered the smallest element";
           
            counting_elements = 0;
            break;

        case 6:

            //Вывод количества элементов в отсортированном массиве, которые больше числа b         
            cout << "\n";
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
                cout << "\nquantity elements:" << counting_elements2 << "\n";;
            }
            else cout << "you entered the largest element";
            counting_elements2 = 0;
            break;

        case 7:

            if (task == 7)
            {
                // бинарный поиск
                cout << endl << "Enter number: ";
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
                cout << "Elapsed time in nanoseconds: " << elepsed_bin.count() << "\n\n";

                // перебор массива   
                find = 0;
                auto startenumeration = steady_clock::now();
                for (i = 0; i < 100; i++)
                {
                    if (mas[i] == number)
                    {
                        cout << "Number " << number << " " << "with index: " << i;
                        find++;

                    }

                }
                auto endenumeration = steady_clock::now();
                if (find == 0)
                    cout << "No entered number";

                cout << "\n";
                auto elepsed_enumeration = duration_cast<nanoseconds>(endenumeration - startenumeration);
                cout << "Elapsed time in nanoseconds: " << elepsed_enumeration.count() << "\n";
            }
            break;

        case 8:
            if (task == 8)
            {
                cout << "\nEnter first index of the array:";
                cin >> swap1;
                cout << "\nEnter second index of the array:";
                cin >> swap2;
                cout << "\n";

                // обмен значениями через буферную переменную 
                auto startsw = steady_clock::now();

                temp = mas[swap1];
                mas[swap1] = mas[swap2];
                mas[swap2] = temp;


                auto endsw = steady_clock::now();

                cout << "\n";

                cout << "Result:" << "\n";
                for (int i = 0; i < n; i++)
                {
                    cout << mas[i] << " ";
                }
                auto elepsed_sw = duration_cast<nanoseconds>(endsw - startsw);

                cout << "\nElapsed time in nanoseconds: " << elepsed_sw.count() << "\n";
                swap(mas[swap1], mas[swap2]); // для того чтобы пункт можно было выбирать несколько раз
            }
            break;

        case 0:
            break;

        }


    } while (task != 0);
    return 0;
}
