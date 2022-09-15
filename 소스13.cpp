#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& data)
{
	for (int i = 0; i < data.size() - 1; i++)
	{
		for (int j = 0; j < data.size() - 1 - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]);
			}
		}
	}
}

int main()
{
	vector<int> vec;

	for (int i = 10; i > 0; i--)
	{
		vec.push_back(i);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ", ";
	}
	cout << endl << endl;

	bubble_sort(vec);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ", ";
	}
	cout << endl;

	return 0;
}
