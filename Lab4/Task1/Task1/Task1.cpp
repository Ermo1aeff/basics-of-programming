#include <iostream>
#include <string>

using namespace std;

char* resizeArray(char* str, int size) {
	char* tmp;
	tmp = new char[size + 1]{};
	memcpy(tmp, str, size);
	delete[] str;
	return tmp;
}

bool isBelong(char* arr, int arrSize, char* _word, int wordSize) {
	
	bool flag = false;

	for (int i = 0; i < wordSize; i++)
	{
		flag = false;

		for (int j = 0; j < arrSize; j++)
		{
			if (_word[i] == arr[j])
			{
				flag = true;
				break;
			}
		}

		if (!flag) return false;
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	char str[]{ "Мама мыла раму" };
	char substr[]{ "Мамеетететрруипш" };
	//char substr[]{ "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ" };

	int signCnt{};

	//Подсчет уникальных символов
	int strLen = sizeof(str);
	int substrLen = sizeof(substr);
	char* uniqSubstr = new char[1]{}; // Один элемент для хранения нулевого символа

	for (int i = 0; i < substrLen - 1; i++)
	{
		for (int j = 0; j < substrLen - 1; j++)
		{
			if (i == j) // Если в подстроке такого символа не было, сравниваем с основной строкой
			{
				signCnt++;
				uniqSubstr = resizeArray(uniqSubstr, signCnt);
				uniqSubstr[signCnt-1] = substr[i];
				break;
			}

			// Проверка на повторение символов в подстроке
			if ((substr[i] == substr[j]) && (i != j)) break; 
		}
	}

	cout << "Количество уникальных символов в подстроке: " << signCnt << "\n";
	cout << "Строка уникальных символов: " << uniqSubstr << "\n";

	int newWordLen{};
	char* newWord = new char[1] {};

	int resultStrLen{};
	char* resultStr = new char[1] {};
	
	bool isWord = true;

	char old = ' ';

	for (int i = 0; i < strLen; i++)
	{

		if ((old == ' ') && (str[i] != ' '))
		{
			isWord = true; // Если новое слово - true
			newWord = new char[1] {};
			newWordLen = 0;
		}

		if (isWord)
		{
			if (str[i] != ' ' && str[i] != '\0') // Если новый символ - проверяем, есть ли он в заданной подстроке
			{
				newWordLen++;
				newWord = resizeArray(newWord, newWordLen);
				newWord[newWordLen - 1] = str[i];
			}
			else // Если конец слова 
			{
				if (isBelong(uniqSubstr, signCnt, newWord, newWordLen)) // Проверяем на содержание симвлолов в подстроке
				{
					resultStr = resizeArray(resultStr, resultStrLen + newWordLen + 1);
					for (int j = 0; j < newWordLen; j++)
					{
						resultStr[resultStrLen + j] = newWord[j];
					}
					resultStrLen += newWordLen;
					resultStr[resultStrLen] = ' ';
					resultStrLen++;

					cout << "Слово : " << newWord << "\n";
				}
				isWord = false;
				delete[] newWord;
			}
		}
		old = str[i];
	}

	cout << "Результирующая строка: " << resultStr << "\n";
}