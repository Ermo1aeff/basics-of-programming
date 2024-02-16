#include <iostream>
#include <string>
#include <random>

using namespace std;

const int arrSize = 10;

int* findMin(int(*arr)[arrSize]) {

	//int arrSize1 = sizeof(arr);
	//int arrSize2 = sizeof(*arr);

	//cout << "\n";
	//cout << arrSize;

	int* minValue = *arr;

	for (int* i{ *arr + 1 }; i != *arr + arrSize; i++) {
		if (minValue > i) minValue = i;
	}

	return minValue;
}

void main() {

	setlocale(LC_ALL, "RUS");

	int arr[arrSize]{};

	//int arrSize1 = sizeof(arr);
	//int arrSize2 = sizeof(*arr);

	// Инициализация генератора случайных чисел 
	random_device rd; // экземпляр класса random_device для ГПСЧ //Если это кто-то будет читать, коментарии могут не соотвествовать действительным операциям
	mt19937 gen(rd()); // задаем генератор по алгоритму mt19937
	uniform_int_distribution<> dis(0, 9); //указываем диапазон генерации

	for (int* i{ arr }; i != arr + arrSize; i++) {
		*i = dis(gen);
	}

	for (int* i{ arr }; i != arr + arrSize; i++) {
		cout << *i << ' ';
	}
	cout << '\n';

	cout << "Адреса элементов массива: \n";
	for (int* i{ arr }; i != arr + arrSize; i++) {
		cout << i << ' ';
	}
	cout << '\n';
	cout << "Адрес минимального элемента массива: " << findMin(&arr);
}