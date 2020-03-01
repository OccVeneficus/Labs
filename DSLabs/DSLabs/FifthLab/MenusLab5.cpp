#include "MenusLab5.h"
#include "../Common/IntegerReading.h"
#include "../Common/Consts.h"
void MainMenu()
{
	BinaryTree userTree;
	Treap userTreap;
	int menuItem;
	do
	{
		PrintMainMenuLab5();
		do
		{
			cout << "Choose number from list above(integer only):";
			menuItem = ReadValue();
		} 
		while (menuItem > 2 || menuItem < 0);
		switch (menuItem)
		{
		case 1:
			{
				system("cls");
				BinaryTreeMenu(&userTree);
				system("cls");
				break;
			}
		case 2:
			{
				system("cls");
				TreapMenu(&userTreap);
				system("cls");
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM_LAB5);
	system("cls");
}

void BinaryTreeMenu(BinaryTree *userTree)
{
	int menuItem;
	Node *toShow;
	do
	{
		int value;
		system("cls");
		PrintTree(userTree->GetRoot());
		PrintBinaryMenu();
		do
		{
			cout << "Choose number from list above(integer only):";
			menuItem = ReadValue();
		}
		while (menuItem > 5 || menuItem < 0);
		switch (menuItem)
		{
		case 1:
			{
				cout << "Enter value you want to add: ";
				value = ReadValue();
				userTree->AddNode(value);
				break;
			}
		case 2:
			{
				cout << "Enter value you want to delete:";
				value = ReadValue();
				Node *root = userTree->GetRoot();
				userTree->DeleteNode(value, root);
				break;
			}
		case 3:
			{
				cout << "Enter value you want to search:";
				value = ReadValue();
				if ((toShow = userTree->SearchNode(value, userTree->GetRoot()))
					!= nullptr)
				{
					cout << "Finded: " << toShow->GetData();
					system("pause");
					break;
				}
				cout << "There is no " << value << " in this tree.";
				system("pause");
				break;
			}
		case 4:
			{
				if (userTree->GetRoot() == nullptr)
				{
					cout << "No elements in this tree. ";
					system("pause");
					break;
				}
				cout << "Minimum element = " << 
					userTree->SearchMin()->GetData() << " .";
				system("pause");
				break;
			}
		case 5:
			{
				if (userTree->GetRoot() == nullptr)
				{
					cout << "No elements in this tree. ";
					system("pause");
					break;
				}
				cout << "Maximum element = " <<
					userTree->SearchMax()->GetData() << " .";
				system("pause");
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM_LAB5);
	system("cls");
}

void TreapMenu(Treap *userTreap)
{
	int menuItem;
	TreapNode *toShow;
	do
	{
		int value;
		system("cls");
		PrintTreap(userTreap->GetRoot());
		PrintTreapMenu();
		do
		{
			cout << "Choose number from list above(integer only):";
			menuItem = ReadValue();
		} 
		while (menuItem > 5 || menuItem < 0);
		switch (menuItem)
		{
		case 1:
			{
				cout << "Enter value you want to add: ";
				value = ReadValue();
				userTreap->Add(value);
				break;
			}
		case 2:
			{
				cout << "Enter value you want to delete:";
				value = ReadValue();
				userTreap->Remove(value);
				break;
			}
		case 3:
		{
			cout << "Enter value you want to search:";
			value = ReadValue();
			if ((toShow = userTreap->Search(value, userTreap->GetRoot()))
				!= nullptr)
			{
				cout << "Finded: " << toShow->GetKey();
				system("pause");
				break;
			}
			cout << "There is no " << value << " in this tree.";
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Enter value you want to add: ";
			value = ReadValue();
			TreapNode *newNode = new TreapNode(value, rand()%100);
			toShow = userTreap->GetRoot();
 			userTreap->OptimisedAdd(toShow, newNode);
			break;
		}
		case 5:
		{
			cout << "Enter value you want to delete:";
			value = ReadValue();
			toShow = userTreap->GetRoot();
			userTreap->OptimisedRemove(value, toShow);
			break;
		}
		}
	} while (menuItem != EXIT_MENU_ITEM_LAB5);
	system("cls");
}