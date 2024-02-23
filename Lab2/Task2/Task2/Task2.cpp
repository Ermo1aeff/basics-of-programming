#include <iostream>
#include <string>
#include <random>

using namespace std;

int main(int argc, char* agrv[]) {

	setlocale(LC_ALL, "RUS");

	int arrACnt, arrBCnt;

	cout << "Укажите размер массива А: ";
	cin >> arrACnt;
	
	cout << "Укажите размер массива B: ";
	cin >> arrBCnt;

	int* arrA{ new int[arrACnt] };
	int* arrB{ new int[arrBCnt] };

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(-9, 9);

	for (int* i = arrA; i != arrA + arrACnt; i++) {
		*i = dis(gen);
	}

	for (int* i = arrB; i != arrB + arrBCnt; i++) {
		*i = dis(gen);
	}

	for (int* i = arrA; i != arrA + arrACnt; i++) {
		cout << *i << " ";
	}
	cout << "\n";

	for (int* i = arrB; i != arrB + arrBCnt; i++) {
		cout << *i << " ";
	}
	cout << "\n";

	int negNumCnt_A{}, negNumCnt_B{};

	for (int* i = arrA; i != arrA + arrACnt; i++) {
		if (*i < 0) negNumCnt_A++;
	}

	for (int* i = arrB; i != arrB + arrBCnt; i++) {
		if (*i < 0) negNumCnt_B++;
	}

	negNumCnt_A != negNumCnt_B ? negNumCnt_A > negNumCnt_B ? cout << "A" : cout << "B" : cout << "A = B";
}