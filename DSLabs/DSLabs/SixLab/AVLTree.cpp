#include "AVLTree.h"
#include "AVLNode.h"

int AVLTree::GetHeight(AVLNode *root)
{
	if (root == nullptr)
	{
		return -1;
	}
	return root->_height;
}

AVLTree::AVLTree()
{
	this->_root = nullptr;
}

int AVLTree::GetRotationCounter()
{
	return this->_rotationCounter;
}

AVLNode * AVLTree::GetRoot()
{
	return this->_root;
}
//TODO: просто Max()
int AVLTree::Max(int first, int second)
{
	return (first > second) ? first : second;
}

AVLNode *AVLTree::RotateRight(AVLNode *&subtreeToRotate)
{
	AVLNode *toRotateLeft = subtreeToRotate->_left;
	subtreeToRotate->_left = toRotateLeft->_right;
	toRotateLeft->_right = subtreeToRotate;
	subtreeToRotate->_height = Max(GetHeight(subtreeToRotate->_left),
		GetHeight(subtreeToRotate->_right))+ 1;
	toRotateLeft->_height = Max(GetHeight(toRotateLeft->_left),
		GetHeight(subtreeToRotate)) + 1;
	_rotationCounter++;
	return toRotateLeft;
}

AVLNode * AVLTree::RotateLeft(AVLNode *&subtreeToRotate)
{
	AVLNode *toRotateRight = subtreeToRotate->_right;
	subtreeToRotate->_right = toRotateRight->_left;
	toRotateRight->_left = subtreeToRotate;
	subtreeToRotate->_height = Max(GetHeight(subtreeToRotate->_left),
		GetHeight(subtreeToRotate->_right)) + 1;
	toRotateRight->_height = Max(GetHeight(subtreeToRotate->_right),
		GetHeight(subtreeToRotate)) + 1;
	_rotationCounter++;
	return toRotateRight;
}
//TODO: именование аргументов
AVLNode * AVLTree::BigRotateLeft(AVLNode *& subtreeToRotate)
{
	subtreeToRotate->_right = RotateRight(subtreeToRotate->_right);
	return RotateLeft(subtreeToRotate);
}

AVLNode * AVLTree::BigRotateRight(AVLNode *& subtreeToRotate)
{
	subtreeToRotate->_left = RotateLeft(subtreeToRotate->_left);
	return RotateRight(subtreeToRotate);
}

AVLNode * AVLTree::InsertAVLNode(int key, AVLNode *root)
{
	if (root == nullptr)
	{
		root = new AVLNode(key);
	}
	else if (key < root->_key)
	{
		root->_left = InsertAVLNode(key, root->_left);
		if ((GetHeight(root->_left) - GetHeight(root->_right)) == 2)
		{
			if (key < root->_left->_key)
			{
				root = RotateRight(root);
			}
			else
			{
				root = BigRotateRight(root);
			}
		}
	}
	else if (key > root->_key)
	{
		root->_right = InsertAVLNode(key, root->_right);
		if ((GetHeight(root->_right) - GetHeight(root->_left)) == 2)
		{
			if (key > root->_right->_key)
			{
				root = RotateLeft(root);
			}
			else
			{
				root = BigRotateLeft(root);
			}
		}
	}
	root->_height = Max(GetHeight(root->_left),
		GetHeight(root->_right)) + 1;
	return root;
}

AVLNode * AVLTree::RemoveAVLNode(int key, AVLNode * root)
{
	AVLNode *tempAVLNode;
	if (root == nullptr)
	{
		return nullptr;
	}
	else if (key < root->_key)
	{
		root->_left = RemoveAVLNode(key, root->_left);
	}
	else if (key > root->_key)
	{
		root->_right = RemoveAVLNode(key, root->_right);
	}
	else if (root->_left && root->_right)
	{
		tempAVLNode = FindMinimum(root->_right);
		root->_key = tempAVLNode->_key;
		root->_right = RemoveAVLNode(root->_key, root->_right);
	}
	else
	{
		tempAVLNode = root;
		if (root->_left == nullptr)
		{
			root = root->_right;
		}
		else if (root->_right == nullptr)
		{
			root = root->_left;
		}
		delete tempAVLNode;
	}
	if (root == nullptr)
	{
		return root;
	}
	root->_height = Max(GetHeight(root->_left),
		GetHeight(root->_right)) + 1;
	if ((GetHeight(root->_left) - GetHeight(root->_right)) == 2)
	{
		if ((GetHeight(root->_left->_left) -
			GetHeight(root->_right->_right)) == 1)
		{
			return RotateLeft(root);
		}
		else
		{
			return BigRotateLeft(root);
		}
	}
	else if ((GetHeight(root->_right) - GetHeight(root->_left)) == 2)
	{
		if ((GetHeight(root->_right->_right) -
			GetHeight(root->_left->_left)) == 1)
		{
			return RotateRight(root);
		}
		else
		{
			return BigRotateRight(root);
		}
	}
	return root;
}

AVLNode * AVLTree::FindMinimum(AVLNode * root)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	else if (root->_left == nullptr)
	{
		return root; //возврат из метода произойдет в любом случае
	}
	else
	{//TODO: return? 
		//рекурсия. вызывает сам себя (в качестве параметра левый элемент от текущего,
		//возвращает его если следующий левый nullptr)
		//root в смысле корень ветки в которой нужно искать минимум, с него начинаем, он
		//в рекурсии меняестся и его и возвращаем, возможно стоит переименовать на 
		// например minimum
		FindMinimum(root->_left);
	}
}

void AVLTree::DeleteTree(AVLNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	DeleteTree(root->_left);
	DeleteTree(root->_right);
	delete root;
}

void AVLTree::Insert(int key)
{
	_rotationCounter = 0;
	_root = InsertAVLNode(key, _root);
}

void AVLTree::Delete(int key)
{
	_rotationCounter = 0;
	_root = RemoveAVLNode(key, _root);
}

AVLNode * AVLTree::SearchByKey(int key, AVLNode * root)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (key == root->_key)
	{
		return root;
	}
	if (key < root->_key)
	{
		SearchByKey(key, root->_left);
	}
	else if (key > root->_key)
	{
		SearchByKey(key, root->_right);
	}
}

AVLTree::~AVLTree()
{
	DeleteTree(this->_root);
}
