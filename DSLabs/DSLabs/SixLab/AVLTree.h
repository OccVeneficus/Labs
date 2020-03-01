#pragma once
#include "AVLNode.h"

class AVLTree
{
private:
	AVLNode *_root;
	int GetHeight(AVLNode *root);
	int Max(int first, int second);
	AVLNode *RotateRight(AVLNode *& subtreeToRotate);
	AVLNode *RotateLeft(AVLNode *& subtreeToRotate);
	AVLNode *BigRotateLeft(AVLNode *& subtreeToRotate);
	AVLNode *BigRotateRight(AVLNode *& subtreeToRotate);
	AVLNode *InsertAVLNode(int key, AVLNode *root);
	AVLNode *RemoveAVLNode(int key, AVLNode *root);
	AVLNode *FindMinimum(AVLNode *root);
	void DeleteTree(AVLNode *root);
	int _rotationCounter; //TODO: пустые строки

public:
	AVLTree();
	int GetRotationCounter();
	AVLNode *GetRoot();
	void Insert(int key);
	void Delete(int key);
	AVLNode *SearchByKey(int key, AVLNode *root);
	~AVLTree();
};

