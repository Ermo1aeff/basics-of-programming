#include <iostream>
#include <sstream>
#include <string.h>
#include <Windows.h>

using namespace std;

struct splitResult 
{
    string** subs = new string * [0] {};
    int subsCnt{};
};

splitResult split(string str, char spltr)
{
    int subsCnt = 0;
    char old = spltr;
    bool isSub = false;

    // Подсчёт количества подстрок
    for (int i = 0; i <= str.size(); i++)
    {
        // Определение начала подстроки
        if ((old == spltr) && (str[i] != spltr)) {
            isSub = true;
        }

        if (isSub)
        {
            if ((str[i] == spltr) || (str[i] == '\0'))
            {
                subsCnt++;
                isSub = false;
            }
        }
        old = str[i];
    }

    splitResult result;
    string** subs = new string * [subsCnt] {};
    string sub{};

    old = spltr;
    int ssCount = 0;

    for (int i = 0; i <= str.size(); i++)
    {
        // Определение начала подстроки
        if ((old == spltr) && (str[i] != spltr)) {
            sub = "";
            isSub = true;
        }

        if (isSub) 
        {
            if ((str[i] != spltr) && (str[i] != '\0'))
            {
                sub += str[i];
            } 
            else
            {
                subs[ssCount] = new string{ sub };
                ssCount++;
                isSub = false;
            }
        }
        old = str[i];
    }

    result.subs = subs;
    result.subsCnt = subsCnt;

    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");
    string str;
    char splitter = 0;

    cout << "Введите строку: ";
    getline(cin, str);

    cout << "Укажите разделитель: ";
    cin >> noskipws >> splitter;

    splitResult result = split(str, splitter);

    for (int i{0}; i < result.subsCnt; i++) {
        cout << i + 1 << ") " << *result.subs[i] << "\n";
    }

    cin.get();
    cin.get();
}
