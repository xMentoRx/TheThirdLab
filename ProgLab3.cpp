#include <iostream>
#include <Windows.h>

#define N1 6
#define N2 8
#define N3 10
#define kComboSort 1.247

using namespace std;

void fillZero(int* f_matrix, int f_N)
{
    int* f_endMatrix = f_matrix + f_N * f_N - 1;
    for (int* i = f_matrix; i <= f_endMatrix; i++)
        *i = 0;
}

void print(int* f_matrix, int f_N)
{
    int* f_endMatrix = f_matrix + f_N * f_N - 1;
    for (int* i = f_matrix; i <= f_endMatrix; i++)
    {
        cout << '{';
        if (*i < 100)
            cout << ' ';
        if (*i < 10)
            cout << ' ';
        cout << *i << '}';
        if ((i - f_matrix) % f_N == (f_N - 1))
            cout << '\n';
        else
            cout << ' ';
    }
}

void printblocks(int* f_matrix, int f_N)
{
    int* f_endMatrix = f_matrix + f_N * f_N - 1;
    int* f_middleMatrix = f_matrix + (f_N * f_N / 2) - 1;
    for (int* i = f_matrix; i <= f_endMatrix; i++)
    {
        cout << '{';
        if (*i < 100)
            cout << ' ';
        if (*i < 10)
            cout << ' ';
        cout << *i << '}';
        if (i == f_middleMatrix)
        {
            cout << '\n';
            for (int j = 0; j < (f_N / 2) - 1; j++)
                cout << "------";
            cout << "-----|";
            for (int j = 0; j < (f_N / 2) - 1; j++)
                cout << "------";
            cout << "-----\n";
        }
        else if ((i - f_matrix) % f_N == (f_N - 1))
            cout << '\n';
        else if ((i - f_matrix) % f_N == (f_N / 2) - 1)
            cout << '|';
        else
            cout << ' ';
    }
}

void new_matrix(int* f_matrix, int f_N)
{
    int* f_endMatrix = f_matrix + f_N * f_N - 1;
    for (int* i = f_matrix; i <= f_endMatrix; i++)
        *i = rand() % (f_N * f_N) + 1;
}

void fillSpiralMatrix(int* f_matrix, int f_N)
{
    fillZero(f_matrix, f_N);
    print(f_matrix, f_N);
    Sleep(100);
    for (int param = 0; param < f_N / 2; param++)
    {
        int* p1 = f_matrix + param * (f_N + 1);
        int* p2 = f_matrix + (param + 1) * (f_N - 1);
        int* p3 = f_matrix + f_N * f_N - 1 - param * (f_N + 1);
        int* p4 = f_matrix + f_N * (f_N - 1) - param * (f_N - 1);
        for (int* i = p1; i < p2; i++)
        {
            *i = rand() % (f_N * f_N) + 1;
            system("cls");
            print(f_matrix, f_N);
            Sleep(100);
        }
        for (int* i = p2; i < p3; i += f_N)
        {
            *i = rand() % (f_N * f_N) + 1;
            system("cls");
            print(f_matrix, f_N);
            Sleep(100);
        }
        for (int* i = p3; i > p4; i--)
        {
            *i = rand() % (f_N * f_N) + 1;
            system("cls");
            print(f_matrix, f_N);
            Sleep(100);
        }
        for (int* i = p4; i > p1; i -= f_N)
        {
            *i = rand() % (f_N * f_N) + 1;
            system("cls");
            print(f_matrix, f_N);
            Sleep(100);
        }
    }
}

void fillSnakeMatrix(int* f_matrix, int f_N)
{
    fillZero(f_matrix, f_N);
    print(f_matrix, f_N);
    Sleep(100);
    for (int param = 0; param < f_N / 2; param++)
    {
        int* p1 = f_matrix + param * 2;
        int* p2 = f_matrix + f_N * (f_N - 1) + param * 2;
        for (int* i = p1; i <= p2; i += f_N)
        {
            *i = rand() % (f_N * f_N) + 1;
            system("cls");
            print(f_matrix, f_N);
            Sleep(100);
        }
        for (int* i = p2 + 1; i >= p1 + 1; i -= f_N)
        {
            *i = rand() % (f_N * f_N) + 1;
            system("cls");
            print(f_matrix, f_N);
            Sleep(100);
        }
    }
}

