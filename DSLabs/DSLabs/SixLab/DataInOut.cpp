#include "DataInOut.h"
#include "../Common/IntegerReading.h"

void PrintTree(string prefix, RedBlackNode *node, bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		wcout << (isLeft ? "|-- " : "\\-- ");
		cout << node->GetKey() << (node->IsRed() ? ": Red" : ": Black") << endl;
		PrintTree(prefix + (isLeft ? "|   " : "    "),
			node->GetLeft(), true);
		PrintTree(prefix + (isLeft ? "|   " : "    "),
			node->GetRight(), false);
	}
}

void PrintTree(RedBlackNode * node)
{
	PrintTree("", node, false);
}

void PrintAVLTree(string prefix, AVLNode * node,  bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		wcout << (isLeft ? "|-- " : "\\-- ");
		cout << node->GetKey() << endl;
		PrintAVLTree(prefix + (isLeft ? "|   " : "    "),
			node->GetLeft(), true);
		PrintAVLTree(prefix + (isLeft ? "|   " : "    "),
			node->GetRight(), false);
	}
}

void PrintAVLTree(AVLNode * node)
{
	PrintAVLTree("", node, false);
}

void PrintMainMenuRBTAVL()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                       ||||||MENU||||||                      |\n";
	cout << "| Choose tree from list below by typing it number.            |\n";
	cout << "| 1. Red-black tree                                           |\n";
	cout << "| 2. AVL-Tree                                                 |\n";
	cout << "| 0. Quit program                                             |\n";
	cout << "|_____________________________________________________________|\n";
}

void PrintRBTMenu()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                   ||||||RBTree MENU||||||                   |\n";
	cout << "| Choose action from list below by typing it number.          |\n";
	cout << "| 1. Add value                                                |\n";
	cout << "| 2. Delete value                                             |\n";
	cout << "| 3. Search value                                             |\n";
	cout << "| 0. Quit                                                     |\n";
	cout << "|_____________________________________________________________|\n";
}

void PrintAVLMenu()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                  ||||||AVL Tree MENU||||||                  |\n";
	cout << "| Choose action from list below by typing it number.          |\n";
	cout << "| 1. Add value                                                |\n";
	cout << "| 2. Delete value                                             |\n";
	cout << "| 3. Search value                                             |\n";
	cout << "| 0. Quit                                                     |\n";
	cout << "|_____________________________________________________________|\n";
}

int GetMenuItem()
{
	int menuItem;
	do
	{
		cout << "Enter menu item from list above (integer only):";
		menuItem = ReadValue();
		cout << endl;
	} 
	while (menuItem > 4 && menuItem < 0);
	return menuItem;
}

