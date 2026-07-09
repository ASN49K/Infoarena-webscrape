#include <fstream>

using namespace std;


#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define hossz 1024
 
int main(void){
	int i, j, m, n, *A, *B, D[hossz][hossz], kozos[hossz], kozos_hossz;;
 
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
 
	f >> m >> n;
	A = new int[m + 1];
	B = new int[n + 1];
	for (i = 1; i <= m; i++)
		f >> A[i];
	for (i = 1; i <= n; i++)
		f >> B[i];
 
	for (i = 1; i <= m; i++)
		for( j = 1; j <= n; j++)
			if (A[i] == B[j])
				D[i][j] = 1 + D[i-1][j-1];
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);
 
	for (i = m, j = n; i; )
		if (A[i] == B[j])
			kozos[++kozos_hossz] = A[i], --i, --j;
		else if (D[i-1][j] < D[i][j-1])
				--j;
			else
				--i;
 
	g << kozos_hossz << endl;
	for (i = kozos_hossz; i; --i)
		g << kozos[i] << " ";
}