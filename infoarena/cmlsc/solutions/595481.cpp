#include <fstream>

using namespace std;


#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define hossz 1024
 
int m, n, A[hossz], B[hossz], D[hossz][hossz], sir[hossz], bst;
 
int main(void){
	int i, j;
 
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
 
	f >> m >> n;
	FOR (i, 1, m)
		f >> A[i];
	FOR (i, 1, n)
		f >> B[i];
 
	FOR (i, 1, m)
		FOR (j, 1, n)
			if (A[i] == B[j])
				D[i][j] = 1 + D[i-1][j-1];
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);
 
	for (i = m, j = n; i; )
		if (A[i] == B[j])
			sir[++bst] = A[i], --i, --j;
		else if (D[i-1][j] < D[i][j-1])
				--j;
			else
				--i;
 
	printf("%d\n", bst);
	for (i = bst; i; --i)
		printf("%d ", sir[i]);
}