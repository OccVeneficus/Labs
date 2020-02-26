#include "DynamicArray.h"
#include <iostream>

using namespace std;

//TODO: именование функций от существительного, а должно быть от глагола
//TODO: именование аргумента не соответствует объекту
void CreateArray(DynamicArray &userArray)
{
	userArray.Length = 8;
	userArray.Capacity = 8;
	userArray.Array = new int[userArray.Capacity];
	for (int i = 0; i < userArray.Length; i++)
	{
		userArray.Array[i] = rand() % 10;
	}
}

//TODO: именование функций от существительного, а должно быть от глагола
//TODO: именование аргумента не соответствует объекту
void PrintArray(DynamicArray &userArray)
{
	cout << "Current array: ";
	for (int i = 0; i < userArray.Length; i++)
	{
		cout << " " << userArray.Array[i] << " ";
	}
	cout << "\n";
}

void PrintMenuText()
{
	cout << " ______________________________________________________________\n";
	cout << "|                       ||||||MENU||||||                      |\n";
	cout << "|List of available functions:                                 |\n";
	cout << "|(To choose function type it number from list below)          |\n";
	cout << "| 1. Delete element from array.                               |\n";
	cout << "| 2. Add element to begin of array.                           |\n";
	cout << "| 3. Add element to end of array.                             |\n";
	cout << "| 4. Add element after specific element in array.             |\n";
	cout << "| 5. Sort array.                                              |\n";
	cout << "| 6. Linear search.                                           |\n";
	cout << "| 7. Binar search.                                            |\n";
	cout << "| 8. Exit                                                     |\n";
	cout << "|_____________________________________________________________|\n";
}

//TODO: именование функций от существительного, а должно быть от глагола
//TODO: именование аргумента не соответствует объекту
void DeleteElement(DynamicArray &userArray)
{
	PrintArray(userArray);
	cout << "\n";
	int indexToDelete;
	do
	{
		cout << "Enter index of element you want to delete: ";
		indexToDelete = ReadValue();
	} while (indexToDelete < 0 || indexToDelete >= userArray.Length);
	for (int i = indexToDelete; i < userArray.Length; i++)
	{
		userArray.Array[i] = userArray.Array[i + 1];
	}
	--userArray.Length;
}

//TODO: именование функций от существительного, а должно быть от глагола
//TODO: именование аргумента не соответствует объекту
void AddAfterIndex(DynamicArray &userArray, int index) 
{
	PrintArray(userArray);
	if (userArray.Length == userArray.Capacity)
	{
		RecreateArray(userArray);
	}
	cout << "\n";
	cout << "Enter value you want to add to array: ";
	int value = ReadValue();
	for (int i = userArray.Length - 1; i >= index; i--)
	{
		userArray.Array[i + 1] = userArray.Array[i];
	}
	userArray.Array[index] = value;
	++userArray.Length;
}

//TODO: именование функций от существительного, а должно быть от глагола
//TODO: именование аргумента не соответствует объекту
void SortArray(DynamicArray &userArray)
{
	for (int i = 1; i < userArray.Length; i++)
	{
		for (int j = i; j > 0 && userArray.Array[j - 1] >
			userArray.Array[j]; j--)
		{
			swap(userArray.Array[j - 1], userArray.Array[j]);
		}
	}
	cout << "\n";
	cout << "Sorted array\n";
}

//TODO: именование функций от существительного, а должно быть от глагола
//TODO: именование аргумента не соответствует объекту
void LinearSearch(DynamicArray &userArray)
{
	PrintArray(userArray);
	cout << "\n";
	cout << "Enter value you want to find: ";
	int valueToSearch = ReadValue();
	int index = -1;
	for (int i = 0; i < userArray.Length; i++)
	{
		if (userArray.Array[i] == valueToSearch)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		cout << "\n";
		cout << "There is at least 1 element ";
		cout << valueToSearch;
		cout << " in array. Index: ";
		cout << index;
		cout << "\n";
	}
	else
	{
		cout << "\n";
		cout << "There is no ";
		cout << valueToSearch;
		cout << " in current Array.";
		cout << "\n";
	}
}

//TODO: именование функций от существительного, а должно быть от глагола
//TODO: именование аргумента не соответствует объекту
void BinarSearch(DynamicArray &userArray)
{
	SortArray(userArray);
	PrintArray(userArray);
	cout << "\n";
	cout << "What value you want to find: ";
	int valueToSearch = ReadValue();
	int leftEnd = 0;
	int rightEnd = userArray.Length;
	int middleOfArray;
	bool flag = false;
	//TODO: используй '!' вместо сравнения с false
	while (!flag && leftEnd <= rightEnd)
	{
		middleOfArray = (leftEnd + rightEnd) / 2;

		if (userArray.Array[middleOfArray] == valueToSearch)
		{
			flag = true;
		}
		if (userArray.Array[middleOfArray] > valueToSearch)
		{
			rightEnd = middleOfArray - 1;
		}
		else
		{
			leftEnd = middleOfArray + 1;
		}
	}
	if (flag)
	{
		cout << "\n";
		cout << "There is at least 1 element ";
		cout << valueToSearch;
		cout << " in array. Index: ";
		cout<< middleOfArray;
		cout << "\n";
	}
	else
	{
		cout << "\n";
		cout << "There is no ";
		cout << valueToSearch;
		cout << " in current Array.";
		cout << "\n";
	}
}

//TODO: именование функций от существительного, а должно быть от глагола
//TODO: метод Delete и Create антагоничны по действию. Предпочтительно, чтобы
//антагоничные функции принимали одинаковые аргументы
void DeleteArray(int *userArray) 
{
	delete[] userArray;
}

//TODO: именование функций от существительного, а должно быть от глагола
//TODO: именование аргумента не соответствует объекту
void RecreateArray(DynamicArray &userArray)
{
	const int buffer = 8;
	int *newArray = new int[userArray.Capacity + buffer];
	for (int i = 0; i < userArray.Length; i++)
	{
		newArray[i] = userArray.Array[i];
	}
	DeleteArray(userArray.Array);
	userArray.Array = newArray;
}

//TODO: именование функций от существительного, а должно быть от глагола
int ReadValue()
{
	int taxableIncome;
	while(true) 
	{
		if (cin >> taxableIncome) 
		{
			break;
		}
		else 
		{
			cout << "You can enter only an integer: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return taxableIncome;
}