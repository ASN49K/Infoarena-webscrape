
#include <iostream>
#include <fstream>
#define maxim(a,b) ((a>b) ? a:b )
#define NMax 1024
using namespace std;

int A[NMax], B[NMax], MAT[NMax][NMax], OUT[NMax], best;
int main()
{
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	int M,N;
	in >> M >> N;
	for (int i = 1; i <= M; i++)
		in >> A[i];
	for (int i = 1; i <= N; i++)
		in >> B[i];

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (A[i] == B[j])
			
				MAT[i][j] = 1 + MAT[i - 1][j - 1];
			else
				MAT[i][j] = maxim(MAT[i][j - 1], MAT[i - 1][j]);
		}
	}

	for (int i = M, j = N; i; )
	{
		if (A[i] == B[j])
		{
			
			OUT[best] = A[i];
			i--;
			j--;
			best++;

		}
		else if (MAT[i - 1][j] < MAT[i][j - 1])
			j--;
		else
			i--;
	}
	
	
	out << best << endl;
	for (int i = best-1; i > -1; i--)
		out << OUT[i] << " ";
	int n;
	cin >> n;
	return 0;
}