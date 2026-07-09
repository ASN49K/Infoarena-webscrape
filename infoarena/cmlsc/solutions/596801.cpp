#include <fstream>

using namespace std;
 
int main(void){
	int i, j, m, n, *A, *B, C[1024][1024], kozos[1024], kozos_hossz;
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
				C[i][j] = 1 + C[i-1][j-1];
			else
				C[i][j] = max(C[i-1][j], C[i][j-1]);
 
	for (i = m, j = n; i; )
		if (A[i] == B[j]){
			kozos[++kozos_hossz] = A[i];
			i--;
			j--;
		}
		else if (C[i-1][j] < C[i][j-1])
				j--;
			else
				i--;
 
	g << kozos_hossz << '\n';
	for (i = kozos_hossz; i; --i)
		g << kozos[i] << " ";
	delete[] A;
	delete[] B;
}