void changeSnake(int* f_matrix, int f_N)
{
    for (int param = 0; param < (f_N * f_N / 4); param++)
    {
        int* p1 = f_matrix + (param * 2 / f_N) * f_N + (param % (f_N / 2));
        int* p2 = p1 + (f_N / 2);
        int* p3 = p2 + (f_N / 2) * f_N;
        int* p4 = p3 - (f_N / 2);
        int temp = *p1;
        int temp2 = *p3;
        *p1 = *p4;
        *p3 = *p2;
        *p2 = temp;
        *p4 = temp2;
    }
    cout << "\n\n";
    printblocks(f_matrix, f_N);
}

void changeCross(int* f_matrix, int f_N)
{
    for (int param = 0; param < (f_N * f_N / 4); param++)
    {
        int* p1 = f_matrix + (param * 2 / f_N) * f_N + (param % (f_N / 2));
        int* p2 = p1 + (f_N / 2);
        int* p3 = p2 + (f_N / 2) * f_N;
        int* p4 = p3 - (f_N / 2);
        swap(*p1, *p3);
        swap(*p2, *p4);
    }
    cout << "\n\n";
    printblocks(f_matrix, f_N);
}

void changeVertical(int* f_matrix, int f_N)
{
    for (int param = 0; param < (f_N * f_N / 4); param++)
    {
        int* p1 = f_matrix + (param * 2 / f_N) * f_N + (param % (f_N / 2));
        int* p2 = p1 + (f_N / 2);
        int* p3 = p2 + (f_N / 2) * f_N;
        int* p4 = p3 - (f_N / 2);
        swap(*p1, *p4);
        swap(*p2, *p3);
    }
    cout << "\n\n";
    printblocks(f_matrix, f_N);
}

void changeHorizontal(int* f_matrix, int f_N)
{
    for (int param = 0; param < (f_N * f_N / 4); param++)
    {
        int* p1 = f_matrix + (param * 2 / f_N) * f_N + (param % (f_N / 2));
        int* p2 = p1 + (f_N / 2);
        int* p3 = p2 + (f_N / 2) * f_N;
        int* p4 = p3 - (f_N / 2);
        swap(*p1, *p2);
        swap(*p3, *p4);
    }
    cout << "\n\n";
    printblocks(f_matrix, f_N);
}

void bubbleSort(int* arr, int countElements)
{
    int* f_endArray = arr + countElements - 1;
    for (int* f_i = arr; f_i < f_endArray; f_i++)
    {
        for (int* f_j = arr; f_j < (f_endArray - (f_i - arr)); f_j++)
        {
            if (*(f_j) > *(f_j + 1))
                swap(*(f_j + 1), *f_j);
        }
    }
}

void insertSort(int* arr, int countElements)
{
    int* f_endArray = arr + countElements;
    for (int* f_i = arr + 1; f_i < f_endArray; f_i++)
    {
        int elem = *f_i, pos = f_i - arr;
        for (int* f_j = f_i - 1; f_j >= arr && *f_j > elem; f_j--)
        {
            *(f_j + 1) = *f_j;
            pos--;
        }
        *(arr + pos) = elem;
    }
}

void shakerSort(int* arr, int countElements)
{
    int* first = arr, * last = arr + countElements - 1;
    while (first < last)
    {
        for (int* f_i = first; f_i < last; f_i++)
        {
            if (*f_i > *(f_i + 1))
                swap(*f_i, *(f_i + 1));
        }
        last--;
        for (int* f_i = last; f_i > first; f_i--)
        {
            if (*(f_i - 1) > *f_i)
                swap(*f_i, *(f_i - 1));
        }
        first++;
    }
}

