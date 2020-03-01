#include "DataInOut.h"

bool CheckForInteger(string value)
{
	int size = value.length();
	if (isdigit((unsigned char)value[0]) || (unsigned char)value[0] == '-')
	{
		for (int i = 1; i < size; i++)
		{
			if (!isdigit((unsigned char)value[i]))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

int ReadValue()
{
	string inputValue;
	int outputValue;
	while (true)
	{
		getline(cin, inputValue);
		bool intCheckFlag = CheckForInteger(inputValue);
		istringstream inputStringStream(inputValue);
		int number;
		inputStringStream >> number;
		if (intCheckFlag == false || inputStringStream.fail())
		{
			cout << endl << "Wrong input, try again.You can use only integer:";
			inputValue.clear();
		}
		else
		{
			outputValue = stoi(inputValue);
			return outputValue;
		}
	}
}

void PrintMainMenu()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                       ||||||MENU||||||                      |\n";
	cout << "| Choose option from list below by typing it number.          |\n";
	cout << "| 1. Binary Search Tree                                       |\n";
	cout << "| 2. Treap                                                    |\n";
	cout << "| 0. Quit program                                             |\n";
	cout << "|_____________________________________________________________|\n";
}

void PrintBinaryMenu()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                    ||||||BINARY TREE||||||                  |\n";
	cout << "| Choose option from list below by typing it number.          |\n";
	cout << "| 1. Add value                                                |\n";
	cout << "| 2. Delete value                                             |\n";
	cout << "| 3. Search value                                             |\n";
	cout << "| 4. Search minimum                                           |\n";
	cout << "| 5. Search maximum                                           |\n";
	cout << "| 0. Quit program                                             |\n";
	cout << "|_____________________________________________________________|\n";
}

void PrintTreapMenu()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                       ||||||TREAP||||||                     |\n";
	cout << "| Choose option from list below by typing it number.          |\n";
	cout << "| 1. Add value (split, merge x 2)                             |\n";
	cout << "| 2. Delete value (split x2, merge)                           |\n";
	cout << "| 3. Search value                                             |\n";
	cout << "| 4. Add value (optimised)                                    |\n";
	cout << "| 5. Delete value (optimised)                                 |\n";
	cout << "| 0. Quit program                                             |\n";
	cout << "|_____________________________________________________________|\n";
}

void PrintTree(string prefix, Node *node, bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		wcout << (isLeft ? "|-- " : "\\-- ");
		cout << node->GetData() << endl;
		PrintTree(prefix + (isLeft ? "|   " : "    "),
			node->GetLeft(), true);
		PrintTree(prefix + (isLeft ? "|   " : "    "),
			node->GetRight(), false);
	}
}

void PrintTree(Node * node)
{
	PrintTree("", node, false);
}

void PrintTreap(string prefix, TreapNode *node, bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		wcout << (isLeft ? "|-- " : "\\-- ");
		cout << node->GetKey() <<" ; "<< node->GetPriority()<<  endl;
		PrintTreap(prefix + (isLeft ? "|   " : "    "),
			node->GetLeft(), true);
		PrintTreap(prefix + (isLeft ? "|   " : "    "),
			node->GetRight(), false);
	}
}

void PrintTreap(TreapNode *node)
{
	PrintTreap("", node, false);
}
