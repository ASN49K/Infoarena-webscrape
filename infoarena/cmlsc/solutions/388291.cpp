#include<fstream>

using namespace std;

int x[1024], y[1024], n, m;
int lcs[1024][1024], maxim;

fstream f("cmlsc.in", ios::in);
fstream g("cmlsc.out", ios::out);

void rezolvare()
{
	for(int k=1;k<=n;k++)
   		for(int h=1;h<=m;h++)
			if(x[k] == y[h])
			{
				lcs[k][h] = 1 + lcs[k - 1][h - 1];
				maxim++;
			}
			else if(lcs[k - 1][h] > lcs[k][h - 1]) 
				lcs[k][h] = lcs[k-1][h];
			else
				lcs[k][h] = lcs[k][h-1];
}

void afiseaza(int k, int h)
{
	if(lcs[k][h] && x[k] == y[h])
    {
		afiseaza(k-1, h-1);
    	g << x[k] << ' ';
	}
	else if (lcs[k][h] == lcs[k-1][h])
         afiseaza(k-1, h);
	else if (lcs[k][h] == lcs[k][h-1])
         afiseaza(k, h-1);
}

int main()
{
	f >> n >> m; int i;

	for(i = 1; i <= n; i++)	f >> x[i];
	for(i = 1; i <= m; i++)	f >> y[i];

	rezolvare();
	g << maxim << endl;
	afiseaza(n, m);

	return 0;
}