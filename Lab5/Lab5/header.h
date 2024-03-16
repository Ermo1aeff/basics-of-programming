#include <string>
#include <list>
#include <iostream>
#include <Windows.h>

using namespace std;

struct _apartment {
    int rmsNum{};
    int floor{};
    double area{};
    string adress{};
};

extern  list<_apartment> apartments;

_apartment input();

void recicleMenu();