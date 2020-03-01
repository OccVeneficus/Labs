#include "IntegerReading.h"

using namespace std;

bool CheckForInteger(string value)
{
	int size = value.length();
	if (isdigit((unsigned char)value[0]) || (unsigned char)value[0] == '-')
	{
		for (int i = 1; i < size; i++)
		{
			if (!isdigit((unsigned char)value[i]))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

int ReadValue()
{
	string inputValue;
	int outputValue;
	while (true)
	{
		getline(cin, inputValue);
		bool intCheckFlag = CheckForInteger(inputValue);
		istringstream inputStringStream(inputValue);
		int number;
		inputStringStream >> number;
		if (intCheckFlag == false || inputStringStream.fail())
		{
			cout << endl << "Wrong input, try again.You can use only integer:";
			inputValue.clear();
		}
		else
		{
			outputValue = stoi(inputValue);
			return outputValue;
		}
	}
}