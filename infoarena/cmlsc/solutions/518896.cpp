#include <fstream>
#include <iostream>
using namespace std;
int m,n,i,j,z,cont,k;
int T[1024],S[1024],RET[1024],L[1024][1024];

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	
	f>>m>>n;
	for (i=1;i<=m;i++)
		f>>S[i];
	for (i=1;i<=n;i++)
		f>>T[i];
	z=0;
	cont=0;
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
			if (S[i]==T[j])
			{
				if (i==1 || j==1)
					L[i][j]=1;
				else L[i][j]=L[i-1][j-1]+1;
				if (L[i][j]>z)
				{
					z=L[i][j];
					cont=0;
				}
				if (L[i][j]==z)
					for (k=i-z+1;k<=i;k++)
					{
						cont++;
						RET[cont]=S[k];
					}
			}
	g<<cont<<endl;
	for (i=1;i<=cont;i++)
		g<<RET[i]<<" ";
	return 0;
}
