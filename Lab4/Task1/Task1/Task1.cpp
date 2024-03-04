#include <iostream>
#include <string>

#include <ctime>
#include <chrono>

using namespace std;

char* resizeArray(char* str, int size) {
	char* tmp;
	tmp = new char[size + 1]{};
	memcpy(tmp, str, size);
	delete[] str;
	return tmp;
}


//bool isBelong(char* arr, int arrSize, char* _word, int wordSize) {
//
//	bool flag = false;
//
//	for (int i = 0; i < wordSize; i++)
//	{
//		flag = false;
//
//		for (int j = 0; j < arrSize; j++)
//		{
//			if (_word[i] == arr[j])
//			{
//				flag = true;
//				break;
//			}
//		}
//
//		if (!flag) return false;
//	}
//	return true;
//}

bool isBelong(char* arr, int arrSize, char* _word, int wordSize) {
	
	bool flag = false;

	for (int i = 0; i < arrSize; i++)
	{
		flag = false;

		for (int j = 0; j < wordSize; j++)
		{
			if (_word[j] == arr[i])
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

	char str[]{ "мама мыла раму" };
	char substr[]{ "ма"};
	//char substr[]{ "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ" };

	int signCnt{};

	int uniqSubstrLen = 1;
	int j{};

	//Удаление повторяющихся символов (алгоритм можно оптимизировать, сравнивая со строкой уникальных символов)
	int strLen = sizeof(str);
	int substrLen = sizeof(substr);
	char* uniqSubstr = new char[uniqSubstrLen]{}; // Один элемент для хранения нулевого символа

	bool isExist = false;

	//time_t seconds = time(NULL);
	//tm* timeinfo = localtime(&seconds);

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < substrLen - 1; i++) // Проверка 
	{
		isExist = false;
		j = 0;

		while (j < uniqSubstrLen) 
		{
			if (uniqSubstr[j] == substr[i])
			{
				isExist = true;
				break; // Если символ встретился реньше - выход
			}
			j++;
		}

		if (!isExist)
		{
			signCnt++;
			uniqSubstrLen++;
			uniqSubstr = resizeArray(uniqSubstr, signCnt);
			uniqSubstr[signCnt - 1] = substr[i];
		}


		//for (int j = 0; j < substrLen - 1; j++)
		//{
		//	if (i != j)
		//	{
		//		if (substr[i] == substr[j]) break; // Если символ встретился реньше - выход
		//	}
		//	else // Если программа дошла до текущего символа - производится его запись
		//	{
		//		signCnt++;
		//		uniqSubstr = resizeArray(uniqSubstr, signCnt);
		//		uniqSubstr[signCnt - 1] = substr[i];
		//		break;
		//	}
		//}
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "Время выполнения: " << duration.count()*10000 << " секунд\n";

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
		if ((old == ' ') && (str[i] != ' ')) // Определение нового слова
		{
			isWord = true;
			newWord = new char[1] {};
			newWordLen = 0;
		}

		if (isWord)
		{
			if (str[i] != ' ' && str[i] != '\0') // Проверка окончания слова
			{
				newWordLen++;
				newWord = resizeArray(newWord, newWordLen);
				newWord[newWordLen - 1] = str[i];
			}
			else // Если конец слова 
			{
				if (isBelong(uniqSubstr, signCnt, newWord, newWordLen)) // Проверка на содержание симвлолов в подстроке
				{
					resultStr = resizeArray(resultStr, resultStrLen + newWordLen + 1); // Расширение строки + 1 элемент под разделитель

					memcpy(resultStr + resultStrLen, newWord, newWordLen); // Запись слова в общую результатирующую строку (вар 1)

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

	cin.get();
}