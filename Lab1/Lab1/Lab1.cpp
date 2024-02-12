#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* agrv[]) {

	//for (int i {}; i < argc; i++)
	//{
	//	cout << agrv[i] << endl;
	//}

	setlocale(LC_ALL, "RUS");

	try
	{
		int a = stoi(agrv[1]);
		string oper = agrv[2];
		int b = stoi(agrv[3]);

		switch (oper[0])
		{
		case '+':
			cout << a + b;
			break;
		case '-':
			cout << a - b;
			break;
		case '*':
			cout << a * b;
			break;
		case '/':
			b != 0 ? cout << (a / (double)b) : cout << "Деление на ноль!";
			break;
		default:
			break;
		}
	}
	catch (const std::exception&)
	{
		cout << "Аргументы введены не верно!";
	}
}