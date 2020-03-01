#include "MenusLab4.h"

void DictionaryMenu(Dictionary *userDictionary)
{
	system("cls");
	string key;
	string value;
	int menuItem;
	do
	{
		system("cls");
		cout << "Current dictionary:\n";
		PrintDictionary(userDictionary);
		cout << endl;
		PrintDictionaryMenuText();
		do
		{
			cout << "Enter menu item from list above (integer only):";
			menuItem = ReadValue();
			cout << endl;
		} 
		while (menuItem > 3 && menuItem < 0);
		switch (menuItem)
		{
			case 1:
			{
				ReadKeyValue(key, value);
				userDictionary->AddKeyValuePair(key, value);
				system("cls");
				break;
			}
			case 2:
			{
				ReadStringKey(key);
				userDictionary->DeletePairByKey(key);
				system("pause");
				break;
			}
			case 3:
			{
				Node *findedValue;
				ReadStringKey(key);
				if ((findedValue = userDictionary->SearchPairByKey(key)) == nullptr)
				{
					cout << "There is no " << key
					<< " in vocabulary.\n";
					system("pause");
					system("cls");
					break;
				}
				PrintNode(findedValue);
				system("pause");
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	system("cls");
}

void HashTableMenu(HashTable *userHashTable)
{
	system("cls");
	string key;
	string value;
	int menuItem;
	do
	{
		system("cls");
		PrintTable(userHashTable);
		cout << endl;
		PrintHashTableMenu();
		do
		{
			cout << "Enter menu item from list above (integer only):";
			menuItem = ReadValue();
			cout << endl;
		}
		while (menuItem > 3 && menuItem < 0);
		switch(menuItem)
		{
			case 1:
			{
				ReadKeyValue(key, value);
				userHashTable->AddKeyValuePair(key, value);
				system("cls");
				break;
			}
			case 2:
			{
				ReadKeyValue(key, value);
				if (!userHashTable->DeletePairByKey(key, value))
				{
					cout << "There is no such value.\n";
				}
				system("pause");
				break;
			}
			case 3:
			{
				Node *findedValue;
				ReadKeyValue(key, value);
				if ((findedValue = userHashTable->Search(key,value)) == nullptr)
				{
					cout << "There is no " << key
						<< ' ' << value << " in vocabulary.\n";
					system("pause");
					break;
				}
				PrintNode(findedValue);
				system("pause");
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	system("cls");
}