#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime> 
#include "RedBlackTree.h"
#include "AVLTree.h"

const int EXIT_MENU_ITEM = 0;

using namespace std;

void PrintTree(string prefix, RedBlackNode *node, bool isLeft);
void PrintTree(RedBlackNode * node);
void PrintAVLTree(string prefix, AVLNode *node, bool isLeft);
void PrintAVLTree(AVLNode * node);
void PrintMainMenuRBTAVL();
void PrintRBTMenu();
void PrintAVLMenu();
int GetMenuItem();