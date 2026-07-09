#include<fstream>
#define nmax 1025

using namespace std;

ifstream f("cmlsc.in");ofstream g("cmlsc.out");

int n,m,a[nmax],b[nmax],mat[nmax][nmax],sol[nmax];

int maxim(int x, int y)
{
	if(x>=y) return x;
	return y;
}

void recurrence()
{
	int k=0,l;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(a[i]==b[j])
			{
				mat[i][j]=mat[i-1][j-1]+1;
			}
			else
			{
				mat[i][j]=maxim(mat[i-1][j], mat[i][j-1]);
			}
		}
	}
	int i=n;
	int j=m;
	while(i && j)
	{
		if(a[i]==b[j])
		{
			sol[++k]=a[i];
			i--;
			j--;
		}
		else if(mat[i][j-1]>mat[i-1][j]) j--;
		else i--;
	}
	g<<k<<"\n";
	for(i=k; i>=1; i--) g<<sol[i]<<" ";
}

void read_it()
{
	f>>n>>m;
	for(int i=1; i<=n; i++)
	{
		f>>a[i];
	}
	for(int i=1; i<=m; i++)
	{
		f>>b[i];
	}
}

int main()
{
	read_it();
	recurrence();
	f.close();g.close();
	return 0;
}
