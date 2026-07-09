#include<stdio.h>
#define maxim(a,b) ((a>b)?a:b)
#define FOR(i,a,b) for(i=a;i<=b;i++)
int v[1024],u[1024],d[1024][1024],sir[1024],b;
int main()
	{
	FILE*f,*g;
	f=fopen("cmlsc.in","r");
	g=fopen("cmlsc.out","w");
	int m,n,i,j;
	fscanf(f,"%d %d",&m,&n);
	FOR(i,1,m) fscanf(f,"&d",&v[i]);
	FOR(i,1,n) fscanf(f,"%d",&u[i]);
	FOR(i,1,m)
		FOR(j,1,n)
			if(v[i]==v[j])
				d[i][j]=	1+d[i-1][j-1];
			else d[i][j]=maxim(d[i-1][j],d[i][j-1]);
		for(i=m,j=n;i;)
			if(v[i]==v[j])
				sir[++b]=v[i],i--,j--;
			else{ if(d[i-1][j]<d[i][j-1])
				j--;
				else i--;}
	fprintf(g,"%d\n",b);
	for(i=b;i>=1;--i)
		fprintf(g,"%d ",sir[i]);
	fcloseall();
	return 0;
	}


