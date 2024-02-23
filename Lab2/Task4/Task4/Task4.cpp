#include <iostream>
#include <string>
#include <list>

using namespace std;

struct _center { int x, y; };

struct circle
{
	unsigned int radius;
	_center center;
};

void main() {

	setlocale(LC_ALL, "RUS");

	int circleCnt{};

	cout << "������� ��������� �����������: ";
	cin >> circleCnt;

	cout << "������� ���������� � ������ ��� ������ ����������� ����� ������ ��� ���� (x y r)\n";

	list<circle> circleList;
	string x, y, r;
	circle newCircle{};
	int cntr = 0;

	while (cntr <= circleCnt - 1) {

		newCircle = {};
		cout << cntr + 1 << ") ";
		cin >> x >> y >> r;

		try
		{
			newCircle.center.x = stoi(x);
			newCircle.center.y = stoi(y);
			newCircle.radius = abs(stoi(r));
			circleList.push_back(newCircle);
			cntr++;
		}
		catch (const std::exception&)
		{
			cout << "������ ������! ����������, ��������� �������.\n";
		}
	}

	circle maxCircle{};
	for (const circle& i : circleList) {
		if (i.radius >= maxCircle.radius) maxCircle = i;
	}

	cout << "����� ������� ���������� ����� ���������� " << maxCircle.center.x << ", " << maxCircle.center.y;
}
