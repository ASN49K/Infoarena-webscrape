#include <fstream>

using namespace std;

#define hossz 1024
 
int D[hossz][hossz], sir[hossz], bst;

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
	ofstream g("cmlsc.out");
	g << bst << '\n';
	for (i = bst; i; --i)
		g << sir[i] << " ";
}