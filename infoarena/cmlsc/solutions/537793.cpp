#include <fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m, A[101], B[101], M[101][101],maximus=0,vmax[100];

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int main()
{
	int i,j;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>A[i];
	for(i=1;i<=m;i++)
		f>>B[i];
	for(i=1;i<=n+1;i++)
		for(j=1;j<=m+1;j++)
			M[i][j]=0;
	M[n][m]=1;
	for(i=n;i>=1;i--)
		for(j=m;j>=1;j--)
			if(A[i] == B[j])
			{				
				M[i][j] = max(M[i+1][j],M[i][j+1]) + 1;
				if(vmax[maximus]!=A[i])
				{
					maximus++;
					vmax[maximus]=A[i];				
				}
			}
			else
				M[i][j] = max(M[i+1][j],M[i][j+1]);
	g<<maximus<<"\n";
	for(int i = maximus ; i>=1 ; i--)
		g<<vmax[i]<<" ";
	f.close();
	g.close();
	return 0;
}