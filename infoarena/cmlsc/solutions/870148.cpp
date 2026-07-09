#include<fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int nr,i,j,k,n,m,a[1025],b[1025],D[1025][1025],sol[1025];

int main()
{
	in>>n>>m;
	
	for (i=1;i<=n;i++) in>>a[i];
	for (i=1;i<=m;i++) in>>b[i];
	
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (a[i]==b[j]) D[i][j]=D[i-1][j-1]+1;
				else D[i][j]=max(D[i][j-1],D[i-1][j]);
			
	i=n;
	j=m;
	nr=D[n][m];
	
	out<<nr<<'\n';
	
	while (nr!=0)
	{
		if (a[i]==b[j])
		{
			sol[++k]=a[i];
			i--;
			j--;
			nr--;
		}
		
		else if (D[i][j-1]==D[i][j])
			j--;
		else i--;
	}
	
	for (i=k;i>=1;i--)
		out<<sol[i]<<' ';
}
