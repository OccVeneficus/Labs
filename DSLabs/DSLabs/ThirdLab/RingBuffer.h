#pragma once
#include "BufferNode.h"

struct RingBuffer
{
	BufferNode *IndexIn;
	BufferNode *IndexOut;
	int BufferSize;
	BufferNode *Head;
	int FreeSpace;
	int OccupiedSpace;
};

//TODO: именование от глагола
void CreateRingBuffer(RingBuffer* buffer);
void BufferInitialisation(RingBuffer* buffer);
void RingBufferPut(RingBuffer* buffer, int value);
int RingBufferGet(RingBuffer* buffer);
void RingBufferDelete(RingBuffer* buffer);