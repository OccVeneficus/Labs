#include "DataInOutLab4.h"

void PrintDictionaryMenuText()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                 ||||||DICTIONARY MENU||||||                 |\n";
	cout << "| 1. Add key-value pair                                       |\n";
	cout << "| 2. Delete key                                               |\n";
	cout << "| 3. Search key                                               |\n";
	cout << "| 0. Quit                                                     |\n";
	cout << "|_____________________________________________________________|\n";
}

void PrintHashTableMenu()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                 ||||||HASH TABLE MENU||||||                 |\n";
	cout << "| 1. Add key-value pair                                       |\n";
	cout << "| 2. Delete key-value pair                                    |\n";
	cout << "| 3. Search key-value pair                                    |\n";
	cout << "| 0. Quit                                                     |\n";
	cout << "|_____________________________________________________________|\n";
}

string InputString()
{
	string toRead;
	getline(cin, toRead);
	return toRead;
}

void PrintDeleteFailMessage()
{
	cout << "Failed to delete element from table."<<
		" Perhaps there is no such value.";
}

void PrintAddingFailMessage()
{
	cout << "Value already in this vocalbulary."<<
		" You can`t add a duplicate.\n";
	system("pause");
}

void ReadKeyValue(string & key, string & value)
{
	ReadStringKey(key);
	ReadStringValue(value);
}

void ReadStringKey(string & key)
{
	cout << "Key: ";
	getline(cin, key);
}

void ReadStringValue(string & value)
{
	cout << "Value: ";
	getline(cin, value);
}

void PrintMainMenuLab4()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                       ||||||MENU||||||                      |\n";
	cout << "| 1. Dictionary                                               |\n";
	cout << "| 2. Hashtable                                                |\n";
	cout << "| 0. Quit program                                             |\n";
	cout << "|_____________________________________________________________|\n";
}
