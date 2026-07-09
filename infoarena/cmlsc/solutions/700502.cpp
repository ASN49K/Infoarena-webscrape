#include<cstdio>
#include<algorithm>
using namespace std;
FILE *fin=fopen("cmlsc.in","r");
FILE *fout=fopen("cmlsc.out","w");
int i,j,n,m,a[1026],b[1026],t[1026][1026],s,v[500],k;
int main()
{
	fscanf(fin,"%d%d",&n,&m);
	for(i=1;i<=n;++i) fscanf(fin,"%d",&a[i]);
	for(i=1;i<=m;++i) fscanf(fin,"%d",&b[i]);
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			if(a[j]==b[i]) t[i][j]=t[i-1][j-1]+1;
					  else t[i][j]=max(t[i-1][j],t[i][j-1]);
	j-=1; i-=1;		
	fprintf(fout,"%d\n",t[m][n]);	
	s=t[m][n];
	while(s)
		if(b[i]==a[j]) {v[k]=a[j]; k++; i-=1; j-=1; s-=1;}
				  else	if(t[i][j-1]==t[i][j]) j-=1;
										  else i-=1;
	for(i=k-1;i>=0;--i)
		fprintf(fout,"%d ",v[i]);
	return 0;
}
