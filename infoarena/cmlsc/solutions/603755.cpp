#include <fstream.h>
#define NM 1025
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[NM],b[NM],d[NM][NM],n,m,cmlsc[NM];

int main(){
	int i,j,k;
	
	fin>>m>>n;
	for ( i = 1; i <= m; i++)
		fin >> a[i];
	
	for ( i = 1; i <= n; i++)
		fin >> b[i];
	
	for ( i = 1; i <= m; i++)
		for ( j = 1; j <= n; j++)
			if ( a[i] == b[j]) d[j][i] = d[j - 1][i - 1] + 1;
			else 
				if (d[j][i-1] != 0) 
					d[j][i] = d[j][i - 1];
				else
					d[j][i] = d[j - 1][i];
			
	i=m; j= n; k =0;
	
	while(j && i)
		if (a[i] == b[j])
			cmlsc[++k] = a[i], i--, j--;
		else if (d[j-1][i] < d[j][i-1])
				i--;
			else
				j--;
			
	fout<<k<<"\n";

	for (i=k;i>0;i--)
		fout<<cmlsc[i]<<" ";
	

	return 0;
}