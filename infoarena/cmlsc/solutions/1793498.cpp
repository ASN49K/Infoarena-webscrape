#include <stdio.h>

struct Mask
{
	int value = 0;
	int prev = -1;
};

FILE* fin;
FILE* fout;

int m, n;

int* vec1;
int* vec2;

int maxL;
int minL;

int* longVec;
int* shortVec;

int resLength;
int* resultVec;

Mask* mask;

void LoadFiles()
{
	fin = fopen("cmlsc.in", "r");
	fout = fopen("cmlsc.out", "w");
}

void Init()
{
	LoadFiles();
}

void AllocMemory()
{
	vec1 = new int[m];
	vec2 = new int[n];
}

void Read()
{
	fscanf(fin, "%d %d", &m, &n);

	AllocMemory();

	for (int i = 0;i < m;i++)
	{
		fscanf(fin, "%d", &vec1[i]);
	}

	for (int i = 0;i < n;i++)
	{
		fscanf(fin, "%d", &vec2[i]);
	}
}

void TransposeValues()
{
	if (m > n)
	{
		maxL = m;
		minL = n;

		longVec = vec1;
		shortVec = vec2;
	}
	else
	{
		maxL = n;
		minL = m;

		longVec = vec2;
		shortVec = vec1;
	}

	mask = new Mask[minL];
}

int FindValue(int val)
{
	int res = -1;
	
	for (int i = 0;i < minL;i++)
	{
		if (shortVec[i] == val)
		{
			res = shortVec[i];
			return i;
		}
	}

	return res;
}

void CompleteUntil(int index)
{
	int val = 1;
	int index2 = -1;

	for (int i = 0;i < index;i++)
	{
		if (mask[i].value >= val)
		{
			val = mask[i].value + 1;
			index2 = i;
		}
	}

	mask[index].value = val;
	mask[index].prev = index2;
}

void Parcurg()
{
	int val;

	for (int i = 0;i < maxL;i++)
	{
		val = FindValue(longVec[i]);

		if (val != -1)
		{
			CompleteUntil(val);
		}
	}
}

void ProcessResults()
{
	int max = 0;
	int crt;
	int index = 0;

	for (int i = 0;i < minL;i++)
	{
		if (mask[i].value > mask[max].value)
		{
			max = i;
		}
	}

	resultVec = new int[mask[max].value];

	crt = max;

	while (crt != -1)
	{
		resultVec[index++] = shortVec[crt];
		crt = mask[crt].prev;
	}

	resLength = mask[max].value;
}

void Solve()
{
	TransposeValues();
	Parcurg();
	ProcessResults();
}

void Write1()
{
	fprintf(fout, "%d\n", resLength);
}

void Write2()
{
	for (int i = resLength - 1;i >= 0;i--)
	{
		fprintf(fout, "%d ", resultVec[i]);
	}
}

void Write()
{
	Write1();
	Write2();
}

void CloseFiles()
{
	fclose(fin);
	fclose(fout);
}

void FreeResources()
{
	delete[] longVec;
	delete[] shortVec;

	delete[] mask;

	delete[] resultVec;
}

void Terminate()
{
	CloseFiles();
	FreeResources();
}

int main(void)
{
	Init();
	Read();
	Solve();
	Write();
	Terminate();

	return 0;
}