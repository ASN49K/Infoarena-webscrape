#include <fstream.h>
#define NM 1025
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[NM],b[NM],d[NM][NM],n,m,cmlsc[NM];

int main(){
	int i,j,k;
	
	fin>>m>>n;
	for (i=1;i<=m;i++)
		fin>>a[i];
	
	for (i=1;i<=n;i++)
		fin>>b[i];
	
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
			if (a[i] == b[j]) d[i][j] = d[i-1][j-1] + 1;
			else if (d[i][j-1] > d[i-1][j])
					d[i][j] = d[i][j-1];
				 else
					d[i][j] = d[i-1][j];
	
	i=m; j= n; k =0;
	
	while(j && i)
		if (a[i] == b[j])
			cmlsc[++k] = a[i], i--, j--;
		else if (d[i-1][j] < d[i][j-1])
				j--;
			else
				i--;
			
	fout<<k<<"\n";

	for (i=k;i>0;i--)
		fout<<cmlsc[i]<<" ";
		
	
	
	return 0;
}