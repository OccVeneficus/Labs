#include "RingBufferQueue.h"

//TODO: именование входного аргумента (здесь и далее)
void CreateRingBufferQueue(RingBufferQueue *queue)
{
	CreateRingBuffer(&queue->Queue);
	queue->IsFull = false;
}

void RingQueuePut(RingBufferQueue *queue, int value)
{
	if (queue->IsFull)
	{
		int newSize = queue->Queue.BufferSize * 1.5;
		RingBufferQueue newQueue;
		int userBufferSize;
		BufferInitialisation(&newQueue.Queue);
		newQueue.Queue.BufferSize = newSize;
		newQueue.Queue.OccupiedSpace = 0;
		newQueue.Queue.FreeSpace = newSize;
		BufferNode *node = newQueue.Queue.Head;
		for (int i = 0; i < newSize - 1; i++)
		{
			BufferNode *addedNode = new BufferNode;
			BufferNode *tempNode = node->NextBufferNode;
			node->NextBufferNode = addedNode;
			addedNode->NextBufferNode = tempNode;
			node = addedNode;
		}
		while (queue->Queue.OccupiedSpace != 0)
		{
			RingBufferPut(&newQueue.Queue, RingBufferGet(&queue->Queue));
		}
		queue->Queue = newQueue.Queue;
	}
	RingBufferPut(&queue->Queue, value);
	if (queue->Queue.OccupiedSpace == queue->Queue.BufferSize)
	{
		queue->IsFull = true;
	}
	else
	{
		queue->IsFull = false;
	}
}

int RingQueueGet(RingBufferQueue *queueParameters)
{
	return RingBufferGet(&queueParameters->Queue);
}
