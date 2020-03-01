#pragma once
//именование файла не в множественном числе
#include <iostream>
#include <ctime>

struct Node
{
	int Field;
	struct Node * Previous;
	struct Node * Next;
};

struct List
{
	int ListLength;
	Node *Head;
	Node *Tail;
	Node *CurrentNode;
};

//TODO: именование не от глагола
void Initialize(List *);
void AddElement(int , List *, Node *);
void DeleteElement(List *);
void Sort(List*);
void SwapNode(List*, Node*);
void SearchElement(struct List *, int);
void DeleteAllList(List *);
void AddElementes(int, List *, Node *);