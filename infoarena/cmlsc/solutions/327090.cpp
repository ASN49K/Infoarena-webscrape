/* 
	Author's name: Alin Tomescu 
	Website: http://alinush.isgreat.org 
	Date: 3:22 AM Saturday, June 27, 2009
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef unsigned long ulong;
typedef unsigned int uint;

const uint maxSize = 1024;

//	Everything is initialized to 0 here...
uint lcsMatrix[maxSize+1][maxSize+1];
uint aSequence[maxSize+1], bSequence[maxSize+1];
uint aSize, bSize;
uint lcsSequence[maxSize+1];
uint lcsSize;

int main()
{
	const char * inFile = "cmlsc.in";
	const char * outFile = "cmlsc.out";
	
	ifstream fin(inFile);
	ofstream fout(outFile);	
	
	//	Read the data in...
	
	fin >> aSize >> bSize;
	
	for(int i = 0; i < aSize; ++i)
		fin >> aSequence[i+1];
		
	for(int i = 0; i < bSize; ++i)
		fin >> bSequence[i+1];
		
	//	Generate the LCS matrix using the LCS recurrency
	
	for(int i = 1; i <= aSize; ++i)
	{
		for(int j = 1; j <= bSize; ++j)
		{
			if(aSequence[i] == bSequence[j])
				lcsMatrix[i][j] = 1 + lcsMatrix[i-1][j-1];
			else
				lcsMatrix[i][j] = max(lcsMatrix[i-1][j], lcsMatrix[i][j-1]);
		}
	}
	
	//	Traceback through the LCS matrix in order to generate one of the longest common subsequences

	lcsSize = lcsMatrix[aSize][bSize];
	int i = aSize, j = bSize, k = lcsSize - 1;
	while(i != 0 && j != 0)	//	Or k != -1
	{
		if(aSequence[i] == bSequence[j])
		{
			lcsSequence[k--] = aSequence[i];
			i--; j--;
		}
		else
		{
			if(lcsMatrix[i-1][j] < lcsMatrix[i][j-1])
				j--;
			else
				i--;
		}
	}
	
	//	Output the longest common subsequence to the file
	
	fout << lcsSize << "\n";	
	for(int i = 0; i < lcsSize; i++)
		fout << lcsSequence[i] << " ";
	
	fin.close();
	fout.close();

	return 0;
}