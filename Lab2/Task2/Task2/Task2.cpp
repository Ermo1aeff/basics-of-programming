#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* agrv[]) {

	setlocale(LC_ALL, "RUS");

	int arrACnt, arrBCnt;

	cout << "������� ������ ������� �: ";
	cin >> arrACnt;
	
	cout << "������� ������ ������� B: ";
	cin >> arrBCnt;

	int* arrA{ new int[arrACnt] };
	int* arrB{ new int[arrBCnt] };

	cout << "���������� ������� �\n";
	for (int* i = arrA; i != arrA + arrACnt; i++) {
		cout << i - arrA + 1 << ": ";
		cin >> *i;
	}

	cout << "���������� ������� B\n";
	for (int* i = arrB; i != arrB + arrBCnt; i++) {
		cout << i - arrB + 1 << ": ";
		cin >> *i;
	}

	int negNumCnt_A{}, negNumCnt_B{};

	for (int* i = arrA; i != arrA + arrACnt; i++) {
		if (*i < 0) negNumCnt_A++;
	}

	for (int* i = arrB; i != arrB + arrBCnt; i++) {
		if (*i < 0) negNumCnt_B++;
	}

	negNumCnt_A > negNumCnt_B ? cout << "A" : cout << "B";
}