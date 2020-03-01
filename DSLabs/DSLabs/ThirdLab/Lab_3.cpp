#include "DataInOutLab3.h"
#include "Stack.h"
#include "RingBuffer.h"
#include "TwoStackQueue.h"
#include "MenusLab3.h"
#include "../Common/Consts.h"
#include "../Common/IntegerReading.h"

void Lab_3()
{
	Stack currentStack;
	currentStack.Empty = true;
	CreateStack(&currentStack);
	int menuItem;
	do
	{
		PrintMainMenuLab3();
		do
		{
			cout << ">";
			menuItem = ReadValue();
		} 
		while (menuItem > 4 || menuItem < 0);
		switch (menuItem)
		{
			case 1:
			{
				system("cls");
				StackMenu(&currentStack);
				break;
			}
			case 2:
			{
				system("cls");
				RingBufferMenu();
				break;
			}
			case 3:
			{
				system("cls");
				TwoStackQueueMenu();
				break;
			}
			case 4:
			{
				system("cls");
				RingBufferQueueMenu();
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM_LAB3);
	DeleteStack(&currentStack);
}