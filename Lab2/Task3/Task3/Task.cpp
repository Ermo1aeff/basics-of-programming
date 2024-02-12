#include <iostream>
#include <string>

using namespace std;

void main(int agrc, char* agrv[]) {

	setlocale(LC_ALL, "RUS");

	int arrCnt;

	cout << "Укажите размер массива: ";
	cin >> arrCnt;

	int* arr{ new int[arrCnt] };

	cout << "Заполнение массива\n";

	for (int* i{ arr }; i <= arr + arrCnt - 1; i++) {
		cout << i - arr + 1 << ") ";
		cin >> *i;
	}

	for (int* i{ arr }; i <= arr + arrCnt - 1; i++) {
		if (*i >= 0) *i = pow(*i, 2);
	}

	for (int* i{ arr }; i <= arr + arrCnt - 1; i++) {
		cout << *i << " ";
	}
}

