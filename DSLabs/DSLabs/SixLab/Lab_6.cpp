#include "DataInOut.h"
#include "Menus.h"
#include "../Common/IntegerReading.h"
#include "../Common/Consts.h"

void Lab_6()
{
	srand(time(nullptr));
	RedBlackTree userTree;
	AVLTree userAVLTree;
	int menuItem;
	do
	{
		system("cls");
		PrintMainMenuRBTAVL();
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
				RBTMenu(&userTree);
				break;
			}
			case 2:
			{
				AVLMenu(&userAVLTree);
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM_LAB6);
	system("cls");
}