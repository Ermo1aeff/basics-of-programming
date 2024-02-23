#include <iostream>
#include <string>
#include <random>

using namespace std;

bool isAscendOrder(int* arr, int _colCnt) {

	int* lastValue = arr;

	for (int* i{ arr + 1 }; i != arr + _colCnt; i++) {

		if (*lastValue <= *i) *lastValue = *i;
		else return false;
	}
	return true;
}

void main() {

	const int colCnt = 3;
	const int rowCnt = 8;

	int arr[rowCnt][colCnt]{};

	//int arrSize1 = sizeof(arr);
	//int arrSize2 = sizeof(*arr);

	// »нициализаци€ генератора случайных чисел 
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 3);

	for (int* i{ *arr }; i != *arr + rowCnt * colCnt; i++) {
		*i = dis(gen);
	}

	for (int* i{ *arr }; i != *arr + rowCnt * colCnt; i++) {

		cout << *i << ' ';

		if ((i + 1 - *arr) % colCnt == 0) {
			cout << '\n';
		}
	}

	for (int* i{ *arr }; i <= *arr + rowCnt * colCnt - 1; i += colCnt) {

		cout << isAscendOrder(i, colCnt) << '\n';

		if ((i + 1 - *arr) % colCnt == 0) {
			cout << '\n';
		}
	}
}