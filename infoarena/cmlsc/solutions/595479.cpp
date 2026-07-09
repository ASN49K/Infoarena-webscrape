#include <fstream>

using namespace std;

#define hossz 1024
 
int m, n, x[hossz], y[hossz], D[hossz][hossz], sir[hossz], bst;
 
int main(void){
	int i, j;
 
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
 
	f >> m >> n;
	for (i = 1; i <= m; i++)
		f >> x[i];
	for (i = 1; i <= n; i++)
		f >> y[i];
 
	for (i = 1; i <= m; i++)
		for(j = 1; j <= m; j++)
			if (x[i] == y[j])
				D[i][j] = 1 + D[i-1][j-1];
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);
 
	for (i = m, j = n; i; )
		if (x[i] == y[j])
			sir[++bst] = x[i], --i, --j;
		else if (D[i-1][j] < D[i][j-1])
				--j;
			else
				--i;
 
	g << bst << '\n';
	for (i = bst; i; --i)
		g << sir[i] << " ";
}