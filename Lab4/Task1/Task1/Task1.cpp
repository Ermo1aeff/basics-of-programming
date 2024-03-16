#include "header.h"

//#define debug

int main()
{
	// Установка кириллицы для программы
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");

	// Инициализация массива строки
	int strLen{ 1 }; // Одна ячейка под нулевой элемент, для правильного определения конца строки
	char* str = new char[strLen] {};

	cout << "Введите строку: ";
	
	while (cin.peek() != '\n')
	{
		str = resizeArray(str, strLen, 1); // Расширение массива на 1 элемент
		cin >> noskipws >> str[strLen - 1]; // Запись из буфера консоли в массив
		strLen++;
	}

	cin.ignore(); // Пропуск символа перехода на новую строку (\n)

	int substrLen{ 1 };
	char* substr = new char[substrLen] {};

	cout << "Введите подстроку: ";

	while (cin.peek() != '\n')
	{
		substr = resizeArray(substr, substrLen, 1);
		cin >> substr[substrLen - 1];
		substrLen++;
	}

	int signCnt{};

	int uniqSubstrLen{ 1 };
	int j{};

	//Удаление повторяющихся символов (алгоритм можно оптимизировать, сравнивая со строкой уникальных символов)
	char* uniqSubstr = new char[uniqSubstrLen]{}; // Один элемент для хранения нулевого символа

	bool isExist = false;

	for (int i = 0; i < substrLen - 1; i++) // Проверка 
	{
		isExist = false;
		j = 0;

		while (j < uniqSubstrLen - 1) 
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
			uniqSubstr = resizeArray(uniqSubstr, uniqSubstrLen, 1);
			uniqSubstr[uniqSubstrLen - 1] = substr[i];
			uniqSubstrLen++;
			signCnt++;
		}
	}

	#ifdef debug
	cout << "Количество уникальных символов в подстроке: " << signCnt << "\n";
	cout << "Строка уникальных символов: " << uniqSubstr << "\n";
	#endif

	int newWordLen{ 1 };
	char* newWord = new char[newWordLen] {};

	int resultStrLen{ 1 };
	char* resultStr = new char[resultStrLen] {};
	
	bool isWord = false;

	bool isFirstSubstring = false;

	char old = ' ';

	for (int i = 0; i < strLen; i++)
	{
		if ((old == ' ') && (str[i] != ' ')) // Определение нового слова
		{
			isWord = true;
			newWordLen = 1;
			newWord = new char[newWordLen] {};
		}

		if (isWord)
		{
			if ((str[i] != ' ') && (str[i] != '\0')) // Проверка окончания слова
			{
				newWord = resizeArray(newWord, newWordLen, 1);
				newWord[newWordLen - 1] = str[i];
				newWordLen++;
			}
			else // Если конец слова
			{
				#ifdef debug
				cout << "Слово: " << newWord << '\n';
				#endif
				// Проверка, является ли слово подстрокой
				//if (isSubstring(substr, substrLen, newWord, newWordLen) && !isFirstSubstring)
				//{
				//	char* strBuf = new char[resultStrLen]; // Объявление буфера
				//	memcpy(strBuf, resultStr, resultStrLen); // Передача результирующей строки в буфер 

				//	#ifdef debag 
				//	cout << "Подстрока: " << strBuf << '\n'; 
				//	#endif

				//	resultStr = resizeArray(resultStr, resultStrLen, newWordLen); // Расширение строки + 1 элемент под разделитель

				//	memcpy(resultStr, newWord, newWordLen); // Передача слова в начало результ. строки  

				//	resultStr[newWordLen - 1] = ' ';

				//	memcpy(resultStr + newWordLen, strBuf, resultStrLen - 1); // Прибавление буфера к строке
				//	resultStrLen += newWordLen;

				//	isFirstSubstring = true;
				//}
				//else 
				//{
					// Проверка на содержание симвлолов в подстроке ( ПЕРЕПРОВЕРИТЬ! )
					if (isBelong(uniqSubstr, signCnt, newWord, newWordLen))
					{
						resultStr = resizeArray(resultStr, resultStrLen, newWordLen); // Расширение строки - 1, т.к. нулевой символ не учитывается и + 1 под разделитель слов

						memcpy(resultStr + resultStrLen - 1, newWord, newWordLen - 1); // Запись слова в общую результатирующую строку

						resultStrLen += newWordLen - 1; // Обновление размера массива (- 1 т.к. один элемент считается нулевым)
						resultStr[resultStrLen - 1] = ' ';
						resultStrLen++;

						#ifdef debug  
						cout << "Слово, содержащее все символы подстроки: " << newWord << '\n';
						#endif
					}
					isWord = false;
					delete[] newWord;
				//}
			}
		}
		old = str[i];
	}

	cout << "Результат выполнения 1: " << resultStr << "\n";

	delete[] resultStr;

	// Восстановление начальных значений всех переменных
	newWordLen = 1;
	newWord = new char[newWordLen] {};

	resultStrLen = 1 ;
	resultStr = new char[resultStrLen] {};

	isWord = false;

	isFirstSubstring = false;

	old = ' ';

	for (int i = 0; i < strLen; i++)
	{
		if ((old == ' ') && (str[i] != ' ')) // Определение нового слова
		{
			isWord = true;
			newWordLen = 1;
			newWord = new char[newWordLen] {};
		}

		if (isWord)
		{
			if ((str[i] != ' ') && (str[i] != '\0')) // Проверка окончания слова
			{
				newWord = resizeArray(newWord, newWordLen, 1);
				newWord[newWordLen - 1] = str[i];
				newWordLen++;
			}
			else // Если конец слова
			{
				#ifdef debug
				cout << "Слово: " << newWord << '\n';
				#endif
				// Проверка, является ли слово подстрокой
				if (isSubstring(substr, substrLen, newWord, newWordLen) && !isFirstSubstring)
				{
					char* strBuf = new char[resultStrLen]; // Объявление буфера
					memcpy(strBuf, resultStr, resultStrLen); // Передача результирующей строки в буфер 

					#ifdef debag 
					cout << "Подстрока: " << strBuf << '\n';
					#endif

					resultStr = resizeArray(resultStr, resultStrLen, newWordLen); // Расширение строки + 1 элемент под разделитель

					memcpy(resultStr, newWord, newWordLen); // Передача слова в начало результ. строки  

					resultStr[newWordLen - 1] = ' ';

					memcpy(resultStr + newWordLen, strBuf, resultStrLen - 1); // Прибавление буфера к строке
					resultStrLen += newWordLen;

					delete[] strBuf;
					isFirstSubstring = true;
				}
				else
				{
					// Проверка на содержание симвлолов в подстроке ( ПЕРЕПРОВЕРИТЬ! )
					//if (isBelong(uniqSubstr, signCnt, newWord, newWordLen))
					//{
						resultStr = resizeArray(resultStr, resultStrLen, newWordLen); // Расширение строки - 1, т.к. нулевой символ не учитывается и + 1 под разделитель слов

						memcpy(resultStr + resultStrLen - 1, newWord, newWordLen - 1); // Запись слова в общую результатирующую строку

						resultStrLen += newWordLen - 1; // Обновление размера массива (- 1 т.к. один элемент считается нулевым)
						resultStr[resultStrLen - 1] = ' ';
						resultStrLen++;

						#ifdef debug  
						cout << "Слово, содержащее все символы подстроки: " << newWord << '\n';
						#endif
					//}
				}
				isWord = false;
				delete[] newWord;
			}
		}
		old = str[i];
	}

	cout << "Результат выполнения 2: " << resultStr << "\n";

	cin.get();
	cin.get();
}