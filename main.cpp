#include <iostream>

using namespace std;

class DynamicStringArray
{
public:
	DynamicStringArray();
	DynamicStringArray(const DynamicStringArray& Array);
	~DynamicStringArray();
	int get_size(void);
	void addEntry(string Array);
	bool deleteEntry(string word);
	string getEntry(int index);

	DynamicStringArray operator=(const DynamicStringArray& array);
private:
	string* dynamicArray;
	int size;
};

int main(int argc, char* argv[])
{
	DynamicStringArray a;
	int i;
	a.addEntry("Apples");
	a.addEntry("Oranges");
	a.addEntry("Bananas");
	a.addEntry("Pears");
	a.addEntry("Bluberries");
	cout << a.get_size() << endl;

	for (i = 0; i < a.get_size(); i++)
	{
		cout << a.getEntry(i) << endl;
	}

	

	cout << a.get_size() << endl;
	a.deleteEntry("Bananas");
	for (i = 0; i < a.get_size(); i++)
	{
		cout << a.getEntry(i) << endl;
	}


	return 0;
}

DynamicStringArray::DynamicStringArray()
{
	dynamicArray = nullptr;
	size = 0;
}

DynamicStringArray::~DynamicStringArray()
{
	delete[] dynamicArray;
}

int DynamicStringArray::get_size(void)
{
	return size;
}

void DynamicStringArray::addEntry(string word)
{
	string* array = new string[size + 1];
	int i = 0;
	for (i = 0; i < size; i++)
	{
		array[i] = dynamicArray[i];
	}
	array[size] = word;
	size++;
	delete[] dynamicArray;
	dynamicArray = array;

}
bool DynamicStringArray::deleteEntry(string word)
{
	int i, j = 0;
	for (i = 0; i < size; i++)
	{
		if (dynamicArray[i] == word)
		{
			j = i + 1;
			break;
		}
		if (i == size)
		{
			return false;
		}
	}
	string* Array2 = new string[size - 1];
	for (i = 0; i < j - 1; i++)
	{
		Array2[i] = dynamicArray[i];
	}
	for (i = j - 1; i < size - 1; i++)
	{
		Array2[i] = dynamicArray[i + 1];
	}
	delete[] dynamicArray;
	size--;
	dynamicArray = Array2;
	return true;
}
string DynamicStringArray::getEntry(int index)
{
	if (index < 0 || index > size)
	{
		return nullptr;
	}
	return dynamicArray[index];
}

DynamicStringArray DynamicStringArray::operator=(const DynamicStringArray& array)
{
	if (dynamicArray != nullptr)
	{
		delete[] dynamicArray;
	}
	if (array.size > 0)
	{
		size = array.size;
		dynamicArray = new string[size];
		for (int i = 0; i < size; i++)
		{
			dynamicArray[i] = array.dynamicArray[i];
		}
	}
		
	return *this;
}

DynamicStringArray::DynamicStringArray(const DynamicStringArray& Array)
{
	size = Array.size;
	dynamicArray = Array.dynamicArray;
}
