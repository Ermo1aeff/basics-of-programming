#include <iostream>
#include <string>

using namespace std;

void main(int argc, char* agrv[]) {
	
	setlocale(LC_ALL, "RUS");

	int a{};
	int b{};

	cout << "������� �������� ���������� a: ";
	cin >> a;

	cout << "������� �������� ���������� b: ";
	cin >> b;

	int* p1 = &a;
	int* p2 = &b;

	*p1 *= 2;

	int c{};
	int* p3 = &c;

	// ������ ������� ���������� �������
	*p3 = *p1;
	*p1 = *p2;
	*p2 = *p3;

	cout << a << " ";
	cout << b;
}