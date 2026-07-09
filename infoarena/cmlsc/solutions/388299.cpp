#include<fstream>

using namespace std;

int x[1024], y[1024], n, m;
int lcs[1024][1024], maxim;

void rezolvare()
{
	for(int k=1;k<=n;k++)
   		for(int h=1;h<=m;h++)
			if(x[k] == y[h])
				lcs[k][h] = 1 + lcs[k - 1][h - 1];
			else if(lcs[k - 1][h] > lcs[k][h - 1]) 
				lcs[k][h] = lcs[k-1][h];
			else
				lcs[k][h] = lcs[k][h-1];

	printf ("%d\n", lcs[n][m]);
}

void afiseaza(int k, int h)
{
	if(lcs[k][h] && x[k] == y[h])
    {
		afiseaza(k-1, h-1);
    	printf ("%d ", x[k]);
	}
	else if (lcs[k][h] == lcs[k-1][h])
         afiseaza(k-1, h);
	else if (lcs[k][h] == lcs[k][h-1])
         afiseaza(k, h-1);
}

int main()
{
	freopen ("cmlsc.in","r",stdin);
	freopen ("cmlsc.out","w",stdout);

	scanf ("%d%d", &n, &m);
	int i;

	for(i = 1; i <= n; i++)	scanf ("%d", &x[i]);
	for(i = 1; i <= m; i++)	scanf ("%d", &y[i]);

	rezolvare();
	afiseaza(n, m);

	return 0;
}
