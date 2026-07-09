#include <fstream.h>
#define NM 1025
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[NM],b[NM],d[NM][NM],n,m,cmlsc[NM];

int main(){
	int i,j,k;
	
	fin>>n>>m;
	for (i=1;i<=n;i++)
		fin>>a[i];
	
	for (i=1;i<=m;i++)
		fin>>b[i];
	
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (a[i] == a[j]) d[i][j] = d[i-1][j-1] + 1;
			else if (d[i][j-1] > d[i-1][j])
					d[i][j] = d[i][j-1];
				 else
					d[i][j] = d[i-1][j];
	
	i=n; j= m; k =0;
	
	while(j)
		if (a[i] == b[j])
			cmlsc[++k] = b[j], i--, j--;
		else if (d[i][j-1] < d[i-1][j])
				i--;
			else
				j--;
			
	fout<<k<<"\n";

	for (i=k;i>0;i--)
		fout<<cmlsc[i]<<" ";
		
	
	
	return 0;
}