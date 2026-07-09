#include <iostream>
#include <fstream>

using namespace std;

ifstream input("cmlsc.in");
ofstream output("cmlsc.out");

#define maxim(a, b) ((a > b) ? a : b)
#define MAX 1024

int main()
{
	int n, m, i, j, max = 0;
	int A[MAX], B[MAX], D[MAX][MAX], result[MAX];
	
	input >> n >> m;
	
	for(i = 0; i < n; i++)
	{
		input >> A[i];
	}
	
	for(j = 0; j < n; j++)
	{
		input >> B[j];
	}
	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			if(A[i] == B[j])
			{
				D[i][j] = 1 + D[i-1][j-1];
			}
			else
			{
				D[i][j] = maxim(D[i][j-1], D[i-1][j]);
			}
		}
	}
	
	for(i = n, j = m; i ; )
	{
		if(A[i] == B[i]) 
		{
			result[++max] = A[i];
			i--;
			j--;
		}
		else if(D[i][j-1] > D[i-1][j])
		{
			j--;
		}
		else
		{
			i--;
		}
	}
	
	output << max << "\n";
	for(i = max; i; i--)
	{
		output << result[i];
	}
	
	return 0;
}
