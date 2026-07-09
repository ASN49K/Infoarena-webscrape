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
	
	for (i=m;i>=1;i--)
		for (j=n;j>=1;j--)
		{
			if (S[i]==T[j])
			{
				L[i][j]=L[i+1][j+1]+1;
				continue;
			}
			L[i][j]=L[i+1][j];
			if (L[i][j+1]>L[i][j])
				L[i][j]=L[i][j+1];
		}
	g<<L[1][1]<<endl;
	i=j=1;
	while (i<=m && j<=n)
	{
		if (S[i]==T[j])
		{
			g<<S[i]<<" ";
			i++;
			j++;
		}
		else
			if (L[i][j+1]>L[i+1][j])
			j++;
			else i++;
	}
	f.close();
	f.close();
	return 0;
}
