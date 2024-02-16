#include <iostream>
#include <string>
#include <random>

using namespace std;

const int ColCnt = 3;
const int RowCnt = 8;

bool isAscendOrder(int* arr) {

	//int arrSize1 = sizeof(arr);
	//int arrSize2 = sizeof(*arr);

	//cout << "\n";
	//cout << arrSize;

	int* lastValue = arr;

	for (int* i{ arr + 1 }; i != arr + ColCnt; i++) {
		if (*lastValue <= *i)
			*lastValue = *i;
		else
			return false;
	}
	return true;
}

void main() {

	int arr[RowCnt][ColCnt]{};

	//int arrSize1 = sizeof(arr);
	//int arrSize2 = sizeof(*arr);

	// ������������� ���������� ��������� ����� 
	random_device rd; // ��������� ������ random_device ��� ���� //���� ��� ���-�� ����� ������, ���������� ����� �� �������������� �������������� ���������
	mt19937 gen(rd()); // ������ ��������� �� ��������� mt19937
	uniform_int_distribution<> dis(0, 3); //��������� �������� ���������

	for (int* i{ *arr }; i != *arr + RowCnt * ColCnt; i++) {
		*i = dis(gen);
	}

	for (int* i{ *arr }; i != *arr + RowCnt * ColCnt; i++) {
		cout << *i << ' ';

		if ((i + 1 - *arr) % ColCnt == 0) {
			cout << '\n';
		}
	}

	for (int* i{ *arr }; i <= *arr + RowCnt * ColCnt - 1; i += ColCnt) {

		cout << isAscendOrder(i) << '\n';

		if ((i + 1 - *arr) % ColCnt == 0) {
			cout << '\n';
		}
	}
}