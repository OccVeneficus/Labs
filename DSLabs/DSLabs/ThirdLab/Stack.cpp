#include "DataInOutLab3.h"
#include "Stack.h"
#include "TwoStackQueue.h"

//TODO: именование входного аргумента (здесь и далее)
void CreateStack(Stack *stack)
{
	stack->Buffer = new int[BUFFER];
	stack->BufferSize = BUFFER;
	stack->TopIndex = -1;
	stack->Empty = true;
}

void StackBufferRecreation(Stack *stack)
{
	int newSize = stack->BufferSize*1.5;
	stack->BufferSize = newSize;
	int *newBuffer = new int[newSize];
	for (int i = 0; i <= stack->TopIndex; i++)
	{
		newBuffer[i] = stack->Buffer[i];
	}
	delete[] stack->Buffer;
	stack->Buffer = newBuffer; 
}

void PushInStack(Stack *stack, int valueToPush)
{
	if (stack->BufferSize == stack->TopIndex + 1)
	{
		cout << "Stack is full." << endl;
	}
	else
	{
		stack->TopIndex++;
		stack->Buffer[stack->TopIndex] = valueToPush;
		stack->Empty = false;
	}
}

void DeleteStack(Stack *stack)
{
	delete[] stack->Buffer;
	CreateStack(stack);
}

int PopFromStack(Stack *stack)
{
	int valueToPop = stack->Buffer[stack->TopIndex];
	stack->TopIndex--;
	if (stack->TopIndex == -1)
	{
		stack->Empty = true;
	}
	return valueToPop;
}