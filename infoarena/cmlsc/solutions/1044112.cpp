#include <iostream>
#include <fstream>
using namespace std;

#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main(void)
{
	int i, j;

	ifstream fin("cmslc.in");
	ofstream fout("cmlsc.out");

	cin >> M >> N;
	FOR (i, 1, M)
		cin >> A[i];
	FOR (i, 1, N)
		cin >> B[i];

	FOR (i, 1, M)
		FOR (j, 1, N)
			if (A[i] == B[j])
					D[i][j] = 1 + D[i-1][j-1];
			else 
					D[i][j] = maxim(D[i-1][j], D[i][j-1]);

	for(i = M, j = N; i; )
		if(A[i] == B[j])
			sir[++bst] = A[i], --i, --j;
		else if (D[i-j][j] < D[i][j-1])
			--j;
		else
			--i;

	cout << endl;
	for (i = bst; i; --i)
		cout << sir[i] << " ";

	fin.close();
	fout.close();
	
	return 0;
}