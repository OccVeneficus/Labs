#include "DynamicArray.h"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	int index;
	DynamicArray arrayParameters;
	CreateArray(arrayParameters);
	cout << "\n";
	int menuItem;
	do 
	{
		PrintArray(arrayParameters);
		cout << endl;
		PrintMenuText();
		do
		{
			cout << "Enter menu item(you can only use numbers from 1 to 8): ";
			menuItem = ReadValue();
		} 
		while (menuItem > 8 || menuItem <= 0);
		switch (menuItem)
		{
		case 1:
			{
			system("cls");
			DeleteElement(arrayParameters);
			break;
			}
		case 2:
			{
			system("cls");
			AddAfterIndex(arrayParameters, 0);
			break;
			}
		case 3:
			{
			system("cls");
			AddAfterIndex(arrayParameters, arrayParameters.Length);
			break;
			}
		case 4:
			{
			system("cls");
			do
			{
				//TODO: а теперь загугли перевод слова witch
				cout << "Enter index of element after wich";
				cout << "you want to put new element: ";
				index = ReadValue() + 1;
			} while (index < 0 || index >= arrayParameters.Length);
			AddAfterIndex(arrayParameters, index);
			break;
			}
		case 5:
			{
			system("cls");
			SortArray(arrayParameters);
			break;
			}
		case 6:
			{
			system("cls");
			LinearSearch(arrayParameters);
			break;
		}
		case 7:
			{
			system("cls");
			BinarSearch(arrayParameters);
			break;
			}
		}
	} while (menuItem != 8);
	DeleteArray(arrayParameters.Array);
	cout << "Ending session...";
	return 0;
}