#include "header.h"

// Ввод количества комнот
double inputOptions() {

	string _value{};

	while (true)
	{
		try
		{
			cout << "Укажите значение: ";
			cin >> _value;
			return stof(_value) > 0 ? stof(_value) : throw "Значение не может быть меньше или равно нулю!";
		}
		catch (const char* error_message)
		{
			cout << error_message << endl;
		}
		catch (const exception&)
		{
			cout << "Значение указано некорректно, повторите попытку." << endl;
		}
	}
	cout << endl;
}

// Функция ввода 
_apartment input()
{
	_apartment apartment;

	cout << "Количество комнат." << endl;
	apartment.rmsNum = inputOptions();

	cout << "Этаж." << endl;
	apartment.floor = inputOptions();

	cout << "Площадь." << endl;
	apartment.area = inputOptions();

	cout << "Адрес квартиры.";

	bool flag = false;
	while (true) 
	{
		flag = false;

		cout << "Укажите адрес: ";

		cin.ignore();
		getline(cin, apartment.adress);

		if (apartment.adress == "b") recicleMenu;

		for (_apartment item : apartments) {

			if (item.adress == apartment.adress) {
				flag = true;
				break;
			}
		}

		if (flag) {
			cout << "В списке уже хранится квартира с указаным адресом. Укажите другой или укажите команду \"b\" что бы выйти в меню." << endl;
		}
		else {
			break;
		}
	}

	return apartment;
}