#include<fstream>
#include<algorithm>
#define NMAX 1028

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[NMAX][NMAX], x[NMAX], y[NMAX], z[NMAX], n, m;

void Citeste()
{
    int i, j;
    f>>n>>m;
    for (i=1; i<=n; ++i) f>>x[i];
    for (j=1; j<=m; ++j) f>>y[j];
}

void Solve()
{
    int i, j;
    for (i=1; i<=n; ++i)
	  for (j=1; j<=m; ++j)
		if (x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
		    else a[i][j]=max(a[i-1][j], a[i][j-1]);
}

void Afiseaza()
{
    int i=n, j=m;
    g<<a[i][j]<<"\n";
    while (i>0 && j>0)
    {
	  if (x[i]==y[j]) z[++z[0]]=x[i], --i, --j;
	  else 
		if (a[i-1][j]>a[i][j-1]) --i;
		else --j;
    }
    for (i=z[0]; i>0; --i) g<<z[i]<<" ";
    g<<"\n";
}

int main()
{
    Citeste();
    
    Solve();
    
    Afiseaza();
    
    f.close();
    g.close();
    return 0;
}
