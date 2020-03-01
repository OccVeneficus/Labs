#include "Vocabulary.h"
#include "DataInOutLab4.h"

void Dictionary::AddKeyValuePair(string key, string value)
{
	if (AssociativeArray.Search(key) != nullptr)
	{
		PrintAddingFailMessage();
	}
	else
	{
		AssociativeArray.AddKeyValuePair(key, value);
	}
}

void Dictionary::DeletePairByKey(string key)
{
	if (!AssociativeArray.DeletePairByKey(key))
	{
		PrintDeleteFailMessage();
	}
}

Node *Dictionary::SearchPairByKey(string key)
{
	return AssociativeArray.Search(key);
}