void combSort(int* arr, int temp, int countElements)
{
    int* f_endArray = arr + countElements - 1;
    while (temp >= 1)
    {
        for (int* f_i = arr; f_i + temp <= f_endArray; f_i++)
        {
            if (*f_i > *(f_i + temp))
                swap(*f_i, *(f_i + temp));
        }
        temp /= kComboSort;
    }
}

void quickSort(int* arr, int* begin, int* end)
{
    int* first = begin, * last = end;
    int middle = *(first + ((last - first) / 2));
    while (first < last)
    {
        while (*first < middle)
            first++;
        while (*last > middle)
            last--;
        if (first <= last)
        {
            swap(*first, *last);
            first++;
            last--;
        }
    }
    if (begin < last)
        quickSort(arr, begin, last);
    if (first < end)
        quickSort(arr, first, end);
}

void add(int* f_matrix, int f_N, int f_actNumber)
{
    int* f_endMatrix = f_matrix + f_N * f_N - 1;
    for (int* i = f_matrix; i <= f_endMatrix; i++)
        *i += f_actNumber;
}

void sub(int* f_matrix, int f_N, int f_actNumber)
{
    int* f_endMatrix = f_matrix + f_N * f_N - 1;
    for (int* i = f_matrix; i <= f_endMatrix; i++)
        *i -= f_actNumber;
}

void mult(int* f_matrix, int f_N, int f_actNumber)
{
    int* f_endMatrix = f_matrix + f_N * f_N - 1;
    for (int* i = f_matrix; i <= f_endMatrix; i++)
        *i *= f_actNumber;
}

void div(int* f_matrix, int f_N, int f_actNumber)
{
    int* f_endMatrix = f_matrix + f_N * f_N - 1;
    for (int* i = f_matrix; i <= f_endMatrix; i++)
        *i /= f_actNumber;
}

void idz(int* f_matrix, int f_N)
{
    cout << "\n\n\n";
    for (int param = 1; param < f_N * f_N; param++)
    {
        int* p1 = f_matrix + (param / f_N * f_N) + (param % f_N);
        int* p2 = f_matrix + (param / f_N) + (param % f_N * f_N);
        swap(*p1, *p2);
        if (param % f_N == (f_N - 1))
            param += param / f_N + 1;
        print(f_matrix, f_N);
        cout << "\n\n";
        Sleep(100);
    }
}

void sort(int* sArr, int f_N)
{
    int punktSort;
    cout << "\nWhich sort do you want to use? Choose the number\n"
        << "1 - Bubble\n"
        << "2 - Shaker\n"
        << "3 - Comb\n"
        << "4 - Insert\n"
        << "5 - Quick\n"
        << "0 - Exit in menu\n\n";
    cin >> punktSort;
    cout << '\n';
    switch (punktSort)
    {
    case 1:
        bubbleSort(sArr, f_N * f_N);
        print(sArr, f_N);
        break;
    case 2:
        shakerSort(sArr, f_N * f_N);
        print(sArr, f_N);
        break;
    case 3:
        combSort(sArr, f_N * f_N - 1, f_N * f_N);
        print(sArr, f_N);
        break;
    case 4:
        insertSort(sArr, f_N * f_N);
        print(sArr, f_N);
        break;
    case 5:
        quickSort(sArr, sArr, sArr + f_N * f_N - 1);
        print(sArr, f_N);
        break;
    case 0:
        break;
    default:
        cout << "Error! Repeat, please.";
        system("Pause");
        sort(sArr, f_N);
        break;
    }
}

