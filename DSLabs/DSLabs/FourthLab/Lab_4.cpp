#include "DataInOutLab4.h"
#include "ClassesOutput.h"
#include "Chain.h"
#include "NodeLab4.h"
#include "HashTable.h"
#include "Vocabulary.h"
#include "MenusLab4.h"
#include <windows.h>

void Lab_4()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menuItem;
	Dictionary userDictionary;
	HashTable userTable;
	do
	{
		PrintMainMenuLab4();
		do
		{
			cout << "Enter menu item from list above (integer only):";
			menuItem = ReadValue();
			cout << endl;
		} 
		while (menuItem > 2 && menuItem < 0);
		switch (menuItem)
		{
			case 1:
			{
				DictionaryMenu(&userDictionary);
				system("cls");
				break;
			}
			case 2:
			{
				HashTableMenu(&userTable);
				system("cls");
				break;
			}
		}
	}
	while (menuItem != EXIT_MENU_ITEM);
}