#include "LinkedList.h"
#include "UserInputOutput.h"
#include "../Common/IntegerReading.h"

void Initialize(List *ListRoot)
{
	const int startingLength = 2;
	ListRoot->Head = new Node;
	ListRoot->Tail = new Node;
	ListRoot->Head->Next = ListRoot->Tail;
	ListRoot->Head->Previous = nullptr;
	ListRoot->Tail->Next = nullptr;
	ListRoot->Tail->Previous = ListRoot->Head;
	ListRoot->CurrentNode = ListRoot->Head;
	ListRoot->ListLength = startingLength;
	ListRoot->Head->Field = ReadValue();
	ListRoot->Tail->Field = ReadValue();
}

//TODO: проверить написание слова адрес
//TODO: elementToAdd - неоднозначное название. Можно понять и как значение, и как индекс. Переименовать однозначно
void AddElementes(int valueToAdd, List *listParameters, Node *nodeAddress)
{
	Node *addressOfNewElement = new Node;
	Node *temporaryNodeAddress;
	addressOfNewElement->Field = valueToAdd;
	listParameters->ListLength++;
	if (nodeAddress->Next == nullptr)
	{
		addressOfNewElement->Next = nullptr;
		addressOfNewElement->Previous = nodeAddress;
		nodeAddress->Next = addressOfNewElement;
		listParameters->Tail = addressOfNewElement;
	}
	else if (nodeAddress->Previous == nullptr)
	{
		addressOfNewElement->Next = nodeAddress;
		addressOfNewElement->Previous = nullptr;
		nodeAddress->Previous = addressOfNewElement;
		listParameters->Head = addressOfNewElement;
	}
	else
	{
		temporaryNodeAddress = nodeAddress->Next;
		nodeAddress->Next = addressOfNewElement;
		temporaryNodeAddress->Previous = addressOfNewElement;
		addressOfNewElement->Next = temporaryNodeAddress;
		addressOfNewElement->Previous = nodeAddress;
	}
}

void AddElement(int elementToAdd, List *listParameters, Node *nodeAddres) 
{
	Node *addresOfNewElement = new Node;
	Node *temporaryNodeAddres;
	addresOfNewElement->Field = elementToAdd;
	listParameters->ListLength++;
	if (nodeAddres->Next == nullptr)
	{
		addresOfNewElement->Next = nullptr;
		addresOfNewElement->Previous = nodeAddres;
		nodeAddres->Next = addresOfNewElement;
		listParameters->Tail = addresOfNewElement;
	}
	else if (nodeAddres->Previous == nullptr)
	{
		addresOfNewElement->Next = nodeAddres;
		addresOfNewElement->Previous = nullptr;
		nodeAddres->Previous = addresOfNewElement;
		listParameters->Head = addresOfNewElement;
	}
	else
	{
		temporaryNodeAddres = nodeAddres->Next;
		nodeAddres->Next = addresOfNewElement;
		temporaryNodeAddres->Previous = addresOfNewElement;
		addresOfNewElement->Next = temporaryNodeAddres;
		addresOfNewElement->Previous = nodeAddres;
	}
}

void DeleteElement(List *ListParameters)
{
	if (ListParameters->ListLength == 0)
	{
		cout << "There is no elements in current list." << endl;
	}
	else
	{ 
		Node *previousNode;
		Node *nextNode;
	    Node *nodeAddres = ListParameters->CurrentNode;
		if (ListParameters->CurrentNode->Previous == nullptr)
		{
			nextNode = nodeAddres->Next;
			nextNode->Previous = nullptr;
			ListParameters->Head = nextNode;
		}
		else if (ListParameters->CurrentNode->Next == nullptr)
		{
			previousNode = nodeAddres->Previous;
			previousNode->Next = nullptr;
			ListParameters->Tail = previousNode;
		}
		else
		{
			previousNode = nodeAddres->Previous;
			nextNode = nodeAddres->Next;
			previousNode->Next = nodeAddres->Next;
			nextNode->Previous = nodeAddres->Previous;
		}
		ListParameters->ListLength--;
		delete (nodeAddres);
	}
}

void SwapNode(List* list, Node* current)
{
	if (current == list->Head)
	{
		list->Head = current->Next;
		list->Head->Previous = nullptr;
	}
	else
	{
		current->Previous->Next = current->Next;
		current->Next->Previous = current->Previous;
	}
	Node* temp = current->Next->Next;
	current->Next->Next = current;
	current->Previous = current->Next;
	if (current->Next == list->Tail)
	{
		list->Tail = current;
		list->Tail->Next = nullptr;
	}
	else
	{
		current->Next = temp;
		temp->Previous = current;
	}
}

void Sort(List* list)
{
	for (size_t i = 0; i < list->ListLength; ++i)
	{
		Node* current = list->Head;
		//TODO: для таких условий надо оставлять комментарии.
		//Иначе через два месяца уже никто не будет знать, что делает код

		/*Bubble sort for list*/
		while (current != nullptr && current->Next != nullptr)
		{
			if (current->Field> current->Next->Field)
			{
				SwapNode(list, current);
			}
			current = current->Next;
		}
	}
}

void SearchElement(struct List *listParameters, int elementToSearch)
{
	struct Node * nodeToCheck = listParameters->Head;
	int counter = 0;
	for (int i = 1; i <= listParameters->ListLength; i++)
	{
		if (nodeToCheck->Field == elementToSearch)
		{
			cout << endl << "Match for your number in position: " <<
				i << "; ";
			counter++;
		}
		nodeToCheck = nodeToCheck->Next;
	}
	if (counter == 0)
	{
		cout << endl << "There is no " << elementToSearch << " in list.";
	}
}

void DeleteAllList(List *listParameters)
{
	Node *nodeToDelete = listParameters->Head;
	for (int i = 0; i < listParameters->ListLength; i++)
	{
		nodeToDelete = nodeToDelete->Next;
		delete (listParameters->Head);
		listParameters->Head = nodeToDelete;
	}
}