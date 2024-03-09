// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

//struct 

string* split(string str, char spltr)
{
    string* subs = new string[0]{};
    int subsCnt = 0;
    char old = spltr;
    string sub{};
    bool isSub = false;

    for (char item : str)
    {
        if ((old == spltr) && (item != spltr)) {
            sub = "";
            isSub = true;
        }

        if (isSub) 
        {
            if ((item != spltr))
            {
                sub += item;
            } 
            else
            {
                // Расширение массива
                string* tmp = new string[subsCnt + 1];
                memcpy(tmp, subs, subsCnt);
                delete[] subs;
                subs = tmp;

                subs[subsCnt] = sub;

                subsCnt++;
                isSub = false;
            }
        }

        old = item;
    }
    return subs;
}

int main()
{
    setlocale(LC_ALL, "RUS");

    //string s1 = "Hello ";
    //string s2 = "World";
    //string s3 = "!";

    //string* subs = new string[]{s1, s2, s3};
    //cout << *subs;
    //cout << *(subs + 1);
    //cout << *(subs + 2);

    string str;
    char splitter = 0;
    cout << "Введите строку: ";
    std::getline(cin, str);
    cout << "Укажите разделитель: ";
    cin >> noskipws >> splitter;
    string* subs = split(str, splitter);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
