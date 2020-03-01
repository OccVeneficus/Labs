#pragma once
#include "DataInOutLab3.h"
#include "RingBuffer.h"

struct RingBufferQueue
{
	RingBuffer Queue;
	bool IsFull;
};

//TODO: глагол в начале названия
void CreateRingBufferQueue(RingBufferQueue* queue);
void RingQueuePut(RingBufferQueue* queue, int value);
int RingQueueGet(RingBufferQueue* queue);