void action(int* aArr, int f_N)
{
    int punktAction, actNumber;
    cout << "\nInput the number\n";
    cin >> actNumber;
    cout << "\nWhich action do you want to use? Choose the number\n"
        << "1 - Addition\n"
        << "2 - Subtraction\n"
        << "3 - Multiplication\n"
        << "4 - Division\n"
        << "0 - Exit in menu\n\n";
    cin >> punktAction;
    cout << '\n';
    switch (punktAction)
    {
    case 1:
        add(aArr, f_N, actNumber);
        print(aArr, f_N);
        break;
    case 2:
        sub(aArr, f_N, actNumber);
        print(aArr, f_N);
        break;
    case 3:
        mult(aArr, f_N, actNumber);
        print(aArr, f_N);
        break;
    case 4:
        div(aArr, f_N, actNumber);
        print(aArr, f_N);
        break;
    case 0:
        break;
    default:
        cout << "Error! Repeat, please.";
        system("Pause");
        action(aArr, f_N);
        break;
    }
}

void menu(int* mArr, int f_N)
{
    int itemMenu;
    cout << "What operation you want to perform? Enter a number from 1 to 8:\n"
        << "1 - Fill matrix with spiral method\n"
        << "2 - Fill matrix with snake method\n"
        << "3 - Change matrix blocks sequentially\n"
        << "4 - Change matrix blocks crosswise.\n"
        << "5 - Change matrix blocks vertical\n"
        << "6 - Change matrix blocks horizontal\n"
        << "7 - Sort matrix\n"
        << "8 - Make an action with matrix\n"
        << "9 - Make IDZ\n"
        << "0 - Exit\n\n";
    cin >> itemMenu;
    switch (itemMenu)
    {
    case 1:
        system("cls");
        fillSpiralMatrix(mArr, f_N);
        system("Pause");
        system("cls");
        menu(mArr, f_N);
        break;
    case 2:
        system("cls");
        fillSnakeMatrix(mArr, f_N);
        system("Pause");
        system("cls");
        menu(mArr, f_N);
        break;
    case 3:
        system("cls");
        new_matrix(mArr, f_N);
        printblocks(mArr, f_N);
        changeSnake(mArr, f_N);
        system("Pause");
        system("cls");
        menu(mArr, f_N);
        break;
    case 4:
        system("cls");
        new_matrix(mArr, f_N);
        printblocks(mArr, f_N);
        changeCross(mArr, f_N);
        system("Pause");
        system("cls");
        menu(mArr, f_N);
        break;
    case 5:
        system("cls");
        new_matrix(mArr, f_N);
        printblocks(mArr, f_N);
        changeVertical(mArr, f_N);
        system("Pause");
        system("cls");
        menu(mArr, f_N);
        break;
    case 6:
        system("cls");
        new_matrix(mArr, f_N);
        printblocks(mArr, f_N);
        changeHorizontal(mArr, f_N);
        system("Pause");
        system("cls");
        menu(mArr, f_N);
        break;
    case 7:
        system("cls");
        new_matrix(mArr, f_N);
        print(mArr, f_N);
        sort(mArr, f_N);
        system("Pause");
        system("cls");
        menu(mArr, f_N);
        break;
    case 8:
        system("cls");
        new_matrix(mArr, f_N);
        print(mArr, f_N);
        action(mArr, f_N);
        system("Pause");
        system("cls");
        menu(mArr, f_N);
        break;
    case 9:
        system("cls");
        new_matrix(mArr, f_N);
        print(mArr, f_N);
        idz(mArr, f_N);
        system("Pause");
        system("cls");
        menu(mArr, f_N);
        break;
    case 0:
        exit(1);
    default:
        cout << "Error! Repeat, please.";
        system("Pause");
        system("cls");
        menu(mArr, f_N);
        break;
    }
}

int main()
{
    srand(time(NULL));
    int number, matrix1[N1][N1], matrix2[N2][N2], matrix3[N3][N3];
    int* m1 = *matrix1, * m2 = *matrix2, * m3 = *matrix3;
    cout << "Input size of matrix.\n";
    cin >> number;
    switch (number)
    {
    case 6:
        system("cls");
        menu(m1, N1);
        break;
    case 8:
        system("cls");
        menu(m2, N2);
        break;
    case 10:
        system("cls");
        menu(m3, N3);
        break;
    default:
        cout << "Error! Repeat, please.\n";
        system("Pause");
        system("cls");
        main();
        break;
    }
    return 0;
}