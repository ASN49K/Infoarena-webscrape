#include<fstream>
using namespace std;
int c[1030][1030],m,n,a[1030],b[1030];
char sol[1030][1030];
ofstream fout("cmlsc.out");
void solutie(int i, int j)
{
	if(i!=0 &&j!=0)
	{
	if(sol[i][j]==' ')
	{
		solutie(i-1,j-1);
		fout<<a[i]<<' ';
		
	}
	else if(sol[i][j]=='s')
		solutie(i-1,j);
	else 
		solutie(i,j-1);
	}
}
int main()
{
	ifstream fin("cmlsc.in");
	fin>>m>>n;
	int i,j;
	for(i=1;i<=m;i++)
		fin>>a[i];
	for(i=1;i<=n;i++)
		fin>>b[i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				sol[i][j]=' ';
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				sol[i][j]='s';
			}
			else
			{
				c[i][j]=c[i][j-1];
				sol[i][j]='t';
			}
	fout<<c[m][n]<<"\n";
	solutie(m,n);
	fout<<"\n";
	return 0;
}
				