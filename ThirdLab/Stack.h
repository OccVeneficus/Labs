#pragma once

struct Stack
{
	int *Buffer;
	int BufferSize;
	int TopIndex;
	bool Empty;
};

//TODO: именование не от глагола
void StackCreation(Stack *);
void StackPush(Stack *, int);
void DeletingStack(Stack *);
int StackPop(Stack *);