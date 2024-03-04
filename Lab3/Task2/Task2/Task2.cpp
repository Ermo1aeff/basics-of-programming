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

	int colCnt{};
	int rowCnt{};

	bool isEqual = false;

	do {
		cout << "������� ���������� ��������: ";
		cin >> colCnt;

		cout << "������� ���������� �����: ";
		cin >> rowCnt;

		if (colCnt == rowCnt) {
			cout << "�� ������� ������ ���������� ����� � ��������! ��������� �������.";
			isEqual = true;
		}

	} while (isEqual);
	
	int** arr = new int* [rowCnt]; // ������������� ���������� �������

	// ��������� ������ ��� ������ ������
	for (int i = 0; i < rowCnt; i++) {
		arr[i] = new int[colCnt];
	}

	// ������������� ���������� ��������� ����� 
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 3);
	
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
}