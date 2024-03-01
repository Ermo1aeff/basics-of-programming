#include <iostream>
#include <string>
#include <random>

using namespace std;

// �������� ������ �� ������� ��������� �� �����������
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

	const int colCnt = 2;
	const int rowCnt = 8;

	//int arr[rowCnt][colCnt]{};

	int** arr = new int* [rowCnt];

	// ��������� ������ ��� ������ ������
	for (int i = 0; i < rowCnt; i++) {
		arr[i] = new int[colCnt];
	}

	//int arrSize1 = sizeof(arr);
	//int arrSize2 = sizeof(*arr);

	//for (int* i{ *arr2 }; i != *arr2 + rowCnt * colCnt; i++) {

	//	cout << *i << ' ';

	//	if ((i + 1 - *arr2) % colCnt == 0) {
	//		cout << '\n';
	//	}
	//}

	// ������������� ���������� ��������� ����� 
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 2);
	
	// ���������� ������� ���������� ����������
	for (int i = 0; i < rowCnt; i++)
	{
		for (int j = 0; j < colCnt; j++)
		{
			arr[i][j] = dis(gen);
		}
	}

	// ����� �������
	cout << "�������:\n";
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

	// ����� ���������� �������� �����
	cout << "��������� �������� �����:\n";
	for (int i = 0; i < rowCnt; i++)
	{
		cout << i + 1 << ") ";
		isAscendOrder(arr[i], colCnt) ? cout << "������\n" : cout << "����\n";
	}

	//for (int* i{ *arr }; i != *arr + rowCnt * colCnt; i++) {
	//	*i = dis(gen);
	//}

	//for (int* i{ *arr }; i != *arr + rowCnt * colCnt; i++) {

	//	cout << *i << ' ';

	//	if ((i + 1 - *arr) % colCnt == 0) {
	//		cout << '\n';
	//	}
	//}

	//for (int* i{ *arr }; i <= *arr + rowCnt * colCnt - 1; i += colCnt) {
	//	cout << isAscendOrder(i, colCnt) << '\n';
	//}
}