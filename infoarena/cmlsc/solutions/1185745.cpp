#include<fstream>
#define NMAX 1025
using namespace std;

int n,m,i,a[NMAX],b[NMAX],lcs[NMAX][NMAX],sol[NMAX],k;
ofstream g("cmlsc.out");

void afisare()
{
	int j;
	g<<k<<'\n';
	for (j=k-1;j>=0;j--)
		g<<sol[j]<<' ';
}

void doLCS()
{
	int i,j;
	for (i=0;i<=n;i++)
		for (j=0;j<=m;j++)
		{
			if (i==0 || j==0)
				lcs[i][j]=0;
			else
			{
				if (a[i]==b[j])
					lcs[i][j]=lcs[i-1][j-1]+1;
				else
					lcs[i][j]=(lcs[i-1][j]>lcs[i][j-1]?lcs[i-1][j]:lcs[i][j-1]);
			}
		}
}

void backtrack()
{
	int i=n,j=m;
	while (i>0 || j>0)
	{
			if (a[i]==b[j])
			{
				sol[k++]=a[i];
				i--;
				j--;
			}
			else
				if (lcs[i-1][j]<lcs[i][j-1])
					j--;
				else
					i--;
	}
}

int main()
{
	ifstream f("cmlsc.in");
	f>>n>>m;
	for (i=1;i<n+m+1;i++)
		if (i<=n)
			f>>a[i];
		else
			f>>b[i-n];
	
	doLCS();
	backtrack();
	afisare();
	return 0;
}