#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <stdlib.h>

typedef unsigned int uint;

using namespace std;

const int EXIT_MENU_ITEM = 0;

//TODO: именование
bool CheckForInteger(string value);
int ReadValue();
void PrintDictionaryMenuText();
void PrintHashTableMenu();
string InputString();
void PrintDeleteFailMessage();
void PrintAddingFailMessage();
void ReadKeyValue(string &key, string &value);
void ReadStringKey(string &key);
void ReadStringValue(string &value);
void PrintMainMenuLab4();