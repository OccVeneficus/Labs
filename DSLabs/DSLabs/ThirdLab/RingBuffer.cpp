#include "RingBuffer.h"
#include "DataInOutLab3.h"
#include "../Common/IntegerReading.h"

//TODO: именование входного аргумента (здесь и далее)
void BufferInitialisation(RingBuffer *buffer)
{
	BufferNode *rootNode = new BufferNode;
	buffer->Head = rootNode;
	buffer->Head->NextBufferNode = buffer->Head;
	buffer->IndexIn = buffer->Head;
	buffer->IndexOut = buffer->Head;
}

void CreateRingBuffer(RingBuffer *buffer)
{
	int userBufferSize;
	BufferInitialisation(buffer);
	do
	{
		cout << endl << "Enter buffer size (only positive integer):";
		userBufferSize = ReadValue();
	} 
	while (userBufferSize <= 0);
	buffer->BufferSize = userBufferSize;
	buffer->FreeSpace = userBufferSize;
	buffer->OccupiedSpace = 0;
	BufferNode *node = buffer->Head;
	for (int i = 0; i < userBufferSize - 1; i++)
	{
		BufferNode *addedNode = new BufferNode;
		BufferNode *tempNode = node->NextBufferNode;
		node->NextBufferNode = addedNode;
		addedNode->NextBufferNode = tempNode;
		node = addedNode;
	}
}

void RingBufferPut(RingBuffer *buffer, int value)
{
	buffer->IndexIn->Data = value;
	buffer->IndexIn->Useful = true;
	buffer->IndexIn = buffer->IndexIn->NextBufferNode;
	buffer->FreeSpace--;
	buffer->OccupiedSpace++;
	if (buffer->OccupiedSpace > buffer->BufferSize)
	{
		buffer->FreeSpace = 0;
		buffer->OccupiedSpace = buffer->BufferSize;
		buffer->IndexOut = buffer->IndexOut->NextBufferNode;
	}
}

int RingBufferGet(RingBuffer *buffer)
{
	BufferNode *tempNode = buffer->IndexOut;
	buffer->IndexOut->Useful = false;
	buffer->IndexOut = buffer->IndexOut->NextBufferNode;
	buffer->FreeSpace++;
	buffer->OccupiedSpace--;
	return tempNode->Data;
}

void RingBufferDelete(RingBuffer *buffer)
{
	BufferNode *nodeToDelete = buffer->Head;
	for (int i = 0; i < buffer->BufferSize; i++)
	{
		nodeToDelete = nodeToDelete->NextBufferNode;
		delete buffer->Head;
		buffer->Head = nodeToDelete;
	}
}
