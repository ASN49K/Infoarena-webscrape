#include <fstream>
using namespace std;
ifstream intrare("cmls.in");
ofstream iesire("cmls.out");

int LCS[1050][1050], OP[1050][1050], N, M;
int a[1050], b[1050];

void dinamic();

int main()
	{
	int i, j;
	intrare>>N>>M;
	for (i=0;i<N;i++)intrare>>a[i];
	for (i=0;i<M;i++)intrare>>b[i];
	dinamic();
	iesire<<LCS[0][0]<<'\n';
	//restaurare solutie
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			if (OP[i][j]==1)
				iesire<<b[j]<<' ';
	return 0;
	}

void dinamic()
	{
	int i, j;
	for (i=N-1;i>=0;i--)
		for (j=M-1;j>=0;j--)
			if (a[i]==b[j])
				{LCS[i][j]=1+LCS[i+1][j+1];OP[i][j]=1;}
			else
				{
				if (LCS[i+1][j]>LCS[i][j+1])
					{LCS[i][j]=LCS[i+1][j];OP[i][j]=2;}
				else
					{LCS[i][j]=LCS[i][j+1];OP[i][j]=3;}
				}
	}