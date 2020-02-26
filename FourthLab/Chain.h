#pragma once
#include "Node.h"
class Chain
{
private:
	int _size;
	Node *_head; //TODO: при смене модификатора стоит отделять пустой строкой

public:
	Chain();
	~Chain();
	Chain & operator=(const Chain & toAssign);
	void AddToEnd(string key, string value);
	//TODO: не нужно делать более одной пустой строки
	void DeleteNode(Node *nodeToDelete);
	void DeleteHeadNode();
	int GetSize()
	{
		return _size;
	}
	Node *GetNode(int index);
	Node *Search(string key , string value);
	Node *Search(string key);
};