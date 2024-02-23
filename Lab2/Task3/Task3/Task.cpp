#include <iostream>
#include <string>
#include <random>

using namespace std;

void main() {

	setlocale(LC_ALL, "RUS");

	int arrCnt;

	cout << "Укажите размер массива: ";
	cin >> arrCnt;

	int* arr{ new int[arrCnt] };

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(-9, 9);

	for (int* i{ arr }; i <= arr + arrCnt - 1; i++) {
		*i = dis(gen);
	}

	cout << "Исходный массив:\n";
	for (int* i{ arr }; i <= arr + arrCnt - 1; i++) {
		cout << *i << " ";
	}
	cout << "\n";

	for (int* i{ arr }; i <= arr + arrCnt - 1; i++) {
		if (*i >= 0) *i = pow(*i, 2);
	}

	cout << "Результирующий массив\n";
	for (int* i{ arr }; i <= arr + arrCnt - 1; i++) {
		cout << *i << " ";
	}
	cout << "\n";
}

