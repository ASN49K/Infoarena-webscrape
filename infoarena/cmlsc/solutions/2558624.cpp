#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	int size1, size2, size;
	int* v1;
	int* v2;
	
	f >> size1;
	f >> size2;
	if (1 > size1 && size2 > 1024)
	{
		return 0;
	}

	v1 = new int[size1];
	v2 = new int[size2];

	for (int i = 0; i < size1; i++)
	{
		f >> v1[i];
		if (v1[i] > 256)
		{
			return 0;
		}
	}

	for (int i = 0; i < size2; i++)
	{
		f >> v2[i];
		if (v2[i] > 256)
		{
			return 0;
		}
	}

	size = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (v1[i] == v2[j])
			{
				size++;
			}
		}
	}

	g << size <<"\n";

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (v1[i] == v2[j])
			{
				g << v1[i] <<" ";
			}
		}
	}
	
	delete[] v1;
	delete[] v2;
	return 0;
}