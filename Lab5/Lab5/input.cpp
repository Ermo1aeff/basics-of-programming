#include "header.h"

// ���� ���������� ������
double inputOptions() {

	string _value{};

	while (true)
	{
		try
		{
			cout << "������� ��������: ";
			cin >> _value;
			return stof(_value) > 0 ? stof(_value) : throw "�������� �� ����� ���� ������ ��� ����� ����!";
		}
		catch (const char* error_message)
		{
			cout << error_message << endl;
		}
		catch (const exception&)
		{
			cout << "�������� ������� �����������, ��������� �������." << endl;
		}
	}
	cout << endl;
}

// ������� ����� 
_apartment input()
{
	_apartment apartment;

	cout << "���������� ������." << endl;
	apartment.rmsNum = inputOptions();

	cout << "����." << endl;
	apartment.floor = inputOptions();

	cout << "�������." << endl;
	apartment.area = inputOptions();

	cout << "����� ��������.";

	bool flag = false;
	while (true) 
	{
		flag = false;

		cout << "������� �����: ";

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
			cout << "� ������ ��� �������� �������� � �������� �������. ������� ������ ��� ������� ������� \"b\" ��� �� ����� � ����." << endl;
		}
		else {
			break;
		}
	}

	return apartment;
}