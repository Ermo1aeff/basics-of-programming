#include <iostream>
#include <string>
#include <list>

using namespace std;

struct _center { int x, y; };

struct circle
{
	int radius;
	_center center;
};

void main() {

	setlocale(LC_ALL, "RUS");

	int circleCnt{};

	cout << "Укажите количесво окружностей: ";
	cin >> circleCnt;

	cout << "Укажите координаты и радиус для каждой окружностей через пробел или энтр (x y r)\n";
	//cout << "EXIT - выход из цикла\n";

	list<circle> circleList;
	string x, y, r;
	circle newCircle{};
	bool isExit = false;
	int cntr = 0;

	while (cntr <= circleCnt - 1) {

		newCircle = {};
		cout << cntr + 1 << ") ";
		cin >> x >> y >> r;

		//for (char& c : x) {
		//	c = tolower(c);
		//}

		//if (x == "exit") isExit = true;
		//else 
		//{
			try
			{
				newCircle.center.x = stoi(x);
				newCircle.center.y = stoi(y);
				newCircle.radius = stoi(r);
				circleList.push_back(newCircle);
				cntr++;
			}
			catch (const std::exception&)
			{
				cout << "Ошибка записи! Пожалуйста, повторите попытку.\n";
			}
		//}
		//cin >> newCircle.center.x >> newCircle.center.y >> newCircle.radius;
	}

	circle maxCircle{};
	for (const circle& i : circleList) {
		if (i.radius >= maxCircle.radius) maxCircle = i;
	}

	cout << "Самая большая окружность имеет координаты " << maxCircle.center.x << ", " << maxCircle.center.y;
}
