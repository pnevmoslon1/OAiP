#include <iostream>
#include <cmath>
#include <locale.h>
#include <iomanip>

using namespace std;


int deliteli(int i)
{
    int counter = 0;
    for (int del = 2; del < i; del++)
    {
        if ((i % del == 0 && del == 3) || (i % del == 0 && del == 4) || (i % del == 0 && del == 7))
        {
            counter += 1;
        }
    }
    //cout << counter << "\n";
    if (counter == 3)
    {
        return 1;
    }
    else return 0;
}

int main()
{
    setlocale(0, "");
    int num, flag = 0, last = -1;
    cout << "Введите значение N в промежутке от 1 до 1000 включительно: ";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {

        if (deliteli(i))
        {
            for (int j = i + 1; j <= num; j++)
            {
                if (deliteli(j) && i != last)
                {
                    cout << right << setw(8) << i << setw(8) << j << endl;
                    flag = 1;
                    last = j;
                    break;
                }
            }
        }
    }
    if (flag == 0 || num > 1000 ||  num < 1)
    {
        cout << "Данные введены некорректно или подходящих значений на промежутке от 1 до N нет.\n";
    }
}