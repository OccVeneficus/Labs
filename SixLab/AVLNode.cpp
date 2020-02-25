#include "AVLNode.h"
//TODO: пустые строки


int AVLNode::GetKey()
{
	return this->_key;
}

AVLNode * AVLNode::GetLeft()
{
	return this->_left;
}

AVLNode * AVLNode::GetRight()
{
	return this->_right;
}

AVLNode::AVLNode(int key)
{
	this->_key = key;
	this->_height = 0;
	this->_left = nullptr;
	this->_right = nullptr;
}

