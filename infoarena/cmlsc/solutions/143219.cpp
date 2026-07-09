#include<stdio.h>
long int n,m,i,j,a[1030],b[1030],cmlsc[1030][1030],c[1030],sol,max;
int main()
{
	FILE *f,*g;f=fopen("cmlsc.in","r");g=fopen("cmlsc.out","w");
	fscanf(f,"%ld%ld",&n,&m);
	for(i=1;i<=n;i++)fscanf(f,"%ld",&a[i]);
	for(j=1;j<=m;j++)fscanf(f,"%ld",&b[j]);
	for(i=1;i<=n;i++)
	 for(j=1;j<=m;j++)
	  { if(a[i]==b[j]) cmlsc[i][j]=cmlsc[i-1][j-1]+1;
	    else cmlsc[i][j]=(cmlsc[i-1][j]>cmlsc[i][j-1])?cmlsc[i-1][j]:cmlsc[i][j-1];
	  }
	sol=cmlsc[n][m];max=sol;
	fprintf(g,"%ld\n",sol);
	if(!sol){fcloseall();return 0;}
	i=n;j=m;
	while(max)
	{ if(cmlsc[i-1][j]==max){i--;continue;}
	  if(cmlsc[i][j-1]==max){j--;continue;}
	  c[max]=a[i];i--;j--;max--;
	}
	for(i=1;i<=sol;i++) fprintf(g,"%ld ",c[i]);
	fcloseall();
	return 0;
}

