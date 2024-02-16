#include <iostream>
#include <string>
//#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	char str[]{ "Мама мыла раму" };
	char substr[]{ "Мамеететет" };


	int signCnt = 0;
	char newStr[]{ "" };


	//Определение количества уникальных символов
	//int length = sizeof(substr);

	//for (int i = 0; i < length - 1; i++)
	//{
	//	for (int j = 0; j < length - 1; j++)
	//	{
	//		if (i == j)
	//		{
	//			signCnt++;
	//			break;
	//		}

	//		if ((substr[i] == substr[j]) && (i != j))
	//		{
	//			break;
	//		}
	//	}
	//}


	//Определение количества уникальных символов
	int strLen = sizeof(str);
	int substrLen = sizeof(substr);

	for (int i = 0; i < substrLen - 1; i++)
	{
		for (int j = 0; j < substrLen - 1; j++)
		{
			if (i == j) // Если в подстроке такого символа не было, сравниваем с основной строкой
			{
				signCnt++;
				break;
			}

			// Проверка на повторение символов в подстроке
			if ((substr[i] == substr[j]) && (i != j)) break; 
		}
	}

	//char* k = new char[signCnt]();
	//*k = 'f';
	//cout << *k;

	cout << "Количество уникальных символов в подстроке: " << signCnt;

	//char* uniqSubstr = new char[signCnt]();
	//char* newStr = new char[0]();

	//for (int i = 0; i < substrLen - 1; i++)
	//{
	//	for (int j = 0; j < strLen - 1; j++)
	//	{
	//		if (str[j] == uniqSubstr[i])
	//		{
	//			newStr += '4';
	//		}
	//	}
	//}

	//for (int k = 0; k < strLen - 1; k++)
	//{
	//	if (strLen[k] = )
	//	{

	//	}
	//}

	

	//int length = sizeof(substr);

	//for (char* i = substr; i < substr + length - 1; i++)
	//{
	//	for (char* j = substr; j < substr + length - 1; j++)
	//	{
	//		//cout << &i << " : " << &j;

	//		if (&i == &j)
	//		{
	//			signCnt++;
	//			break;
	//		}

	//		if ((i == j) && (&i != &j))
	//		{
	//			break;
	//		}
	//	}
	//}



	/*for (char i : str) {

	}*/


}