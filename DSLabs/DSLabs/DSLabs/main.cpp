#include "../Common/Consts.h"
#include "../Common/IntegerReading.h"
#include "Lab_1.h"
#include "Lab_2.h"
#include "Lab_3.h"
#include "Lab_4.h"
#include <iostream>

using namespace std;

int main()
{
	int menuItem;
	system("cls");
	do
	{
		do
		{
			cout << "Enter menu item from list above (integer only):";
			menuItem = ReadValue();
			cout << endl;
		} while (menuItem > 6 && menuItem < 0);
		switch (menuItem)
		{
			case 1:
			{
				Lab_1();
				break;
			}
			case 2:
			{
				Lab_2();
				break;
			}
			case 3:
			{
				Lab_3();
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM_MAIN);
	return 0;
}