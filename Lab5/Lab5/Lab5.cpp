#include "header.h"

list<_apartment> apartments;

// Процедура вывода информации о квартире
void output(_apartment apartment)
{
	cout << "Кол-во комнат: " << apartment.rmsNum << endl;
	cout << "Этаж: " << apartment.floor << endl;
	cout << "Площадь: " << apartment.area << endl;
	cout << "Адрес: " << apartment.adress << endl;
	cout << endl;
}

// Функция, выполняющая функцияю меню
int menu() {
	string _operation{};
	int operation{};

	cout << "---Меню---" << endl << endl;
	cout << "1) Ввод заявки на объмен." << endl;
	cout << "2) Поиск в картотеке подходящего варианта." << endl;
	cout << "3) Вывод списка квартир." << endl;
	cout << "4) Выход из программы." << endl << endl;

	while (true)
	{
		cout << "Введите номер действия, которое хотите совершить: ";
		cin >> _operation;

		try
		{
			operation = stoi(_operation);

			if ((operation >= 1) && (operation <= 4))
			{
				//system("CLS");
				return operation;
			}
			else
			{
				throw "Значение не в ходит в заданный диапазон!";
			}
		}
		catch (const char* error_message)
		{
			cout << error_message;
		}
		catch (const std::exception&)
		{
			cout << "Указано некорректное значение, повторите попытку.";
		}
		cout << endl << endl;
	}
}

// Поиск в картотеке подходящего варианта 
void search() {
	cout << "Поиск в картотеке подходящего варианта." << endl << endl;
	_apartment desiredApt = input();

	double minArea = desiredApt.area - desiredApt.area * 0.05;
	double maxArea = desiredApt.area + desiredApt.area * 0.05;

	double idealArea{ -1 }; // Размер площади подходящей записи
	int idealIndex{}; // Индекс подходящей записи
	int i{}; // Индекс списка

	// Поиск подходящего варианта
	for (_apartment item : apartments) {
		if ((item.rmsNum == desiredApt.rmsNum) && (item.floor == desiredApt.floor) &&
			(item.area > minArea) && (item.area < maxArea)) {

			if (idealArea == -1) {
				idealArea = item.area;
				idealIndex = i;
			}
			else
			{
				// Отсебятина, условие ищет оптимальный вариант по площади
				if (abs(item.area - desiredApt.area) < abs(idealArea - desiredApt.area)) {
					idealIndex = i;
				}
			}
		}
		i++;
	}

	if (idealArea == -1) {
		apartments.push_back(desiredApt);
		cout << "Не удалось найти подходящего варианта. Ваша заявка добавлена в список." << endl;
	}
	else {
		cout << "Наиболее подходящий вариант для вас: " << endl;
		list<_apartment>::iterator it = next(apartments.begin(), idealIndex); // Определение итератора элемента списка
		output(*it);			// Вывод карточки найденой записи
		apartments.erase(it);   // Удаление элемента списка по итератору
	}
}


void recicleMenu() {
	int recordCount{};
	// Цикличный вызов меню и вызов выбраной операции
	while (true)
	{
		switch (menu())
		{
		case 1:
			apartments.push_back(input());
			break;
		case 2:
			search();
			break;
		case 3:
			recordCount = 0;
			for (_apartment item : apartments) {
				cout << "Запись №" << ++recordCount << endl;
				output(item);
			}
			cout << endl;
			break;
		case 4: 
			exit(0);
			break;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // Подключение кириллицы
	setlocale(LC_ALL, "RUS");

	// Начальное условие задания (формирование картотеки)

	int recordCount = 0;
	string choice{};

	cout << "Формирование картотеки:" << endl;

	while (true)
	{
		cout << "Создать новую запись? да(y) / нет(n): ";
		cin >> choice;
		cout << endl;

		if (choice == "n") break;
		else
		{
			if (choice == "y") {
				cout << "Заполнение записи №" << ++recordCount << ":" << endl;
				apartments.push_back(input());
			}
			else {
				cout << "Указан неверный запрос, повторите попытку." << endl;
			}
		}
	}

	recicleMenu();
}
