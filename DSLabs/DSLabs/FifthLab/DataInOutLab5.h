#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include "BinaryTree.h"
#include "Treap.h"

const int EXIT_MENU_ITEM = 0;

using namespace std;
//TODO: именование
void PrintTree(string prefix, Node *node, bool isLeft);
void PrintTree(Node *node);
void PrintTreap(string prefix, TreapNode *node, bool isLeft);
void PrintTreap(TreapNode *node);
void PrintMainMenuLab5();
void PrintBinaryMenu();
void PrintTreapMenu();