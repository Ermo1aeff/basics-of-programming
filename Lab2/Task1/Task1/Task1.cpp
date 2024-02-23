#include <iostream>
#include <string>

using namespace std;

void main(int argc, char* agrv[]) {
	
	setlocale(LC_ALL, "RUS");

	int a{};
	int b{};

	cout << "Укажите значение переменной a: ";
	cin >> a;

	cout << "Укажите значение переменной b: ";
	cin >> b;

	int* p1 = &a;
	int* p2 = &b;

	*p1 *= 2;

	int c{};
	int* p3 = &c;

	// Замена адресов переменных местами
	*p3 = *p1;
	*p1 = *p2;
	*p2 = *p3;

	cout << a << " ";
	cout << b;
}