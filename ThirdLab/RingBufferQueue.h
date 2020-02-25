#pragma once
#include "DataInOut.h"
#include "RingBuffer.h"

struct RingBufferQueue
{
	RingBuffer Queue;
	bool IsFull;
};

//TODO: глагол в начале названия
void RingBufferQueueCreation(RingBufferQueue *);
void RingQueuePut(RingBufferQueue *, int data);
int RingQueueGet(RingBufferQueue *);