#include <iostream>
#include <string>
#include <random>

using namespace std;



//int* findMin(int(*arr)[arrSize]) {
//
//	int* minValue = *arr;
//
//	for (int* i{ *arr + 1 }; i != *arr + arrSize; i++) {
//		if (minValue > i) minValue = i;
//	}
//
//	return minValue;
//}

// Функция выполняющая поиск минимального значения
int* findMin(int* arr, int _arrSize) {

	int* minValue = arr;

	for (int* i{ arr + 1 }; i != arr + _arrSize; i++) {
		if (*minValue > *i) minValue = i;
	}

	return minValue;
}

void main() {

	setlocale(LC_ALL, "RUS");

	int arrSize = 10; // Инициализация динамического массива
	int* arr = new int[arrSize]{};

	//cout << arr;

	//int arr[arrSize]{};

	//int arrSize1 = sizeof(arr);
	//int arrSize2 = sizeof(*arr);

	// Инициализация генератора случайных чисел 
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 9);

	// Заполнение массива случайными значениями от 0 до 9
	for (int* i{ arr }; i != arr + arrSize; i++) {
		*i = dis(gen);
	}

	//arr = new int[20];

	// Вывод элементов массива
	for (int* i{ arr }; i != arr + arrSize + arrSize; i++) {
		cout << *i << ' ';
	}
	cout << '\n';

	// Вывод адресов элементов массива
	cout << "Адреса элементов массива: \n";
	for (int* i{ arr }; i != arr + arrSize; i++) {
		cout << i << ' ';
	}
	cout << '\n';

	// Вывод адреса минимального элемента массива
	cout << "Адрес минимального элемента массива: " << findMin(arr, arrSize);
}