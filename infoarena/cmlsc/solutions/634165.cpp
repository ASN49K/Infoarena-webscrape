#include<fstream>
#define Nmax 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int x[Nmax],y[Nmax],a[Nmax][Nmax];
int sol[Nmax],k;
int n,m;

void ReadData()
{
	int i;
	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>x[i];
	for(i=1;i<=m;i++)
		fin>>y[i];
}
void cmlsc()
{
	int i,j;
	for( i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(x[i]==y[j])
				a[i][j] = 1 + a[i-1][j-1];
			else
				a[i][j] = max ( a[i][j-1],a[i-1][j]);
}

void Sol()
{
	int i=n,j=m;
	while(i>=1 && j>=1)
	{
		if(x[i] == y[j] ) 
		{
			sol[k++] = x[i];
			i--;
			j--;
		}
		else
			if( a[i][j-1] > a[i-1][j] )
				j--;
			else
				i--;
	}
	for( i = k-1; i>=0;i--)
		fout<<sol[i]<<" ";
	fout<<"\n";
}

int main()
{
	ReadData();
	cmlsc();
	fout<<a[n][m]<<"\n";
	Sol();
	fin.close();
	fout.close();
	return 0;
}