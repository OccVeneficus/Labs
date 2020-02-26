#pragma once

struct Stack
{
	int *Buffer;
	int BufferSize;
	int TopIndex;
	bool Empty;
};

//TODO: именование не от глагола
void CreateStack(Stack* stack);
void PushInStack(Stack* stack, int valueToPush);
void DeleteStack(Stack* stack);
int PopFromStack(Stack* stack);