#include <iostream>

char* resizeArray(char* str, int strSize, int value) {
	char* tmp = new char[strSize + value]{};
	memcpy(tmp, str, strSize);
	delete[] str;
	return tmp;
}

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

bool isSubstring(char* arr, int arrSize, char* _word, int wordSize) {

	if (arrSize != wordSize) return false;

	for (int i = 0; i < arrSize; i++)
	{
		if (_word[i] != arr[i])
		{
			return false;
		}
	}

	return true;
}