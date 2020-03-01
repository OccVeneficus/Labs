#include "Menus.h"
#include "../Common/IntegerReading.h"

void RBTMenu(RedBlackTree *userTree)
{
	system("cls");
	int menuItem;
	do
	{
		system("cls");
		cout << "Current Red-black tree:\n";
		PrintTree(userTree->GetRoot());
		cout << endl;
		PrintRBTMenu();
		menuItem = GetMenuItem();
		switch (menuItem)
		{
			case 1:
			{
				cout << "Enter value to add:";
				std::chrono::steady_clock::time_point begin = 
					std::chrono::steady_clock::now();
				userTree->InsertNode(ReadValue(), userTree->GetRoot());
				std::chrono::steady_clock::time_point end = 
					std::chrono::steady_clock::now();
				std::cout << "Time difference = " <<
					std::chrono::duration_cast<std::chrono::nanoseconds>
					(end - begin).count() << "[ns]" << std::endl;
				cout << "\nRotations: " << userTree->GetRotationCounter();
				system("pause");
				break;
			}
			case 2:
			{
				cout << "Enter value to delete:";
				std::chrono::steady_clock::time_point begin = 
					std::chrono::steady_clock::now();
				userTree->DeleteByKey(ReadValue());
				std::chrono::steady_clock::time_point end =
					std::chrono::steady_clock::now();
				std::cout << "Time difference = " <<
					std::chrono::duration_cast<std::chrono::nanoseconds> 
					(end - begin).count() << "[ns]" << std::endl;
				cout << "\nRotations: " << userTree->GetRotationCounter();
				system("pause");
				break;
			}
			case 3:
			{
				cout << "Enter value you want to find:";
				int value = ReadValue();
				std::chrono::steady_clock::time_point begin = 
					std::chrono::steady_clock::now();
				if (userTree->SearchByKey(userTree->GetRoot(), value) != nullptr)
				{
					std::chrono::steady_clock::time_point end = 
						std::chrono::steady_clock::now();
					std::cout << "Time difference = " << 
						std::chrono::duration_cast<std::chrono::nanoseconds> 
						(end - begin).count() << "[ns]" << std::endl;
					cout << "Finded: " << value;
				}
				else
				{
					std::chrono::steady_clock::time_point end = 
						std::chrono::steady_clock::now();
					std::cout << "Time difference = " << 
						std::chrono::duration_cast<std::chrono::nanoseconds> 
						(end - begin).count() << "[ns]" << std::endl;
					cout << "There is no " << value;
				}
				system("pause");
				break;
			}
			case 4:
			{
				cout << "Enter element quantity: ";
				int quantity = ReadValue();
				for (int i = 0; i < quantity; i++)
				{
					userTree->InsertNode(rand()%1000, userTree->GetRoot());
				}
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	system("cls");
}

void AVLMenu(AVLTree * userTree)
{
	system("cls");
	int menuItem;
	do
	{
		system("cls");
		cout << "Current AVL Tree:\n";
		PrintAVLTree(userTree->GetRoot());
		cout << endl;
		PrintAVLMenu();
		menuItem = GetMenuItem();
		switch (menuItem)
		{
			case 1:
			{
				cout << "Enter value to add:";
				std::chrono::steady_clock::time_point begin = 
					std::chrono::steady_clock::now();
				userTree->Insert(ReadValue());
				std::chrono::steady_clock::time_point end 
					= std::chrono::steady_clock::now();
				std::cout << "Time difference = " <<
					std::chrono::duration_cast<std::chrono::nanoseconds>
					(end - begin).count() << "[ns]" << std::endl;
				cout << "\nRotations: " << userTree->GetRotationCounter();
				system("pause");
				break;
			}
			case 2:
			{
				cout << "Enter value to delete:";
				std::chrono::steady_clock::time_point begin =
					std::chrono::steady_clock::now();
				userTree->Delete(ReadValue());
				std::chrono::steady_clock::time_point end =
					std::chrono::steady_clock::now();
				std::cout << "Time difference = " <<
					std::chrono::duration_cast<std::chrono::nanoseconds> 
					(end - begin).count() << "[ns]" << std::endl;
				cout << "\nRotations: " << userTree->GetRotationCounter();
				system("pause");
				break;
			}
			case 3:
			{
				cout << "Enter value you want to find:";
				int value = ReadValue();
				std::chrono::steady_clock::time_point begin =
					std::chrono::steady_clock::now();
				if (userTree->SearchByKey(value, userTree->GetRoot()) != nullptr)
				{
					std::chrono::steady_clock::time_point end =
						std::chrono::steady_clock::now();
					std::cout << "Time difference = " <<
						std::chrono::duration_cast<std::chrono::nanoseconds> 
						(end - begin).count() << "[ns]" << std::endl;
					cout << "Finded: " << value;
				}
				else
				{
					std::chrono::steady_clock::time_point end =
						std::chrono::steady_clock::now();
					std::cout << "Time difference = " <<
						std::chrono::duration_cast<std::chrono::nanoseconds> 
						(end - begin).count() << "[ns]" << std::endl;
					cout << "There is no " << value;
				}
				system("pause");
				break;
			}
			case 4:
			{
				cout << "Enter element quantity: ";
				int quantity = ReadValue();
				for (int i = 0; i < quantity; i++)
				{
					userTree->Insert(rand() % 1000);
				}
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	system("cls");
}
