#include <iostream>
#include <string>
#include <random>

using namespace std;

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

	int arrSize{}; // Инициализация динамического массива

	cout << "Укажите размер массива: ";
	cin >> arrSize;

	int* arr = new int[arrSize]{};

	// Инициализация генератора случайных чисел 
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 9);

	// Заполнение массива случайными значениями от 0 до 9
	for (int* i{ arr }; i != arr + arrSize; i++) {
		*i = dis(gen);
	}

	// Вывод элементов массива
	for (int* i{ arr }; i != arr + arrSize; i++) {
		cout << *i << ' ';
		cout << i << '\n';
	}
	cout << '\n';

	// Вывод адреса минимального элемента массива
	cout << "Адрес минимального элемента массива: " << findMin(arr, arrSize);
}