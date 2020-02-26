#pragma once
//TODO: зачем здесь эта библиотека?
//#include <iostream>

//TODO: зачем?
//using namespace std;

struct DynamicArray
{
	int Length;
	int Capacity;
	int *Array;
};

//TODO: в прототипах нужно указывать имена переменных
void DeleteArray(int* userArray);
void CreateArray(DynamicArray& userArray);
void PrintArray(DynamicArray& userArray);
void PrintMenuText();
void DeleteElement(DynamicArray& userArray);
void AddAfterIndex(DynamicArray& userArray, int index);
void SortArray(DynamicArray& userArray);
void LinearSearch(DynamicArray& userArray);
void BinarSearch(DynamicArray& userArray);
void RecreateArray(DynamicArray& userArray);
int ReadValue();