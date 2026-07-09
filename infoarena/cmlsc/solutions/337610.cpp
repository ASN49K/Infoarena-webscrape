#include <stdio.h>
int max(long x,long y){
	if(x>y) return x;
	else return y;
}
long d[1025][1025];
long i,j,a[1025],b[1025];
int main(){
	FILE *f,*g;
	f=fopen("cmlsc.in","r");
	g=fopen("cmlsc.out","w");
	long n,m;
	fscanf(f,"%ld%ld",&m,&n);
	for(i=1;i<=m;i++)fscanf(f,"%ld",&a[i]);
	for(i=1;i<=n;i++)fscanf(f,"%ld",&b[i]);
	for(i=0;i<=m;i++)
		for(j=0;j<=n;j++)
			d[i][j]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
			else d[i][j]=max(d[i-1][j],d[i][j-1]);
	fprintf(g,"%ld\n",d[m][n]);
	long x=m,y=n,k=0,w[1025];
	while(d[x][y]!=0&&x>0&&y>0){
		w[++k]=a[x];
		x--;
		y--;
		while(d[x][y]==d[x-1][y])x--;
		while(d[x][y]==d[x][y-1])y--;
	}
	for(i=k;i>0;i--)
		fprintf(g,"%ld ",w[i]);
	fprintf(g,"\n");
	fclose(f);
	fclose(g);
	return 0;
}
