#pragma once
#include "NodeLab5.h"

class BinaryTree
{
private:
	Node *_root = nullptr;
	void DeleteTree(Node *toDelete);
public:
	BinaryTree();
	~BinaryTree();
	Node *GetRoot();
	void AddNode(int data, Node *parent = nullptr);
	Node *DeleteNode(int data, Node *&toDelete);
	Node *SearchMax(Node *toCheck = nullptr);
	Node *SearchMin(Node *toCheck = nullptr);
	Node *SearchNode(int data, Node *toCheck);
};

