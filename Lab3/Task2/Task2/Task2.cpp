#include <iostream>
#include <string>
#include <random>

using namespace std;

// Проверка строки на порядок элеметров по возрастанию
bool isAscendOrder(int* arr, int _colCnt) {

	int* lastValue = arr;

	for (int* i{ arr + 1 }; i != arr + _colCnt; i++) {

		if (*lastValue < *i) *lastValue = *i;
		else return false;
	}
	return true;
}

void main() {

	setlocale(LC_ALL, "RUS");

	int colCnt{};
	int rowCnt{};

	bool isEqual = false;

	do {
		cout << "Укажите количество столбцов: ";
		cin >> colCnt;

		cout << "Укажите количество строк: ";
		cin >> rowCnt;

		if (colCnt == rowCnt) {
			cout << "Вы указали равное количество строк и столбцов! Повторите попытку.";
			isEqual = true;
		}

	} while (isEqual);
	
	int** arr = new int* [rowCnt]; // Инициализация двумерного массива

	// Выделение памяти для каждой строки
	for (int i = 0; i < rowCnt; i++) {
		arr[i] = new int[colCnt];
	}

	// Инициализация генератора случайных чисел 
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 3);
	
	// Заполнение матрицы случайными элементами
	for (int i = 0; i < rowCnt; i++)
	{
		for (int j = 0; j < colCnt; j++)
		{
			arr[i][j] = dis(gen);
		}
	}

	// Вывод массива
	cout << "Матрица:\n";
	for (int i = 0; i < rowCnt; i++)
	{
		cout << i + 1 << ") ";
		for (int j = 0; j < colCnt; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";

	// Вывод результата проверки строк
	cout << "Результат проверок строк:\n";
	for (int i = 0; i < rowCnt; i++)
	{
		cout << i + 1 << ") ";
		isAscendOrder(arr[i], colCnt) ? cout << "Правда\n" : cout << "Ложь\n";
	}
}