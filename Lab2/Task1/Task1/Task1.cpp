#include <iostream>
#include <string>

using namespace std;

void main(int argc, char* agrv[]) {
	
	setlocale(LC_ALL, "RUS");

	int a = stoi(agrv[1]);
	int b = stoi(agrv[2]);

	int* p1 = &a;
	int* p2 = &b;

	*p1 *= 2;
	
	// Замена адресов переменных местами
	int* p3 = p1;
	p1 = p2;
	p2 = p3;

	cout << *p1 << " ";
	cout << *p2;
}