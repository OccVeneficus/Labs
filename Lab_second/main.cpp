#include "LinkedList.h"
#include "UserInputOutput.h"
#include "UserInterface.h"
#include <cstdlib>

const int EXIT_MENU_ITEM = 8;

int main()
{
	List listParameters;
	int menuItem;
	cout << "Enter Head and Tail of new list." << endl;
	Initialize(&listParameters);
	do
	{
		PrintList(&listParameters);
		PrintMenu();
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
				ChoosePosition(&listParameters);
				DeleteElement(&listParameters);
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Enter value you want to add in the begining of list:";
				AddElement(ReadValue(), &listParameters,
					listParameters.Head);
				break;
			}
			case 3:
			{
				system("cls");
				cout << "Enter value you want to add in the end of list: ";
				AddElement(ReadValue(), &listParameters,
					listParameters.Tail);
				break;
			}
			case 4:
			{
				system("cls");
				if (ChoosePosition(&listParameters) == false)
				{
					cout << "There is no elements in list yet.";
					break;
				}
				cout << endl << "Enter value: ";
				AddElement(ReadValue(), &listParameters,
					listParameters.CurrentNode);
				break;
			}
			case 5:
			{
				system("cls");
				if (ChoosePosition(&listParameters) == false)
				{
					cout << "There is no elements in list yet.";
					break;
				}
				cout << endl << "Enter value: ";
				AddElement(ReadValue(), &listParameters,
					listParameters.CurrentNode->Previous);
				break;
			}
			case 6:
			{
				system("cls");
				Sort(&listParameters);
				break;
			}
			case 7:
			{
				system("cls");
				cout << "Enter value you want to find." << endl;
				SearchElement(&listParameters, ReadValue());
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	DeleteAllList(&listParameters);
	return 0;
}