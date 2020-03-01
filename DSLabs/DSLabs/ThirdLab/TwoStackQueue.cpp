#include "DataInOutLab3.h"
#include "Stack.h"
#include "TwoStackQueue.h"

int GetFromTwoStack(TwoStackQueue *queue)
{
	int value;
	if (queue->ToPop.Empty)
	{
		while (!(queue->ToPush.Empty))
		{
			value = PopFromStack(&queue->ToPush);
			PushInStack(&queue->ToPop, value);
		}
	}
	return PopFromStack(&queue->ToPop);
}

void PushToTwoStack(TwoStackQueue *queue , int value)
{
	PushInStack(&queue->ToPush, value);
}