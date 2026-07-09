#include <fstream>

using namespace std;

#define hossz 1024
 
int  A[hossz][hossz], kozos[hossz], kozos_hossz;

void beolvas(int &m, int &n, int *&x, int *&y){
	ifstream f("cmlsc.in");
	int i;
	f >> m >> n;
	x = new int[m + 1];
	for (i = 1; i <= m; i++)
		f >> x[i];
	y = new int[n +1];
	for (i = 1; i <= n; i++)
		f >> y[i];
}

int main(void){
	int i, j, m, n, *x, *y;
	beolvas(m, n, x, y);
	
	for (i = 1; i <= m; i++)
		for(j = 1; j <= m; j++)
			if (x[i] == y[j])
				A[i][j] = 1 + A[i-1][j-1];
			else
				A[i][j] = max(A[i-1][j], A[i][j-1]);
 
	for (i = m, j = n; i; )
		if (x[i] == y[j]){
			kozos[++kozos_hossz] = x[i];
			i--;
			j--;
		}
		else if (A[i-1][j] < A[i][j-1])
				j--;
			else
				i--;

	ofstream g("cmlsc.out");
	g << kozos_hossz << '\n';
	for (i = kozos_hossz; i; --i)
		g << kozos[i] << " ";
}