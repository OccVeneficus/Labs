//TODO: плохое именование для файла.
// Функции ввода/вывода лучше в один файл,
// а функции чисто пользовательского интерфейса - в другой
#include "UserInputOutput.h"
#include "LinkedList.h"
#include <string>
#include <sstream>

bool CheckForInteger(string value)
{
	int size = value.length();
	if (isdigit((unsigned char)value[0]) || (unsigned char)value[0] == '-')
	{
		for (int i = 1; i < size; i++)
		{
			if (!isdigit((unsigned char)value[i]))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

int ReadValue()
{
	string inputValue;
	int outputValue;
	while (true)
	{
		getline(cin, inputValue);
		bool intCheckFlag = CheckForInteger(inputValue);
		istringstream inputStringStream(inputValue);
		int number;
		inputStringStream >> number;
		if (intCheckFlag == false || inputStringStream.fail())
		{
			cout << endl << "Wrong input, try again.You can use only integer:";
			inputValue.clear();
		}
		else
		{
			outputValue = stoi(inputValue);
			return outputValue;
		}
	}
}

void PrintList(List *listParameters)
{
	cout << endl;
	struct Node *elementToPrint;
	elementToPrint = listParameters->Head;
	for(int i = 0; i < listParameters->ListLength; i++)
	{
		cout << elementToPrint->Field << ' ';
		elementToPrint = elementToPrint->Next;
	}
	cout << endl;
}

bool ChoosePosition(List *ListParameters)
{
	int positionOfElement;
	if (ListParameters->ListLength == 0)
	{
		return false;
	}
	do
	{
		cout << "Enter position of element(from 1 to " <<
			ListParameters->ListLength <<"):";
		positionOfElement = ReadValue();
	} while (positionOfElement > ListParameters->ListLength ||
		positionOfElement <= 0);
	clock_t begin = clock();
	if (positionOfElement <= ListParameters->ListLength / 2)
	{
		ListParameters->CurrentNode = ListParameters->Head;
		for (int i = 1; i < positionOfElement; i++)
		{
			ListParameters->CurrentNode = ListParameters->CurrentNode->Next;
		}
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << elapsed_secs;
		system("pause");
		return true;
	}
	else
	{
		ListParameters->CurrentNode = ListParameters->Tail;
		for (int i = ListParameters->ListLength; i > positionOfElement; i--)
		{
			ListParameters->CurrentNode = ListParameters->CurrentNode->Previous;
		}
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << elapsed_secs;
		system("pause");
		return true;
	}
}